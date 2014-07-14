#ifndef AREA_H
#define AREA_H
#include "mapobject.h"


using namespace Tiled;

class Area : public MapObject
{
public:
    Area();
    Area(const Area &);
    Area(const QString &,const QString &,const QPointF &, const QSizeF &,const QPolygonF &,const Properties &);
    ~Area();
    QString & getOwnerPlayerName();
    void setOwnerPlayerName(const QString &);
    bool operator !=(const Area &);
    bool isEdgeArea();
    bool enDeclin;
    int getTokensToConquiert();

private:

    QString ownerPlayerName;
};

#endif // AREA_H
