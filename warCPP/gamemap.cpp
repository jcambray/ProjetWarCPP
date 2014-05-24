#include "gamemap.h"
#include <QPixmap>
#include <QMessageBox>
#include <QGraphicsItem>
#include <QDebug>


gameMap::gameMap()
{
    viewer = new TmxViewer;
    viewer->viewMap(QString(QLatin1String("mapBis.tmx")));
}


gameMap::gameMap(const gameMap &map)
{
    if(map.viewer != NULL)
    {
        viewer = map.viewer;
    }
}

mapItem * gameMap::addItem(const QString & img, int x, int y)
{
   QPixmap image(img);
   mapItem * item = reinterpret_cast<mapItem *>(viewer->scene()->addPixmap(image));
   item->setPos(x,y);
   return item;
}

void gameMap::addAllItems(){

   mapItem * monsterItem;
   monsterItem = addItem(QLatin1String("monster.jpg"),130,250);
   monsterItem->setScale(0.3);

}

QMap<QString,mapItem> gameMap::getItems()
{
    return items;
}

TmxViewer * gameMap::getViewer()
{
    return viewer;
}

gameMap::~gameMap()
{
    delete  viewer;
}


