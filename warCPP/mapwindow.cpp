#include "mapwindow.h"
#include "ui_mapwindow.h"
#include "gamemap.h"
#include "game.h"


MapWindow::MapWindow(gameMap *m, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapWindow)
{
    ui->setupUi(this);
    ui->bottomPanelWindow->setFixedHeight(250);
    gameM = m;
    ui->groupBoxJ1->setTitle(gameM->partie->getP1()->getName());
    ui->groupBoxJ2->setTitle(gameM->partie->getP2()->getName());
    ui->combiJ1->setText(gameM->partie->getP1()->nat->getName()+tr(" ")+gameM->partie->getP1()->pow->getName());
    ui->combiJ2->setText(gameM->partie->getP2()->nat->getName()+tr(" ")+gameM->partie->getP2()->pow->getName());
    setCentralWidget(gameM->viewer);
    gameM->viewer->viewMap(tr("map//map.tmx"));
    gameM->viewer->populateAreas();
    showNormal();
}


void MapWindow::displayPlayer1Name(QString & name)
{
    ui->groupBoxJ1->setTitle(name);

}

void MapWindow::displayPlayer2Name(QString & name)
{
    ui->groupBoxJ2->setTitle(name);
}

MapWindow::~MapWindow()
{
    delete ui;
    delete gameM;
}

void MapWindow::enableGroupBox(player *p, bool val)
{

    if(p->getName()==ui->groupBoxJ1->title())
    {
        ui->groupBoxJ1->setEnabled(val);
    }
    else if(p->getName()==ui->groupBoxJ2->title())
    {
        ui->groupBoxJ2->setEnabled(val);
    }
}

void MapWindow::setNbTour(int tour)
{
    QString t = QString::number(tour);
    ui->labelNbTour->setText(tr("Tour : ")+t+tr("/6"));
}
