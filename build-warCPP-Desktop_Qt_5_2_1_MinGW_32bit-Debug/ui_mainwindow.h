/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNouvelle_Partie;
    QAction *actionCharger_Partie;
    QAction *actionQuitter;
    QAction *actionR_gles;
    QAction *actionR_gions;
    QAction *actionPeuples;
    QAction *actionPouvoirs;
    QWidget *centralWidget;
    QLabel *Titre;
    QPushButton *btnLaunch;
    QLabel *Titre_2;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuLexique;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(639, 347);
        MainWindow->setContextMenuPolicy(Qt::PreventContextMenu);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("font: italic 12pt \"Sylfaen\";\n"
"border-color: qlineargradient(spread:pad, x1:0.47695, y1:0.688, x2:0.492462, y2:0.011, stop:0 rgba(238, 223, 141, 255), stop:1 rgba(255, 255, 255, 255));\n"
""));
        actionNouvelle_Partie = new QAction(MainWindow);
        actionNouvelle_Partie->setObjectName(QStringLiteral("actionNouvelle_Partie"));
        actionCharger_Partie = new QAction(MainWindow);
        actionCharger_Partie->setObjectName(QStringLiteral("actionCharger_Partie"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionR_gles = new QAction(MainWindow);
        actionR_gles->setObjectName(QStringLiteral("actionR_gles"));
        actionR_gions = new QAction(MainWindow);
        actionR_gions->setObjectName(QStringLiteral("actionR_gions"));
        actionPeuples = new QAction(MainWindow);
        actionPeuples->setObjectName(QStringLiteral("actionPeuples"));
        actionPouvoirs = new QAction(MainWindow);
        actionPouvoirs->setObjectName(QStringLiteral("actionPouvoirs"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Titre = new QLabel(centralWidget);
        Titre->setObjectName(QStringLiteral("Titre"));
        Titre->setGeometry(QRect(470, 180, 101, 41));
        Titre->setStyleSheet(QLatin1String("font: 16pt \"Lucida Handwriting\";\n"
"background-image: url(:/fond/images/panneau2.png);\n"
""));
        btnLaunch = new QPushButton(centralWidget);
        btnLaunch->setObjectName(QStringLiteral("btnLaunch"));
        btnLaunch->setGeometry(QRect(90, 180, 201, 61));
        btnLaunch->setStyleSheet(QLatin1String("font: 75 20pt \"Andalus\";\n"
"background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        Titre_2 = new QLabel(centralWidget);
        Titre_2->setObjectName(QStringLiteral("Titre_2"));
        Titre_2->setGeometry(QRect(410, 100, 231, 221));
        Titre_2->setStyleSheet(QLatin1String("font: italic 16pt \"Sylfaen\";\n"
"background-image: url(:/fond/images/panneau.png);"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 641, 321));
        label->setStyleSheet(QStringLiteral("background-image: url(:/fond/Lexique);"));
        MainWindow->setCentralWidget(centralWidget);
        label->raise();
        Titre_2->raise();
        btnLaunch->raise();
        Titre->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 639, 28));
        menuBar->setAutoFillBackground(false);
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QStringLiteral("menuFichier"));
        menuLexique = new QMenu(menuBar);
        menuLexique->setObjectName(QStringLiteral("menuLexique"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuLexique->menuAction());
        menuFichier->addAction(actionNouvelle_Partie);
        menuFichier->addAction(actionQuitter);
        menuLexique->addAction(actionR_gles);
        menuLexique->addAction(actionR_gions);
        menuLexique->addAction(actionPeuples);
        menuLexique->addAction(actionPouvoirs);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "War Cpp", 0));
        actionNouvelle_Partie->setText(QApplication::translate("MainWindow", "Nouvelle Partie", 0));
        actionCharger_Partie->setText(QApplication::translate("MainWindow", "Charger Partie", 0));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", 0));
        actionR_gles->setText(QApplication::translate("MainWindow", "R\303\250gles", 0));
        actionR_gions->setText(QApplication::translate("MainWindow", "R\303\251gions", 0));
        actionPeuples->setText(QApplication::translate("MainWindow", "Peuples", 0));
        actionPouvoirs->setText(QApplication::translate("MainWindow", "Pouvoirs", 0));
        Titre->setText(QApplication::translate("MainWindow", "WAR C++", 0));
        btnLaunch->setText(QApplication::translate("MainWindow", "Nouvelle partie", 0));
        Titre_2->setText(QString());
        label->setText(QString());
        menuFichier->setTitle(QApplication::translate("MainWindow", "Fichier", 0));
        menuLexique->setTitle(QApplication::translate("MainWindow", "Lexique", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
