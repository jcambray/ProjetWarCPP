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



mapItem * gameMap::addItem(const QString & img, int x, int y)
{
   QPixmap image(img);
   mapItem * item = reinterpret_cast<mapItem *>(viewer->scene()->addPixmap(image));
   //item->setFlag(QGraphicsItem::ItemIsMovable,true);
   item->setPos(x,y);
   return item;
}

void gameMap::addAllItems(){

   mapItem * monsterItem;
   monsterItem = addItem(QLatin1String("monster.jpg"),130,250);
   monsterItem->setScale(0.3);

}

TmxViewer * gameMap::getViewer()
{
    return viewer;
}


