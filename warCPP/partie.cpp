#include "partie.h"
#include <QmessageBox>

Partie::Partie()
{
    joueurs = new QVector<player>();
    currentPlayer = NULL;
    map = new gameMap();
}

Partie::Partie(const qint16 nbJoueurs)
{
    currentPlayer = NULL;
    nbPlayers = nbJoueurs;
    joueurs = new QVector<player>(nbPlayers);
    map = new gameMap();
}

void Partie::setCurrentPlayer(const qint16 nb)
{
    if(nb > 0 && nb < nbPlayers)
    {
        currentPlayer = new player(joueurs->at(nb));
    }
}

void Partie::start()
{
    map->addAllItems();
    map->getViewer()->setWindowTitle(QLatin1String("WAR C++"));
    map->getViewer()->show();
}



Partie::~Partie()
{
    joueurs->clear();
    delete joueurs;
}
