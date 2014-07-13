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

void gameMap::initToken(player *p,const QPoint spawnPos)
{
    if(p->nat->getName() == tr("Amazones"))
        addItem(new mapItem(QPixmap(tr("images\\token\\tokenAmazones.png")),p,this),spawnPos.x(),spawnPos.y());
    if(p->nat->getName() == tr("Humains"))
          addItem(new mapItem(QPixmap(tr("images\\token\\tokenHumains.png")),p,this),spawnPos.x(),spawnPos.y());
    if(p->nat->getName() == tr("Squelettes"))
        addItem(new mapItem(QPixmap(tr("images\\token\\tokenSquelette.png")),p,this),spawnPos.x(),spawnPos.y());
     if(p->nat->getName() == tr("Hommes-Rats"))
        addItem(new mapItem(QPixmap(tr("images\\token\\tokenHommesRats.png")),p,this),spawnPos.x(),spawnPos.y());

}

gameMap::~gameMap()
{
    delete viewer;
    delete tokens;
    delete partie;
    delete mapView;
}


