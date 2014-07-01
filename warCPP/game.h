#ifndef GAME_H
#define GAME_H


#include "mainwindow.h"
#include "gamemap.h"

class game : public QWidget
{

    Q_OBJECT

public:

    game();
    void run();

    //Demarre une nouvelle partie
    void start();

public slots:

    void MWCreateNouvellePartieBtnClicked();


private:

    MainWindow *mainW;
    gameMap * map;
};



#endif // GAME_H
