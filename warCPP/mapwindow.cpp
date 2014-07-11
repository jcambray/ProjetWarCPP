#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "gamemap.h"
#include "game.h"
#include "player.h"

MapWindow::MapWindow(gameMap *m, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapWindow)
{
    ui->setupUi(this);
    ui->bottomPanelWindow->setFixedHeight(250);
    gameM = m;
    ui->player1Name->setText(gameM->partie->getP1()->getName());
    ui->player2Name->setText(gameM->partie->getP2()->getName());
    setCentralWidget(gameM->viewer);
    gameM->viewer->viewMap(tr("map//map.tmx"));
    gameM->viewer->populateAreas();
    showMaximized();
}

MapWindow::~MapWindow()
{
    delete ui;
    delete gameM;
}
