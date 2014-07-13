/*
 * tmxviewer.cpp
 * Copyright 2010, Thorbjørn Lindeijer <thorbjorn@lindeijer.nl>
 *
 * This file is part of the TMX Viewer example.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *    1. Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *    2. Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL THE CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "tmxviewer.h"

#include "isometricrenderer.h"
#include "map.h"
#include "mapobject.h"
#include "mapreader.h"
#include "orthogonalrenderer.h"
#include "tilelayer.h"
#include "tileset.h"
#include <QCoreApplication>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QStyleOptionGraphicsItem>
#include <QMessagebox>
#include <QDebug>


using namespace Tiled;

/**
 * Item that represents a map object.
 */
class MapObjectItem : public QGraphicsItem
{
public:
    MapObjectItem(MapObject *mapObject, MapRenderer *renderer,
                  QGraphicsItem *parent = 0)
        : QGraphicsItem(parent)
        , mMapObject(mapObject)
        , mRenderer(renderer)
    {}

    QRectF boundingRect() const
    {
        return mRenderer->boundingRect(mMapObject);
    }

    void paint(QPainter *p, const QStyleOptionGraphicsItem *, QWidget *)
    {
        const QColor &color = mMapObject->objectGroup()->color();
        mRenderer->drawMapObject(p, mMapObject,
                                 color.isValid() ? color : Qt::darkGray);
    }

private:
    MapObject *mMapObject;
    MapRenderer *mRenderer;
};

/**
 * Item that represents a tile layer.
 */
class TileLayerItem : public QGraphicsItem
{
public:
    TileLayerItem(TileLayer *tileLayer, MapRenderer *renderer,
                  QGraphicsItem *parent = 0)
        : QGraphicsItem(parent)
        , mTileLayer(tileLayer)
        , mRenderer(renderer)
    {
        setFlag(QGraphicsItem::ItemUsesExtendedStyleOption);
    }

    QRectF boundingRect() const
    {
        return mRenderer->boundingRect(mTileLayer->bounds());
    }

    void paint(QPainter *p, const QStyleOptionGraphicsItem *option, QWidget *)
    {
        mRenderer->drawTileLayer(p, mTileLayer, option->rect);
    }

private:
    TileLayer *mTileLayer;
    MapRenderer *mRenderer;
};

/**
 * Item that represents an object group.
 */
class ObjectGroupItem : public QGraphicsItem
{
public:
    ObjectGroupItem(ObjectGroup *objectGroup, MapRenderer *renderer,
                    QGraphicsItem *parent = 0)
        : QGraphicsItem(parent)
    {
        setFlag(QGraphicsItem::ItemHasNoContents);

        // Create a child item for each object
        foreach (MapObject *object, objectGroup->objects())
            new MapObjectItem(object, renderer, this);
    }

    QRectF boundingRect() const { return QRectF(); }
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) {}
};

/**
 * Item that represents a map.
 */
class MapItem : public QGraphicsItem
{
public:
    MapItem(Map *map, MapRenderer *renderer, QGraphicsItem *parent = 0)
        : QGraphicsItem(parent)
    {
        setFlag(QGraphicsItem::ItemHasNoContents);

        // Create a child item for each layer
        foreach (Layer *layer, map->layers()) {
            if (TileLayer *tileLayer = layer->asTileLayer()) {
                new TileLayerItem(tileLayer, renderer, this);
            } else if (ObjectGroup *objectGroup = layer->asObjectGroup()) {
                new ObjectGroupItem(objectGroup, renderer, this);
            }
        }
    }

    QRectF boundingRect() const { return QRectF(); }
    void paint(QPainter *, const QStyleOptionGraphicsItem *, QWidget *) {}
};


TmxViewer::TmxViewer(QWidget *parent) :
    QGraphicsView(parent),
    mScene(new QGraphicsScene(this)),
    mMap(0),
    mRenderer(0)
{
    setWindowTitle(tr("WAR C++"));
    setScene(mScene);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setDragMode(QGraphicsView::ScrollHandDrag);
    setOptimizationFlags(QGraphicsView::DontAdjustForAntialiasing
                         | QGraphicsView::DontSavePainterState);
    setBackgroundBrush(Qt::black);
    setFrameStyle(QFrame::NoFrame);
    viewport()->setAttribute(Qt::WA_StaticContents);

    setMouseTracking(true);
    setGeometry(500,500,1136,689);
    areas = new QList<Area *>();
}


TmxViewer::~TmxViewer()
{
    qDeleteAll(mMap->tilesets());
    delete mMap;
    delete mRenderer;
    delete areas;
}

QList<Area *> &TmxViewer::getAreas()
{
    return *areas;
}


void TmxViewer::populateAreas()
{
    int index = mMap->indexOfLayer(QLatin1String("Areas"));
   ObjectGroup *AreaLayer = mMap->layerAt(index)->asObjectGroup();
   for(int i =0;i < AreaLayer->objectCount();i++)
   {
       MapObject  mapObj = *AreaLayer->objects()[i];
       Area * obj = new Area(mapObj.name(),mapObj.type(),mapObj.position(),mapObj.size(),mapObj.polygon(),mapObj.properties());
       areas->insert(i,obj);
   }
}

Area * TmxViewer::getAreaByName(const QString & name)
{
    ObjectGroup * areasObjectGroup = mMap->layerAt(mMap->indexOfLayer(tr("Areas")))->asObjectGroup();
    for(int i = 0; i < getAreas().count();i++)
    {
        if(getAreas().at(i)->name() == name)
            return getAreas()[i];
    }

    return NULL;
}


Area * TmxViewer::getAreaByLocation(QPointF & p)
{
    ObjectGroup * oc = mMap->layerAt(mMap->indexOfLayer(tr("Areas")))->asObjectGroup();

     for(int i = 0; i < oc->objects().count();i++)
     {
         MapObject * item = oc->objectAt(i);
         if(sceneCoordinatesPolygon(item->polygon(),item->position()).containsPoint(p,Qt::OddEvenFill))
         {
              return getAreaByName(item->name());
         }
     }
      return  NULL;
}


QPolygonF TmxViewer::sceneCoordinatesPolygon(const QPolygonF & poly, const QPointF & p)
{
    QPolygonF translatedPolygon  = QPolygonF(poly);
    translatedPolygon.translate(p);
    return translatedPolygon;
}


void TmxViewer::mouseMoveEvent(QMouseEvent *event)
{
    QGraphicsView::mouseMoveEvent(event);

    QPointF p = mapToScene((event->pos()));
    Area * hoveredArea = getAreaByLocation(p);
}


void TmxViewer::setColorToAreaBorder(QPen pen, Area *area)
{
    QPolygonF polygon = sceneCoordinatesPolygon(getAreaByName(area->name())->polygon(),area->position());
    mScene->addPolygon(polygon,pen);
}

void TmxViewer::viewMap(const QString &fileName)
{
    delete mRenderer;
    mRenderer = 0;

    mScene->clear();
    centerOn(0, 0);

    MapReader reader;
    mMap = reader.readMap(fileName);
    if (!mMap)
    {
        QMessageBox::warning(this,tr("ERROR"),reader.errorString());
        return; // TODO: Add error handling
    }

    switch (mMap->orientation()) {
    case Map::Isometric:
        mRenderer = new IsometricRenderer(mMap);
        break;
    case Map::Orthogonal:
    default:
        mRenderer = new OrthogonalRenderer(mMap);
        break;
    }

    mScene->addItem(new MapItem(mMap, mRenderer));
}
