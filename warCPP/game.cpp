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
    selectPlayer = new SelectPlayerWindows();
    selectNationPower = new SelectNationPowerWindows();
}
game::~game()
{
    delete selectPlayer;
    delete selectNationPower;
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

   /* map = new gameMap();
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
    if(!IA)
    {
        selectPlayer->enableLineEdit2();

    }
    QObject::connect(selectPlayer,SIGNAL(ButtonCommencer(QString,QString,int)),this,SLOT(selectionNationPower(QString,QString,int)));
    selectPlayer->show();
}


void game::selectionNationPower(QString nameJ1,QString nameJ2, int first)
{

    if(first == 1)
    {
        selectNationPower->prepareSelectNationPower(nameJ1);
    }
    else if(first == 2)
    {
        selectNationPower->prepareSelectNationPower(nameJ2);
    }
    QObject::connect(selectNationPower,SIGNAL(createJoueur(QString,QString,QString)),this,SLOT(creationJoeur(QString,QString,QString)));
    selectNationPower->show();
}

void game::creationJoeur(QString namePlayer,QString nation, QString power)
{
    if(p1.getName() == tr(""))
    {
        QMessageBox::information(this, tr("Joueur 1"),namePlayer+tr(" ")+nation+tr(" ")+power );

    }
    else
    {
        QMessageBox::information(this, tr("Joueur 2"),namePlayer+tr(" ")+nation+tr(" ")+power );
    }
}

void game::randomlySetPower(player ps[]){



}

void game::conquere(player p1, player p2){

}

void game::deploy(player p){

}

void game::decline(player p){

}

void game::endRound(){


}

void game::endGame(){


    if(p1.getScore()>p2.getScore())
        qDebug()<<"Player 1 win";
    else if (p1.getScore()<p2.getScore())
        qDebug()<<"Player 2 win";
    else
        qDebug()<<"Egalite";
}
