#ifndef MAPITEM_H
#define MAPITEM_H
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include "area.h"
#include "tmxviewer.h"
#include "mapobject.h"
#include "map.h"
#include "objectgroup.h"
#include "player.h"


class mapItem : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:
    mapItem();
    mapItem(const mapItem &);
    mapItem(const QString & _name, const QString & _type, const QPixmap &,TmxViewer *);
    void setName(const QString & _name);
    void setType(const QString & newType);
    const QString & getName();
    Area *getAreaOnDrag(QPointF &);
    player * getOwnerPlayer();
    void setOwnerPlayer(const player & p);
    void setAnciennePos(QPointF &p);
    bool validateMove(Area *);
    QPolygonF sceneCoordinatesPolygon(const QPolygonF &,const QPointF &);

private:

    QString name,type;
    TmxViewer * viewer;
    QPointF * anciennePos;
    player * ownerPlayer;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
};

#endif // MAPITEM_H
