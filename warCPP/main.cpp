#include "mainwindow.h"
#include "glossary.h"
#include "game.h"
#include <QApplication>
#include <QtGui>
#include <QGraphicsScene>
#include "tmxviewer.h"
#include <QString>
#include <QMessageBox>
#include <QtXml>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    game g;
    g.run();
    return a.exec();
}
