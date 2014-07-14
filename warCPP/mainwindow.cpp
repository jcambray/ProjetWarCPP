#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QMessageBox>
#include <QInputDialog>



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
    QObject::connect(ui->actionNouvelle_Partie,SIGNAL(triggered()),this,SLOT(btnNouvellePartieClicked()));
    QObject::connect(ui->actionQuitter,SIGNAL(triggered()),this,SLOT(closeDialog()));


}

void MainWindow::closeDialog()
{
    int reponse = QMessageBox::question(this, QLatin1String("Fin"), QLatin1String("Etes-vous sur(e) de vouloir quitter ?"), QMessageBox::Yes | QMessageBox::No);

    if (reponse == QMessageBox::Yes)
    {
        QMessageBox::information(this, QLatin1String("Quitter"), QLatin1String("A bientot !"));
        this->close();
    }
    else if (reponse == QMessageBox::No)
    {
        QMessageBox::information(this, QLatin1String("Continuer"), QLatin1String("Sage descision"));
    }
}

void MainWindow::btnNouvellePartieClicked()
{
    emit createPartie();
}

void MainWindow::printArea(){
    //g->getMSGArea();
    g->getUIArea();
}

void MainWindow::printNation(){
    //g->getMSGNation();
    g->getUINation();
}

void MainWindow::printPower(){
   // g->getMSGPower();
    g->getUIPower();
}

void MainWindow::printRules(){
    //g->getMSGRules();
    g->getUIRules();
}


MainWindow::~MainWindow()
{
    delete ui;
}


