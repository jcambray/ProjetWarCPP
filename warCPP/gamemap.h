#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "tmxviewer.h"
#include "mapitem.h"
#include <QMap>

using namespace Tiled;

class gameMap
{
public:
    gameMap();
    gameMap(const gameMap & map);
    ~gameMap();

    //retourne le QGraphicsView contenant la map
    TmxViewer * getViewer();

    //affiche un item sur la map à partir d'une image
    mapItem * addItem(const QString & img,int x, int y);

    //ajoute les items sur la map
    void addAllItems();

    //retourne la liste des éléments graphiques de la map
    QMap<QString,mapItem> getItems();

    void setMapItemsScale(double coeff);


private:

    TmxViewer *viewer;
    QMap<QString,mapItem> items;
};

#endif // GAMEMAP_H
