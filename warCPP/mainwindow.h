#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "tmxviewer.h"




namespace Ui{
 class MainWindow;
}





class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

signals:

   void createPartie();

public slots:

void btnNouvellePartieClicked();

private:

    Ui::MainWindow *ui;
    QMenu *fichierMenu,*nvllePartieMenu,*chargerPartieMenu,*quitMenu;


};



#endif // MAINWINDOW_H
