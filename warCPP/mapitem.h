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

class gameMap;

class mapItem : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:
    mapItem();
    mapItem(const mapItem &);
    mapItem(const QPixmap &, player *,gameMap *);
    ~mapItem();
    void setType(const QString & newType);
    player * getOwnerPlayer();
    void setOwnerPlayer(const player & p);
    void setAnciennePos(QPointF &p);
    QPointF getAnciennePos();
    bool validateMove(Area *);


private:

    QString type;
    QPointF * anciennePos;
    player * ownerPlayer;
    gameMap * gameM;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
};

#endif // MAPITEM_H
