#include "area.h"

Area::Area() : MapObject()
{
    enDeclin = false;
    ownerPlayerName = QLatin1String("");
}

Area::Area(const Area &a)
{
    enDeclin = a.enDeclin;
    ownerPlayerName = a.ownerPlayerName;

}


Area::Area(const QString & name, const QString & type, const QPointF & point, const QSizeF & size, const QPolygonF & p, const Properties & prop) : MapObject(name,type,point,size)
{
    enDeclin = false;
    ownerPlayerName = QLatin1String("");
    setPolygon(p);
    setProperties(prop);
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

bool Area::isEdgeArea()
{
    return hasProperty(QLatin1String("isEdgeArea"));
}

int Area::getTokensToConquiert()
{
    if(type() == QLatin1String("herbe"))
        return 2;
    if(type() == QLatin1String("aqua"))
        return 1;
    if(type() == QLatin1String("arbre"))
        return 2;
    if(type() == QLatin1String("rocher"))
        return 3;
    if(type() == QLatin1String("sable"))
        return 1;
    if(type() == QLatin1String("chateau"))
        return 5;
    if(type() == QLatin1String("champs"))
        return 1;
}

Area::~Area()
{

}
