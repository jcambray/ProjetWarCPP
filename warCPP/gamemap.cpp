#include "gamemap.h"
#include <QPixmap>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QDebug>



gameMap::gameMap()
{
    viewer = new TmxViewer;
    items = new QMap<QString,mapItem *>();
    viewer->viewMap(QString(QLatin1String("map\\mapBis.tmx")));
}


gameMap::gameMap(const gameMap &map)
{
    if(map.viewer != NULL)
    {
        delete viewer;
        viewer = map.viewer;
    }
    if(map.items != NULL)
    {
        delete items;
        items = map.items;
    }
}

mapItem * gameMap::addItem(mapItem * item, int x, int y)
{
   viewer->scene()->addItem(item);
   item->setPos(x,y);
   items->insert(item->getName(),item);
   return item;
}

void gameMap::addAllItems(){

    mapItem *it = new mapItem(QLatin1String("greenMonster"),QLatin1String("race"),QPixmap(QLatin1String("images\\monster.jpg")));
    addItem(it,300,180);
    it->setScale(0.3);
}

QMap<QString,mapItem *> * gameMap::getItems()
{
    return items;
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

gameMap::~gameMap()
{
    delete  viewer;
}


