#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "tmxviewer.h"
#include "mapitem.h"
#include "mapwindow.h"


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


    //retourne la liste des éléments graphiques de la map
    QList<mapItem*> * getTokens();



    //Agrandit chaque carre de la map en fonction du coefficient
    void setMapItemsScale(double coeff);

    void loadTokens();

    void initToken(player *p, const QPoint);

    TmxViewer *viewer;
    game * partie;
    MapWindow * mapView;

private:


    QList<mapItem*> *tokens;

};

#endif // GAMEMAP_H
