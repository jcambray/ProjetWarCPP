#include "mapitem.h"
#include <QDebug>
#include <QPolygonF>

mapItem::mapItem() : QGraphicsPixmapItem()
{
    viewer = NULL;
    anciennePos = NULL;
    ownerPlayer = NULL;
}

mapItem::mapItem(const QPixmap &img, TmxViewer *v, player *p) : QGraphicsPixmapItem(img)
{
    type = tr("token");
    viewer = v;
    anciennePos = NULL;
    ownerPlayer = p;
    setParent(viewer);
    setFlags(ItemIsMovable | ItemIsSelectable | ItemIsFocusable);
}

mapItem::mapItem(const mapItem &m)
{
    type = m.type;
    if(viewer != NULL)
        delete viewer;
    if(anciennePos != NULL)
        delete anciennePos;
    if(ownerPlayer != NULL)
        delete ownerPlayer;
    viewer = m.viewer;
    anciennePos = m.anciennePos;
    ownerPlayer = m.ownerPlayer;
}


void mapItem::setType(const QString & newType)
{
    type = newType;
}


void mapItem::setAnciennePos(QPointF & p)
{
    if(anciennePos != NULL)
    {
        delete anciennePos;
    }
    anciennePos = new QPointF(p);
}

void mapItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
   if(event->button() != Qt::LeftButton){
       return;
    }
   QPointF point;
   point =scenePos();
   QGraphicsItem::mousePressEvent(event);
   this->setAnciennePos(point);
}



void mapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   if(event->button() != Qt::LeftButton){
   return;
   }

   QGraphicsItem::mouseReleaseEvent(event);
   QPointF point;
   point =scenePos();
   Area * dragDestination = viewer->getAreaByLocation(point);

   if(!dragDestination)
   {
       setPos(QPointF(anciennePos->x(),anciennePos->y()));
       return;
   }

   //Debug
   //qDebug()<<dragDestination->name();
   //dragDestination->setOwnerPlayerName(QLatin1String("me"));

   if(validateMove(dragDestination))
   {
       setPos(scenePos());
   }
   else
   {
       setPos(QPointF(anciennePos->x(),anciennePos->y()));
   }
/*
   viewer->setAreaColor(sceneCoordinatesPolygon(dragDestination->polygon(),dragDestination->position()).toPolygon());
   const QRegion reg(sceneCoordinatesPolygon(dragDestination->polygon(),dragDestination->position()).toPolygon());
   viewer->canRepaint = true;
   viewer->repaint(reg);
   */
}



void mapItem::setOwnerPlayer(const player &p)
{
    if(ownerPlayer != NULL)
        delete ownerPlayer;

    ownerPlayer = new player(p);
}

bool mapItem::validateMove(Area * a)
{
    if(!a)
    {
        return false;
    }


    if(ownerPlayer->getName() != a->getOwnerPlayerName())
    {
        return false;
    }
    return true;
}



QPointF mapItem::getAnciennePos()
{
    return *anciennePos;
}


mapItem::~mapItem()
{
    delete viewer;
    delete anciennePos;
    delete ownerPlayer;
}
