#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "tmxviewer.h"
#include "glossary.h"



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
    void printArea();
    void printNation();
    void printPower();
    void printRules();
    void btnNouvellePartieClicked();

private:

    Ui::MainWindow *ui;
    Glossary *g;
    QMenu *fichierMenu,*nvllePartieMenu,*chargerPartieMenu,*quitMenu;


};



#endif // MAINWINDOW_H
