#include "mapitem.h"
#include <QDebug>

mapItem::mapItem() : QGraphicsPixmapItem()
{
}

mapItem::mapItem(const QString &_name, const QString &_type,const QPixmap &img) : QGraphicsPixmapItem(img)
{
    name = _name;
    type = _type;
    setFlags(GraphicsItemFlag::ItemIsMovable | GraphicsItemFlag::ItemIsSelectable | GraphicsItemFlag::ItemIsFocusable);
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
   /*if(event->button() == Qt::MouseButton::LeftButton){

       QGraphicsItem::mousePressEvent(event);
       qDebug() <<"click";


    }
    }*/
}

void mapItem::getAreaOnDrag(const QPointF & p)
{
     TmxViewer * viewer = reinterpret_cast<TmxViewer *>(parent()->parent());
     QList<Area> listAreas = viewer->getAreas();
     foreach(Area ar,listAreas)
     {

     }

     /**
     for(int i = 0; i < listAreas.count();i++)
     {
         if(listAreas[i].polygon().containsPoint(p,Qt::FillRule::WindingFill))
         {
             qDebug()<<listAreas[i].name();
             return;
         }
     }
     **/
}

//Gestion de l'événement release de la souris
void mapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
   if(event->button() == Qt::MouseButton::LeftButton){

  /* if(event->button() != Qt::MouseButton::LeftButton){


       QGraphicsItem::mouseReleaseEvent(event);
       getAreaOnDrag(scenePos());
       setPos(scenePos());

    }*/


}

}


