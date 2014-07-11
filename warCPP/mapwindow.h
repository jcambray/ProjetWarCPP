#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>

namespace Ui {
class MapWindow;
}

class gameMap;

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(gameMap *, QWidget *parent = 0);
    void displayPlayer1Name(QString);
    void displayPlayer2Name(QString);
    void displayPlayer1Score(int);
    void displayPlayer2Score(int);
    ~MapWindow();

public slots:

    //void btnNextStepClicked();

private:
    Ui::MapWindow *ui;
    gameMap * gameM;

};

#endif // MAPWINDOW_H
