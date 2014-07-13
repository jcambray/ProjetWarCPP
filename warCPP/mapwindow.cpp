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
    g = new Glossary();
    setWindowTitle(tr("War CPP"));
    ui->groupBoxJ1->setTitle(gameM->partie->getP1()->getName());
    ui->groupBoxJ2->setTitle(gameM->partie->getP2()->getName());
    ui->combiJ1->setText(gameM->partie->getP1()->nat->getName()+tr(" ")+gameM->partie->getP1()->pow->getName());
    ui->combiJ2->setText(gameM->partie->getP2()->nat->getName()+tr(" ")+gameM->partie->getP2()->pow->getName());
    setCentralWidget(gameM->viewer);
    gameM->viewer->viewMap(tr("map//map.tmx"));
    gameM->viewer->populateAreas();
    QObject::connect(ui->actionQuitter,SIGNAL(triggered()),this,SLOT(quitter()));
    QObject::connect(ui->actionR_gles,SIGNAL(triggered()),this,SLOT(printRules()));
    QObject::connect(ui->actionR_gions,SIGNAL(triggered()),this,SLOT(printArea()));
    QObject::connect(ui->actionPeuples,SIGNAL(triggered()),this,SLOT(printNation()));
    QObject::connect(ui->actionPouvoirs,SIGNAL(triggered()),this,SLOT(printPower()));
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

void MapWindow::quitter()
{
    emit quitterGame();
    this->close();
}

void MapWindow::printArea(){
    //g->getMSGArea();
    g->getUIArea();
}

void MapWindow::printNation(){
    //g->getMSGNation();
    g->getUINation();
}

void MapWindow::printPower(){
   // g->getMSGPower();
    g->getUIPower();
}

void MapWindow::printRules(){
    //g->getMSGRules();
    g->getUIRules();
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

void MapWindow::on_pushGoldP1_clicked()
{
    QString score = QString::number(gameM->partie->getP1()->getScore());
    QMessageBox::information(this, tr("Information pour ")+gameM->partie->getP1()->getName(),tr("Votre score actuel est de ")+score+tr(" pièce d'or"));
}

void MapWindow::on_pushGoldP2_clicked()
{
    QString score = QString::number(gameM->partie->getP2()->getScore());
    QMessageBox::information(this, tr("Information pour ")+gameM->partie->getP2()->getName(),tr("Votre score actuel est de ")+score+tr(" pièce d'or"));
}
