#include "game.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QPushButton>




game::game()
{
    mainW = NULL;
    map = NULL;
    vsIA = NULL;
}


void game::run()
{
    mainW = new MainWindow();
    mainW->setMaximumSize(mainW->size());
    mainW->setMinimumSize(mainW->size());
    QObject::connect(mainW,SIGNAL(createPartie()),this,SLOT(MWCreateNouvellePartieBtnClicked()));
    mainW->show();
}

void game::start()
{
    switch( QMessageBox::question(
                    this,
                    tr("Choix de la partie"),
                    tr("Voulez vous jouer contre un bot ?"),

                    QMessageBox::Yes |
                    QMessageBox::No |
                    QMessageBox::Cancel,

                    QMessageBox::Cancel ) )
        {
          case QMessageBox::Yes:
            qDebug( "yes" );
            vsIA = true;
            selectionPlayer(vsIA);
            break;
          case QMessageBox::No:
            qDebug( "no" );
            vsIA = false;
            selectionPlayer(vsIA);
            break;
          case QMessageBox::Cancel:
            qDebug( "cancel" );
            break;
          default:
            qDebug( "close" );
            break;
        }

    /*map = new gameMap();
    map->setMapItemsScale(1.2);
    map->addAllItems();
    map->getViewer()->setWindowTitle(QLatin1String("WAR C++"));
    map->getViewer()->show();*/
}


void game::MWCreateNouvellePartieBtnClicked()
{
    start();
}

void game::selectionPlayer(bool IA)
{
    selectPlayer = new SelectPlayerWindows();

    if(!IA)
    {
        selectPlayer->enableLineEdit2();

    }
    QObject::connect(selectPlayer,SIGNAL(ButtonCommencer(QString,QString,int)),this,SLOT(selectionNationPower(QString,QString,int)));
    selectPlayer->show();
}


void game::selectionNationPower(QString nameJ1,QString nameJ2, int first)
{
    //QMessageBox::information(this, tr("Application Name"),nameJ1+tr(" ")+nameJ2+tr(" ")+first );
    selectNationPower = new SelectNationPowerWindows();
    selectNationPower->show();
}

void game::randomlySetPower(Player ps[]){


}

void game::conquere(Player p1, Player p2){

}

void game::deploy(Player p){

}

void game::decline(Player p){

}

void game::endRound(){

}

void game::endGame(){

}
