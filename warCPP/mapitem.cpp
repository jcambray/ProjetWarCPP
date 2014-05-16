#include "mapitem.h"
#include <QDebug>

mapItem::mapItem() : QGraphicsPixmapItem()
{
}

mapItem::mapItem(const QString &_name){
    name = _name;
}

void mapItem::setName(const QString &_name){
    name = _name;
}

const QString & mapItem::getName()
{
    return name;
}

void mapItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mousePressEvent(event);
    qDebug() <<"click";
    QMessageBox::information(0,QLatin1String("test"),QLatin1String("Event Working!!"));

}
