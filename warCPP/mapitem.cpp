#include "mapitem.h"
#include "gamemap.h"
#include "game.h"
#include <QDebug>
#include <QPolygonF>

mapItem::mapItem() : QGraphicsPixmapItem()
{
    gameM = NULL;
    anciennePos = NULL;
    ownerPlayer = NULL;
}

mapItem::mapItem(const QPixmap &img, player *p, gameMap *g) : QGraphicsPixmapItem(img)
{
    type = tr("token");
    gameM = g;
    anciennePos = NULL;
    ownerPlayer = p;
    setParent(gameM->viewer);
    setFlags(ItemIsMovable | ItemIsSelectable | ItemIsFocusable);
}

mapItem::mapItem(const mapItem &m)
{
    type = m.type;
    if(gameM != NULL)
        delete gameM;
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
   Area * dragDestination = gameM->viewer->getAreaByLocation(point);

   if(!dragDestination)
   {
       setPos(QPointF(anciennePos->x(),anciennePos->y()));
       return;
   }

   //Debug
   //dragDestination->setOwnerPlayerName(QLatin1String("me"));

   if(validateMove(dragDestination))
       setPos(scenePos());
   else
       setPos(QPointF(anciennePos->x(),anciennePos->y()));
}



void mapItem::setOwnerPlayer(const player &p)
{
    if(ownerPlayer != NULL)
        delete ownerPlayer;

    ownerPlayer = new player(p);
}

bool mapItem::validateMove(Area * a)
{
    if(!a->isEdgeArea() && gameM->partie->nbTour == 0)
        return false;

    /*
    if(ownerPlayer->getName() != a->getOwnerPlayerName())
    {
        return false;
    }
    */
    return true;
}



QPointF mapItem::getAnciennePos()
{
    return *anciennePos;
}


mapItem::~mapItem()
{
    delete gameM;
    delete anciennePos;
    delete ownerPlayer;
}
