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
}

gameMap::gameMap(game *g)
{
    viewer = new TmxViewer;
    partie = g;
    tokens = new QList<mapItem*>();
    viewer->viewMap(tr("map//map.tmx"));
    viewer->populateAreas();
}


gameMap::gameMap(const gameMap &map)
{
    if(viewer != NULL)
        delete viewer;
    if(tokens != NULL)
        delete tokens;
    if(partie != NULL)
        delete partie;

    tokens = map.tokens;
    viewer = map.viewer;
    partie = map.partie;
}

mapItem * gameMap::addItem(mapItem * item, int x, int y)
{
   viewer->scene()->addItem(item);
   item->setPos(x,y);
   tokens->append(item);
   return item;
}

void gameMap::addAllItems(){

    mapItem * amazon = new mapItem(tr("amazone"),tr("token"),QPixmap(tr("tokens\\tokenAmazones.png")),viewer);
    addItem(amazon,490,389);
    amazon->setScale(0.225);
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

gameMap::~gameMap()
{
    delete  viewer;
    delete tokens;
    delete partie;
}


