#ifndef MAPITEM_H
#define MAPITEM_H
#include <QMessageBox>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>


class mapItem : public QGraphicsPixmapItem
{
public:
    mapItem();
    mapItem(const QString & _name, const QString & _type);
    void setName(const QString & _name);
    void setType(const QString & newType);
    const QString & getName();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:

    QString name,type;
};

#endif // MAPITEM_H
