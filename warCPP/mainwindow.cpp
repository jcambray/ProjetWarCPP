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

    QObject::connect(ui->btnLaunch,SIGNAL(clicked()),this,SLOT(btnNouvellePartieClicked()));
}


void MainWindow::btnNouvellePartieClicked()
{
    emit createPartie();
}



MainWindow::~MainWindow()
{
    delete ui;
}


