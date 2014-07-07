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
    setFlags(ItemIsMovable | ItemIsSelectable | ItemIsFocusable);
}

mapItem::mapItem(const mapItem &m)
{
    name = m.name;
    type = m.type;
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
   setAnciennePos(scenePos());
}

Area * mapItem::getAreaOnDrag(QPointF & p)
{
    ObjectGroup * oc = viewer->mMap->layerAt(viewer->mMap->indexOfLayer(tr("Areas")))->asObjectGroup();

     for(int i = 0; i < oc->objects().count();i++)
     {
         MapObject * item = oc->objectAt(i);
         //QPolygonF poly = QPolygonF(item->polygon());
         //poly.translate(item->position());

         if(sceneCoordinatesPolygon(item->polygon(),item->position()).containsPoint(p,Qt::OddEvenFill))
         {
              return viewer->getAreaByName(item->name());
         }
     }
      return  NULL;
}

//Gestion de l'événement release de la souris
void mapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   if(event->button() != Qt::LeftButton){
   return;
   }

   QGraphicsItem::mouseReleaseEvent(event);
   Area * dragDestination = getAreaOnDrag(scenePos());
   if(!dragDestination)
   {
       setPos(QPointF(anciennePos->x(),anciennePos->y()));
       return;
   }

   //Debug
   dragDestination->setOwnerPlayerName(QLatin1String("me"));

   if(validateMove(dragDestination))
   {
       setPos(scenePos());
   }
   else
   {
       setPos(QPointF(anciennePos->x(),anciennePos->y()));
   }
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

QPolygonF mapItem::sceneCoordinatesPolygon(const QPolygonF & poly, const QPointF & p)
{
    QPolygonF translatedPolygon  = QPolygonF(poly);
    translatedPolygon.translate(p);
    return translatedPolygon;
}


