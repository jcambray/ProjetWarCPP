#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "tmxviewer.h"
#include "mapitem.h"

using namespace Tiled;

class gameMap
{
public:
    gameMap();
    //retourne le QGraphicsView contenant la map
    TmxViewer * getViewer();

    //affiche un item sur la map à partir d'une image
    mapItem * addItem(const QString & img,int x, int y);

    //ajoute les items sur la map
    void addAllItems();

private:

    TmxViewer *viewer;
};

#endif // GAMEMAP_H
