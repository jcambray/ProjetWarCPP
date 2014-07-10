#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "tmxviewer.h"
#include "mapitem.h"

using namespace Tiled;

class game;

class gameMap : public QObject
{

    Q_OBJECT

public:
    gameMap();
    gameMap(game * g);
    gameMap(const gameMap & map);
    ~gameMap();

    //retourne le QGraphicsView contenant la map
    TmxViewer * getViewer();

    //affiche un item sur la map à partir d'une image
    mapItem *addItem(mapItem *, int x, int y);

    //ajoute les items sur la map
    void addAllItems();

    //retourne la liste des éléments graphiques de la map
    QList<mapItem*> * getTokens();



    //Agrandit chaque carre de la map en fonction du coefficient
    void setMapItemsScale(double coeff);

    void loadTokens();

private:

    TmxViewer *viewer;
    QList<mapItem*> *tokens;
    game * partie;
};

#endif // GAMEMAP_H
