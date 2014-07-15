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
    displayEndGame = new DisplayEndGame();
    p1 = new player();
    p2 = new player();
    nation = new Nation();
    power = new Power();
    nbTour = 1;
    deployStep = false;
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
    QObject::connect(selectNationPower,SIGNAL(retour()),this,SLOT(pushRetour()));
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
    if(qsnation == tr("Hommes-Rats"))
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
        p1->setToken(p1->nat->getToken()+p1->pow->getToken());
        QMessageBox::information(this, tr("Joueur 1"),tr("Sélection de ")+qsnamePlayer+tr(" terminée. Au tour de ")+savJoueur2+tr(" de faire sa sélection"));
        //QMessageBox::information(this, tr("Joueur 1"),qsnamePlayer+tr(" ")+qsnation+tr(" ")+qspower );
        selectNationPower->prepareSelectNationPower(savJoueur2);
        delete selectPlayer;
    }
    else
    {
        p2 = new player(0,qsnamePlayer,nation,power);
        p2->setToken(p2->nat->getToken()+p2->pow->getToken());
        //QMessageBox::information(this, tr("Joueur 2"),qsnamePlayer+tr(" ")+qsnation+tr(" ")+qspower );
        selectNationPower->setDebutGame(false);
    }

    if(p1->getName() != tr("player") && p2->getName() != tr("player")){
        selectNationPower->close();
        renderMap();
        currentGame(p1,p2);
        QObject::connect(map->mapView,SIGNAL(quitterGame()),this,SLOT(pushQuitter()));
        QObject::connect(map->mapView,SIGNAL(redeploy(player*)),this,SLOT(deploy(player*)));
        QObject::connect(map->mapView,SIGNAL(endTurn(player*)),this,SLOT(endRound(player*)));
        QObject::connect(map->mapView,SIGNAL(modeDeclin(player*)),this,SLOT(decline(player*)));
    }
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
    if(qsnation == tr("Hommes-Rats"))
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

    p1 = new player(2,qsnamePlayer,nation,power);
    p1->setToken(p1->nat->getToken()+p1->pow->getToken());

    selectNationPower->close();
    map->mapView->displayNewPlayer(p1,p2);
    map->initToken(p1,getSpawnPos(),p1->getToken());
    currentGame(p1,p2);

}

void game::pushRetour()
{
    savJoueur2 = tr("");
    selectNationPower = new SelectNationPowerWindows();
}

void game::pushQuitter()
{
    map->mapView->close();
    selectNationPower->close();
    mainW = NULL;
    map = NULL;
    vsIA = NULL;
    savJoueur2 = tr("");
    selectPlayer = new SelectPlayerWindows();
    selectNationPower = new SelectNationPowerWindows();
    displayEndGame = new DisplayEndGame();
    p1 = new player();
    p2 = new player();
    nation = new Nation();
    power = new Power();
    nbTour = 1;
    deployStep = false;
}

void game::currentGame(player *currentPlayer, player *secondPlayer)
{
    p1 = currentPlayer;
    p2 = secondPlayer;

    if(currentPlayer->getDeclin()==1)
    {
        selectNationPower->prepareSelectNationPower(currentPlayer->getName());
        selectNationPower->show();
        map->removeAllPlayerTokens(currentPlayer);
    }
    else
    {
        if(nbTour != 13)
        {
            if(currentPlayer->getDeclin()==2)
            {
                map->mapView->enableButtonDeclin(false);
            }
            else
            {
                map->mapView->enableButtonDeclin(true);
            }
            nbTour++;
            map->mapView->setNbTour(nbTour);
            map->mapView->enableGroupBox(secondPlayer,false);
            map->mapView->enableGroupBox(currentPlayer,true);
            QMessageBox::information(this, tr(""),currentPlayer->getName()+tr(", Partez à l'attaque"));

        }
        else
        {
            endGame();
        }
     }
}

void game::conquere(){

}

void game::deploy(player *p){

    QMessageBox::information(this, tr(""),p->getName()+tr(", Redéployez vos troupes !"));

}

void game::decline(player *p)
{
    p->setDeclin(1);
    endRound(p);
}

void game::endRound(player* p){
    int score = map->getTourScore();
    p1->setScore(p1->getScore() + score);
    QMessageBox::information(this, tr("Fin du tour"),p->getName()+tr(", Vous remportez ")+ QString::number(score) + tr(" pièce(s) d'or durant ce tour"));
    currentGame(p2,p1);
}

void game::endGame(){

    QObject::connect(displayEndGame,SIGNAL(quitterEndGame()),this,SLOT(pushQuitter()));
    if(p1->getScore()>p2->getScore())
    {
        displayEndGame->SetDisplayEndGame(p1,p2);
        displayEndGame->show();
    }
   else if (p1->getScore()<p2->getScore())
    {
        displayEndGame->SetDisplayEndGame(p2,p1);
        displayEndGame->show();
    }
    else
    {
        QMessageBox::information(this, tr("Fin de la partie"),p2->getName()+tr(" et ")+p1->getName()+tr(", Vous êtes en égalité."));
        pushQuitter();
    }

}


void game::renderMap()
{
    map = new gameMap(this);
    map->initToken(p1,QPoint(-100,200),p1->getToken());
    map->initToken(p2,QPoint(-100,400),p2->getToken());
}

player * game::getP1()
{
    return p1;
}

player * game::getP2()
{
    return p2;
}

QPoint game::getSpawnPos()
{
    if(nbTour % 2 == 0)
       return QPoint(-100,400);
    else
       return QPoint(-100,200);
}
