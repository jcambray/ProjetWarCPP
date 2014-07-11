#ifndef GAME_H
#define GAME_H


#include "mainwindow.h"
#include "selectplayerwindows.h"
#include "selectnationpowerwindows.h"
#include "gamemap.h"
#include "player.h"
#include "nation.h"
#include "power.h"

class game : public QWidget
{

    Q_OBJECT

public:

    game();
    ~game();
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
    void renderMap();
    player * getP1();
    player * getP2();


public slots:

    void MWCreateNouvellePartieBtnClicked();
    void selectionNationPower(QString nameJ1,QString nameJ2);
    void creationJoeur(QString qsnamePlayer,QString qsnation, QString qspower);


private:
    player *p1,*p2;
    Nation *nation;
    Power * power;
    bool vsIA;
    MainWindow *mainW;
    SelectPlayerWindows * selectPlayer;
    SelectNationPowerWindows * selectNationPower;
    gameMap * map;
    QString savJoueur2;
};



#endif // GAME_H
