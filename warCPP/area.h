#ifndef AREA_H
#define AREA_H
#include "mapobject.h"

using namespace Tiled;

class Area : public MapObject
{
public:
    Area();
    Area(const QString &,const QString &,const QPointF &, const QSizeF &);
    bool isActive();
    QString & getOwnerPlayerName();

private:

    bool active;
    QString ownerPlayerName;
};

#endif // AREA_H
