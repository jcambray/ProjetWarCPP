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
   item->setZValue(1);
   tokens->append(item);
   return item;
}


QList<mapItem *>& gameMap::getTokens()
{
    return *tokens;
}

void gameMap::setMapItemsScale(double coeff)
{
    QList<QGraphicsItem *> items = viewer->items();
    for(int i = 0; i < items.count();i++)
    {
        items[i]->setScale(coeff);
    }
}

void gameMap::initToken(player *p,const QPoint spawnPos, int nbToken)
{
    for(int i = 0;i < nbToken;i++)
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
}


QList<mapItem *> gameMap::getPlayerTokensOnArea(Area *a,player *p)
{
    QPolygonF areaPoly = viewer->sceneCoordinatesPolygon(a->polygon(),a->position());
    QList<mapItem *> findTokens = QList<mapItem *>();
    for(int i = 0; i < tokens->length(); i++)
    {

        if(areaPoly.containsPoint(getTokens()[i]->pos(),Qt::OddEvenFill) && getTokens()[i]->getOwnerPlayer()->getName() == p->getName())
            findTokens.append(getTokens()[i]);
    }

    return findTokens;
}


void gameMap::tryConquere(Area *area)
{
    if(area->getOwnerPlayerName() == partie->getP1()->getName())
        return;
    QList<mapItem * > p1Items = getPlayerTokensOnArea(area,partie->getP1());
    QList<mapItem * > p2Items = getPlayerTokensOnArea(area,partie->getP2());


    if((p1Items.length() > p2Items.length()) || (p1Items.size() == 0 && p2Items.size() == 0))
    {
        area->setOwnerPlayerName(partie->getP1()->getName());
        if(partie->nbTour % 2 == 0)
            viewer->setColorToAreaBorder(QPen(Qt::red,3.0),area);
        else
            viewer->setColorToAreaBorder(QPen(Qt::green,3.0),area);
    }
}

gameMap::~gameMap()
{
    delete viewer;
    delete tokens;
    delete partie;
    delete mapView;
}


