#ifndef GAME_H
#define GAME_H


#include "mainwindow.h"
#include "selectplayerwindows.h"
#include "selectnationpowerwindows.h"
#include "gamemap.h"
#include "player.h"

class game : public QWidget
{

    Q_OBJECT

public:

    game();
    void run();

    //Demarre une nouvelle partie
    void start();
    void selectionPlayer(bool IA);
    void randomlySetPower(player ps[]);
    void conquere(player p1, player p2);
    void deploy(player p);
    void decline(player p);
    void endRound();
    void endGame();


public slots:

    void MWCreateNouvellePartieBtnClicked();
    void selectionNationPower(QString nameJ1,QString nameJ2, int first);


private:
    player p1,p2;
    bool vsIA;
    MainWindow *mainW;
    SelectPlayerWindows * selectPlayer;
    SelectNationPowerWindows * selectNationPower;
    gameMap * map;
};



#endif // GAME_H
