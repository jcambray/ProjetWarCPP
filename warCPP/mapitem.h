#ifndef MAPITEM_H
#define MAPITEM_H
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
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
    mapItem(const QPixmap &, TmxViewer *, player *);
    ~mapItem();
    void setType(const QString & newType);
    player * getOwnerPlayer();
    void setOwnerPlayer(const player & p);
    void setAnciennePos(QPointF &p);
    QPointF getAnciennePos();
    bool validateMove(Area *);

private:

    QString type;
    TmxViewer * viewer;
    QPointF * anciennePos;
    player * ownerPlayer;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
};

#endif // MAPITEM_H
