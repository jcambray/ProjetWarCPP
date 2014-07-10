#include "area.h"

Area::Area() : MapObject()
{
    enDeclin = false;
    ownerPlayerName = QLatin1String("nobody");
}

Area::Area(const Area &a)
{
    enDeclin = a.enDeclin;
    ownerPlayerName = a.ownerPlayerName;

}


Area::Area(const QString & name, const QString & type, const QPointF & point, const QSizeF & size) : MapObject(name,type,point,size)
{
    enDeclin = false;
    ownerPlayerName = QLatin1String("nobody");
}

void Area::setOwnerPlayerName(const QString & name)
{
    ownerPlayerName = name;
}

QString & Area::getOwnerPlayerName()
{
    return ownerPlayerName;
}

bool Area::operator !=(const Area & ar)
{
    return (position() != ar.position());
}
