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

private:

    QString name,type;
    TmxViewer * viewer;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
};

#endif // MAPITEM_H
