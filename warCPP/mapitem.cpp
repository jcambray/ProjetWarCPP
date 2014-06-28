#include "mapitem.h"
#include <QDebug>

mapItem::mapItem() : QGraphicsPixmapItem()
{
}

mapItem::mapItem(const QString &_name, const QString &_type){
    name = _name;
    type = _type;
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

void mapItem::mousePressEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mousePressEvent(event);
    qDebug() <<"click";
    QMessageBox::information(0,QLatin1String("test"),QLatin1String("Event Working!!"));
}



