#ifndef GAME_H
#define GAME_H


#include "mainwindow.h"
#include "selectplayerwindows.h"
#include "gamemap.h"

class game : public QWidget
{

    Q_OBJECT

public:

    game();
    void run();

    //Demarre une nouvelle partie
    void start();
    void selectionPlayer(bool IA);

public slots:

    void MWCreateNouvellePartieBtnClicked();
    void SPWSelectionPlayer(QString nameJ1,QString nameJ2, int first);


private:

    bool vsIA;
    MainWindow *mainW;
    SelectPlayerWindows * selectPlayer;
    gameMap * map;
};



#endif // GAME_H
