/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouvelle_Partie;
    QAction *actionCharger_Partie;
    QAction *actionQuitter;
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *btnLaunch;
    QLabel *background;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 343);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("font: italic 12pt \"Sylfaen\";\n"
"border-color: qlineargradient(spread:pad, x1:0.47695, y1:0.688, x2:0.492462, y2:0.011, stop:0 rgba(238, 223, 141, 255), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
""));
        actionNouvelle_Partie = new QAction(MainWindow);
        actionNouvelle_Partie->setObjectName(QStringLiteral("actionNouvelle_Partie"));
        actionCharger_Partie = new QAction(MainWindow);
        actionCharger_Partie->setObjectName(QStringLiteral("actionCharger_Partie"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 0, 111, 81));
        QFont font;
        font.setFamily(QStringLiteral("Sylfaen"));
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QLatin1String("font: italic 16pt \"Sylfaen\";\n"
""));
        btnLaunch = new QPushButton(centralWidget);
        btnLaunch->setObjectName(QStringLiteral("btnLaunch"));
        btnLaunch->setGeometry(QRect(60, 120, 181, 61));
        btnLaunch->setStyleSheet(QStringLiteral(""));
        background = new QLabel(centralWidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, -30, 691, 321));
        background->setStyleSheet(QLatin1String("background-image: url(:/fond/Lexique);\n"
""));
        MainWindow->setCentralWidget(centralWidget);
        background->raise();
        label->raise();
        btnLaunch->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 28));
        menuBar->setStyleSheet(QLatin1String("background-image: url(:/fond/Lexique);\n"
""));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFichier->menuAction());
        menuFichier->addAction(actionNouvelle_Partie);
        menuFichier->addAction(actionCharger_Partie);
        menuFichier->addAction(actionQuitter);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "War C++", 0));
        actionNouvelle_Partie->setText(QApplication::translate("MainWindow", "Nouvelle Partie", 0));
        actionCharger_Partie->setText(QApplication::translate("MainWindow", "Charger Partie", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        label->setText(QApplication::translate("MainWindow", "Warc++", 0));
        btnLaunch->setText(QApplication::translate("MainWindow", "Nouvelle partie", 0));
        background->setText(QString());
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
