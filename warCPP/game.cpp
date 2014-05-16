#include "game.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>



game::game()
{
    partie = NULL;
    mainW = NULL;
}


void game::run()
{
    mainW = new MainWindow();
    QObject::connect(mainW,SIGNAL(createPartie()),this,SLOT(MWCreateNouvellePartieBtnClicked()));
    mainW->show();
}


void game::MWCreateNouvellePartieBtnClicked()
{
    createPartie();
}

void game::createPartie()
{
    bool check = false;
    qint16 nbplayer = QInputDialog::getInt(mainW,QLatin1String("Nouvelle Partie"),QLatin1String("Selectionnez le nombre de joueurs"),1,1,4,1,&check);
    if(check)
    {
        partie = new Partie(nbplayer);
        partie->start();
    }
}





