#ifndef GAME_H
#define GAME_H

#include "partie.h"
#include "mainwindow.h"


class game : public QWidget
{

    Q_OBJECT

public:

    game();
    void run();
    void createPartie();

public slots:

    void MWCreateNouvellePartieBtnClicked();


private:

    MainWindow *mainW;
    Partie * partie;
};



#endif // GAME_H
