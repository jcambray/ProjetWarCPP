#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QMessageBox>
#include <QInputDialog>
#include "partie.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    g = new Glossary();
    QObject::connect(ui->btnLaunch,SIGNAL(clicked()),this,SLOT(btnNouvellePartieClicked()));
    QObject::connect(ui->actionR_gles,SIGNAL(triggered()),this,SLOT(printRules()));
    QObject::connect(ui->actionR_gions,SIGNAL(triggered()),this,SLOT(printArea()));
    QObject::connect(ui->actionPeuples,SIGNAL(triggered()),this,SLOT(printNation()));
    QObject::connect(ui->actionPouvoirs,SIGNAL(triggered()),this,SLOT(printPower()));

}


void MainWindow::btnNouvellePartieClicked()
{
    emit createPartie();
}

void MainWindow::printArea(){
    g->setName("area");
    g->print();
}

void MainWindow::printNation(){
    g->setName("nation");
    g->print();
}

void MainWindow::printPower(){
    g->setName("power");
    g->print();
}

void MainWindow::printRules(){
    g->setName("rules");
    g->print();
}


MainWindow::~MainWindow()
{
    delete ui;
}


