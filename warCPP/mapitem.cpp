#include "mapitem.h"
#include <QDebug>
#include <QPolygonF>

mapItem::mapItem() : QGraphicsPixmapItem()
{
}

mapItem::mapItem(const QString &_name, const QString &_type, const QPixmap &img,TmxViewer *v) : QGraphicsPixmapItem(img)
{
    name = _name;
    type = _type;
    viewer = v;
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

//gestion de l'evenement click de la souris
void mapItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
   if(event->button() == Qt::LeftButton){
       QGraphicsItem::mousePressEvent(event);
    }
}

Area * mapItem::getAreaOnDrag(QPointF & p)
{
    ObjectGroup * oc = viewer->mMap->layerAt(viewer->mMap->indexOfLayer(tr("Areas")))->asObjectGroup();

     for(int i = 0; i < oc->objects().count();i++)
     {
         MapObject * item = oc->objectAt(i);
         QPolygonF poly = QPolygonF(item->polygon());
         poly.translate(item->position());

         if(poly.containsPoint(p,Qt::FillRule::OddEvenFill))
         {
              return viewer->getAreaByName(item->name());
         }
     }
      return  NULL;
}

//Gestion de l'événement release de la souris
void mapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   if(event->button() == Qt::LeftButton){

       QGraphicsItem::mouseReleaseEvent(event);
       Area * dragDestination = getAreaOnDrag(scenePos());
       if(!dragDestination)
       {
           return;
       }
       qDebug()<<dragDestination->name();
       setPos(scenePos());

    }


}



