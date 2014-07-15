#ifndef DISPLAYENDGAME_H
#define DISPLAYENDGAME_H

#include <QDialog>
#include "player.h"

namespace Ui {
class DisplayEndGame;
}

class DisplayEndGame : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayEndGame(QWidget *parent = 0);
    void SetDisplayEndGame(player *winner,player *loser);
    ~DisplayEndGame();

signals:
    void quitterEndGame();

private slots:
    void on_Quitter_clicked();

private:
    Ui::DisplayEndGame *ui;
};

#endif // DISPLAYENDGAME_H
