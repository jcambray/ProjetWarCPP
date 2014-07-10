#include "mapitem.h"
#include <QDebug>
#include <QPolygonF>

mapItem::mapItem() : QGraphicsPixmapItem()
{
    viewer = NULL;
    anciennePos = NULL;
}

mapItem::mapItem(const QString &_name, const QString &_type, const QPixmap &img,TmxViewer *v) : QGraphicsPixmapItem(img)
{
    name = _name;
    type = _type;
    viewer = v;
    anciennePos = NULL;
    setParent(viewer);
    setFlags(ItemIsMovable | ItemIsSelectable | ItemIsFocusable);
}

mapItem::mapItem(const mapItem &m)
{
    name = m.name;
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

void mapItem::setName(const QString &_name){
    name = _name;
}

void mapItem::setType(const QString & newType)
{
    type = newType;
}

const QString & mapItem::getName()
{
    return name;
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
   QGraphicsItem::mousePressEvent(event);
   this->setAnciennePos(scenePos());
}




void mapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   if(event->button() != Qt::LeftButton){
   return;
   }

   QGraphicsItem::mouseReleaseEvent(event);

   Area * dragDestination = viewer->getAreaByLocation(scenePos());

   if(!dragDestination)
   {
       setPos(QPointF(anciennePos->x(),anciennePos->y()));
       return;
   }

   //Debug
   //qDebug()<<dragDestination->name();
   dragDestination->setOwnerPlayerName(QLatin1String("me"));

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

    //Debug
    if(QLatin1String("me") != a->getOwnerPlayerName())
    //if(ownerPlayer->getName() != a->getOwnerPlayerName())
    {
        return false;
    }
    return true;
}



QPointF mapItem::getAnciennePos()
{
    return *anciennePos;
}


