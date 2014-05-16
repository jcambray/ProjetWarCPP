#ifndef PARTIE_H
#define PARTIE_H
#include <QString>
#include <Qvector>
#include "player.h"
#include "gamemap.h"
#include "QSaveFile"


class Partie
{
public:
    Partie();
    Partie(const qint16 nbJoueurs);
    Partie(const Partie&);
    void setCurrentPlayer(const qint16);
    ~Partie();

    bool save();
   const Partie & load(const QString &);


   void start();




private:

  QString nom;
  qint16 nbPlayers;
  player * currentPlayer;
  QVector<player> * joueurs;
  gameMap * map;


};

#endif // PARTIE_H
