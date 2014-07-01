#include "game.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>



game::game()
{
    mainW = NULL;
    map = NULL;
}


void game::run()
{
    mainW = new MainWindow();
    QObject::connect(mainW,SIGNAL(createPartie()),this,SLOT(MWCreateNouvellePartieBtnClicked()));
    mainW->show();
}

void game::start()
{
    map = new gameMap();
    map->setMapItemsScale(1.2);
    map->addAllItems();
    map->getViewer()->setWindowTitle(QLatin1String("WAR C++"));
    map->getViewer()->show();
}


void game::MWCreateNouvellePartieBtnClicked()
{
    start();
}






