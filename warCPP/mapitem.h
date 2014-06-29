#ifndef MAPITEM_H
#define MAPITEM_H
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


class mapItem : public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

public:
    mapItem();
    mapItem(const mapItem &);
    mapItem(const QString & _name, const QString & _type, const QPixmap &);
    void setName(const QString & _name);
    void setType(const QString & newType);
    const QString & getName();


private:

    QString name,type;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
};

#endif // MAPITEM_H
