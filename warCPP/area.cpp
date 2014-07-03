#include "area.h"

Area::Area() : MapObject()
{
    active = false;
    ownerPlayerName = QLatin1String("nobody");
}


Area::Area(const QString & name, const QString & type, const QPointF & point, const QSizeF & size) : MapObject(name,type,point,size)
{
    active = false;
    ownerPlayerName = QLatin1String("nobody");
}

bool Area::isActive()
{
    return active;
}


QString & Area::getOwnerPlayerName()
{
    return ownerPlayerName;
}
