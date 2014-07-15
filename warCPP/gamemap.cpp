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
        addItem(new mapItem(QPixmap(tr(":/fond/images/token/tokenAmazones.png")),p,this),spawnPos.x(),spawnPos.y());
    if(p->nat->getName() == tr("Humains"))
          addItem(new mapItem(QPixmap(tr(":/fond/images/token/tokenHumains.png")),p,this),spawnPos.x(),spawnPos.y());
    if(p->nat->getName() == tr("Squelettes"))
        addItem(new mapItem(QPixmap(tr(":/fond/images/token/tokenSquelette.png")),p,this),spawnPos.x(),spawnPos.y());
     if(p->nat->getName() == tr("Hommes-Rats"))
        addItem(new mapItem(QPixmap(tr(":/fond/images/token/tokenHommesRats.png")),p,this),spawnPos.x(),spawnPos.y());
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

void gameMap::removePlayerTokensArea(Area *a, player *p,int nbIteration)
{
    QPolygonF areaPoly = viewer->sceneCoordinatesPolygon(a->polygon(),a->position());

    for(int j = 0; j < nbIteration; j++)
    {
    for(int i = 0; i < tokens->length(); i++)
    {

        if(areaPoly.containsPoint(getTokens()[i]->pos(),Qt::OddEvenFill) && getTokens()[i]->getOwnerPlayer()->getName() == p->getName())
        {
           viewer->scene()->removeItem(tokens->at(i));
            tokens->removeAt(i);
        }
    }
    }
}


void gameMap::tryConquere(Area *area)
{
    if(area->getOwnerPlayerName() == partie->getP1()->getName())
        return;


    if(area->type() == QLatin1String("aqua") && partie->getP1()->getPower()->getName() != QLatin1String("Pirates"))
        return;

    QList<mapItem * > p1Items = getPlayerTokensOnArea(area,partie->getP1());
    QList<mapItem * > p2Items = getPlayerTokensOnArea(area,partie->getP2());



    if(p1Items.size() < area->getTokensToConquiert())
        return;

    if((p1Items.length() > p2Items.length()) || (p1Items.size() == 0 && p2Items.size() == 0))
    {
        area->setOwnerPlayerName(partie->getP1()->getName());
        if(partie->nbTour % 2 == 0)
            viewer->setColorToAreaBorder(QPen(Qt::red,3.0),area);
        else
            viewer->setColorToAreaBorder(QPen(Qt::green,3.0),area);

        if(p2Items.size() > 0)
        {
        removePlayerTokensArea(area,partie->getP2(),p2Items.size());

        if(partie->nbTour % 2 == 0)
            initToken(partie->getP2(),QPoint(-100,400),1);
        else
            initToken(partie->getP2(),QPoint(-100,200),1);
        }
    }
}

void gameMap::removeAllPlayerTokens(player * p)
{
    for(int i = 0; i < viewer->getAreas().length();i++)
    {
        int nbIteration = getPlayerTokensOnArea(viewer->getAreas()[i],p).length();
        removePlayerTokensArea(viewer->getAreas()[i],p,nbIteration);
    }
}

int gameMap::getAreaScore(Area * area)
{
    int bonusNation = 0;
    int scoreBase = 1;

    if(area->type() == QLatin1String("Chateau"))
        return 3;


    if(partie->getP1()->getNation()->getName() == QLatin1String("Amazones") && area->type() == QLatin1String("arbre"))
        bonusNation = 1;

    if(partie->getP1()->getNation()->getName() == QLatin1String("Humains") && area->type() == QLatin1String("herbe"))
        bonusNation = 1;

    return scoreBase + bonusNation;
}

int gameMap::getPowerScore()
{
    int powerScore = 0;

    if(partie->getP1()->getPower()->getName() == QLatin1String("Marchands"))
    {
        for(int i = 0; i < viewer->getAreas().length(); i++)
        {
            if(viewer->getAreas()[i]->getOwnerPlayerName() == partie->getP1()->getName())
               powerScore++;
        }
    }

    if(partie->getP1()->getPower()->getName() == QLatin1String("Bucherons"))
    {
        for(int i = 0; i < viewer->getAreas().length(); i++)
        {
            if(viewer->getAreas()[i]->getOwnerPlayerName() == partie->getP1()->getName() && viewer->getAreas()[i]->type() == QLatin1String("arbre"))
               powerScore++;
        }
    }

    int squeletteScore = 0;

    if(partie->getP1()->getNation()->getName() == QLatin1String("Squelettes"))
    {
        for(int i = 0; i < viewer->getAreas().length(); i++)
        {
            if(viewer->getAreas()[i]->getOwnerPlayerName() == partie->getP1()->getName())
               squeletteScore++;
        }
         squeletteScore = squeletteScore / 2;
    }

    return powerScore + squeletteScore;
}

int gameMap::getTourScore()
{
    int scoreByAreas = 0;
    for(int i = 0; i < viewer->getAreas().length(); i++)
    {
        if(viewer->getAreas()[i]->getOwnerPlayerName() == partie->getP1()->getName())
            scoreByAreas += getAreaScore(viewer->getAreas()[i]);
    }

    int powerScore = getPowerScore();

    return scoreByAreas + powerScore;
}

gameMap::~gameMap()
{
    delete viewer;
    delete tokens;
    delete partie;
    delete mapView;
}


