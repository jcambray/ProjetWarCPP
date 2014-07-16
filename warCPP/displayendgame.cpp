#include "displayendgame.h"
#include "ui_displayendgame.h"
#include "game.h"

DisplayEndGame::DisplayEndGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DisplayEndGame)
{
    ui->setupUi(this);
}

DisplayEndGame::~DisplayEndGame()
{
    delete ui;
}

void DisplayEndGame::on_Quitter_clicked()
{
    emit quitterEndGame();
    this->close();
}

void DisplayEndGame::SetDisplayEndGame(player *winner,player *loser)
{
    ui->LabelPlayerWin->setText(winner->getName());
    ui->LabelScoreWin->setText(QString::number(winner->getScore()));
    ui->LabelPlayerLose->setText(loser->getName());
    ui->LabelScoreLose->setText(QString::number(loser->getScore()));
}
