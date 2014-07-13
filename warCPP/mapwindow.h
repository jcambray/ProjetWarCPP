#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>
#include "player.h"
#include "glossary.h"

namespace Ui {
class MapWindow;
}

class gameMap;

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(gameMap *, QWidget *parent = 0);
    void displayPlayer1Name(QString &);
    void displayPlayer2Name(QString &);
    void displayPlayer1Score(int);
    void displayPlayer2Score(int);
    void displayNewPlayer(player * p1, player * p2);
    void enableGroupBox(player *p, bool val);
    void enableButtonDeclin(bool val);
    void setNbTour(int tour);


    ~MapWindow();

public slots:
    void quitter();
    void printArea();
    void printNation();
    void printPower();
    void printRules();
    //void btnNextStepClicked();

signals:
    void quitterGame();
    void redeploy(player*p);
    void endTurn(player*p);
    void modeDeclin(player*p);

private slots:


    void on_pushGoldP1_clicked();

    void on_pushGoldP2_clicked();

    //void on_pushButton_clicked();

    void on_pushButtonMapWindow_clicked();

    void on_pushButtonDeclin_clicked();

private:
    Ui::MapWindow *ui;
    Glossary *g;
    gameMap * gameM;

};

#endif // MAPWINDOW_H
