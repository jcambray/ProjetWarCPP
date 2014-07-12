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
    savJoueur2 = tr("");
    selectPlayer = new SelectPlayerWindows();
    selectNationPower = new SelectNationPowerWindows();
    p1 = new player();
    p2 = new player();
    nation = new Nation();
    power = new Power();
}
game::~game()
{
    delete selectPlayer;
    delete selectNationPower;
    delete p1;
    delete p2;
    delete nation;
    delete power;
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
    QObject::connect(selectPlayer,SIGNAL(ButtonCommencer(QString,QString)),this,SLOT(selectionNationPower(QString,QString)));
    selectPlayer->show();
}


void game::selectionNationPower(QString nameJ1,QString nameJ2)
{
    savJoueur2 =nameJ2;
    selectNationPower->prepareSelectNationPower(nameJ1);

    QObject::connect(selectNationPower,SIGNAL(createJoueur(QString,QString,QString)),this,SLOT(creationJoeur(QString,QString,QString)));
    QObject::connect(selectNationPower,SIGNAL(UpJoueur(QString,QString,QString)),this,SLOT(upDateJoueur(QString,QString,QString)));
    selectNationPower->show();

}

void game::creationJoeur(QString qsnamePlayer,QString qsnation, QString qspower)
{

    if(qsnation == tr("Amazones"))
    {
        nation = new Nation(qsnation,1,5);
    }
    if(qsnation == tr("Humains"))
    {
        nation = new Nation(qsnation,2,5);
    }
    if(qsnation == tr("Squelettes"))
    {
        nation = new Nation(qsnation,3,6);
    }
    if(qsnation == tr("Hommes-rats"))
    {
        nation = new Nation(qsnation,4,8);
    }

    if(qspower == tr("Pirates"))
    {
        power = new Power(qspower,1,5);
    }
    if(qspower == tr("Et leur Dragon"))
    {
        power = new Power(qspower,2,5);
    }
    if(qspower == tr("Bucherons"))
    {
        power = new Power(qspower,3,4);
    }
    if(qspower == tr("Marchands"))
    {
        power = new Power(qspower,4,2);
    }

    if(p1->getName() == tr("player"))
    {
        p1 = new player(0,qsnamePlayer,nation,power);
        QMessageBox::information(this, tr("Joueur 1"),tr("Sélection de ")+qsnamePlayer+tr(" terminée. Au tour de ")+savJoueur2+tr(" de faire sa sélection."));
        selectNationPower->prepareSelectNationPower(savJoueur2);
    }
    else
    {
        p2 = new player(0,qsnamePlayer,nation,power);
        QMessageBox::information(this, tr("Joueur 2"),qsnamePlayer+tr(" ")+qsnation+tr(" ")+qspower );
        selectNationPower->setDebutGame(false);
    }

    if(p1->getName() != tr("player") && p2->getName() != tr("player"))
        renderMap();
}

void game::upDateJoueur(QString qsnamePlayer,QString qsnation, QString qspower)
{

    if(qsnation == tr("Amazones"))
    {
        nation = new Nation(qsnation,1,5);
    }
    if(qsnation == tr("Humains"))
    {
        nation = new Nation(qsnation,2,5);
    }
    if(qsnation == tr("Squelettes"))
    {
        nation = new Nation(qsnation,3,6);
    }
    if(qsnation == tr("Hommes-rats"))
    {
        nation = new Nation(qsnation,4,8);
    }

    if(qspower == tr("Pirates"))
    {
        power = new Power(qspower,1,5);
    }
    if(qspower == tr("Et leur Dragon"))
    {
        power = new Power(qspower,2,5);
    }
    if(qspower == tr("Bucherons"))
    {
        power = new Power(qspower,3,4);
    }
    if(qspower == tr("Marchands"))
    {
        power = new Power(qspower,4,2);
    }

    if(p1->getName() == qsnamePlayer)
    {
        p1 = new player(0,qsnamePlayer,nation,power);
        QMessageBox::information(this, tr("Joueur 1"),qsnamePlayer+tr(" ")+qsnation+tr(" ")+qspower );
    }
    else
    {
        p2 = new player(0,qsnamePlayer,nation,power);
        QMessageBox::information(this, tr("Joueur 2"),qsnamePlayer+tr(" ")+qsnation+tr(" ")+qspower );
    }

    if(p1->getName() != tr("player") && p2->getName() != tr("player"))
        renderMap();
}

void game::randomlySetPower(player ps[]){



}

void game::conquere(){

}

void game::deploy(player p){

}

void game::decline(player p){

}

void game::endRound(){


}

void game::endGame(){


    if(p1->getScore()>p2->getScore())
        qDebug()<<"Player 1 win";
    else if (p1->getScore()<p2->getScore())
        qDebug()<<"Player 2 win";
    else
        qDebug()<<"Egalite";
}


void game::renderMap()
{
    map = new gameMap(this);
    map->initToken(p1,QPoint(-100,200));
    map->initToken(p2,QPoint(-100,400));
    //map->getViewer()->setWindowTitle(tr("WAR C++"));
    //map->getViewer()->show();
}

player * game::getP1()
{
    return p1;
}

player * game::getP2()
{
    return p2;
}
