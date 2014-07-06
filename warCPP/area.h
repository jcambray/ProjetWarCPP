#ifndef AREA_H
#define AREA_H
#include "mapobject.h"

using namespace Tiled;

class Area : public MapObject
{
public:
    Area();
    Area(const Area &);
    Area(const QString &,const QString &,const QPointF &, const QSizeF &);
    QString & getOwnerPlayerName();
    void setOwnerPlayerName(const QString &);

    bool enDeclin;

private:

    QString ownerPlayerName;
};

#endif // AREA_H
