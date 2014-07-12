#include "gamemap.h"
#include "game.h"
#include <QPixmap>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QDebug>



gameMap::gameMap()
{
    viewer = NULL;
    partie = NULL;
    tokens = NULL;
    mapView = NULL;
}

gameMap::gameMap(game *g)
{
    viewer = new TmxViewer;
    partie = g;
    tokens = new QList<mapItem*>();
    //viewer->viewMap(tr("map//map.tmx"));
    //viewer->populateAreas();
    mapView = new MapWindow(this);
}


gameMap::gameMap(const gameMap &map)
{
    if(viewer != NULL)
        delete viewer;
    if(tokens != NULL)
        delete tokens;
    if(partie != NULL)
        delete partie;
    if(mapView != NULL)
        delete mapView;

    tokens = map.tokens;
    viewer = map.viewer;
    partie = map.partie;
    mapView = map.mapView;
}

mapItem * gameMap::addItem(mapItem * item, int x, int y)
{
   item->setScale(0.225);
   viewer->scene()->addItem(item);
   item->setPos(x,y);
   tokens->append(item);
   return item;
}

void gameMap::addAllItems(){
/*
    mapItem * amazon = new mapItem(tr("token"),QPixmap(tr("token\\tokenAmazones.png")),viewer);
    addItem(amazon,490,389);
    amazon->setScale(0.225);
    */
}

QList<mapItem *> *gameMap::getTokens()
{
    return tokens;
}

TmxViewer * gameMap::getViewer()
{
    return viewer;
}

void gameMap::setMapItemsScale(double coeff)
{
    QList<QGraphicsItem *> items = viewer->items();
    for(int i = 0; i < items.count();i++)
    {
        items[i]->setScale(coeff);
    }
}

void gameMap::initToken(player &p)
{
    if(p.getNation()->getName() == tr("Amazones"))
        addItem(new mapItem(QPixmap(tr("images\\token\\tokenAmazones.png")),viewer),500,500);
    if(p.getNation()->getName() == tr("Humains"))
          addItem(new mapItem(QPixmap(tr("images\\token\\tokenHumains.png")),viewer),500,500);
    if(p.getNation()->getName() == tr("Squelettes"))
        addItem(new mapItem(QPixmap(tr("images\\token\\tokenSquelette.png")),viewer),500,500);
     if(p.getNation()->getName() == tr("Hommes-rats"))
        addItem(new mapItem(QPixmap(tr("images\\token\\tokenHommesRats.png")),viewer),500,500);

qDebug()<<tr("Hommes-rats");
}

gameMap::~gameMap()
{
    delete viewer;
    delete tokens;
    delete partie;
    delete mapView;
}


