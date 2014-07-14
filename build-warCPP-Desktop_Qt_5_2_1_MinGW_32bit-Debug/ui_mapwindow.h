/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QAction *actionQuitter;
    QAction *actionR_gles;
    QAction *actionR_gions;
    QAction *actionPeuples;
    QAction *actionPouvoirs;
    QWidget *centralwidget;
    QDockWidget *bottomPanel;
    QWidget *bottomPanelWindow;
    QPushButton *pushButtonMapWindow;
    QGroupBox *groupBoxJ2;
    QLabel *combiJ2;
    QPushButton *pushGoldP2;
    QGroupBox *groupBoxJ1;
    QLabel *combiJ1;
    QPushButton *pushGoldP1;
    QPushButton *pushButtonDeclin;
    QLabel *labelNbTour;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuLexique;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QStringLiteral("MapWindow"));
        MapWindow->setWindowModality(Qt::WindowModal);
        MapWindow->resize(1264, 700);
        MapWindow->setMinimumSize(QSize(1136, 700));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Handwriting"));
        font.setPointSize(10);
        MapWindow->setFont(font);
        MapWindow->setStyleSheet(QStringLiteral(""));
        actionQuitter = new QAction(MapWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionQuitter->setFont(font);
        actionR_gles = new QAction(MapWindow);
        actionR_gles->setObjectName(QStringLiteral("actionR_gles"));
        actionR_gles->setFont(font);
        actionR_gions = new QAction(MapWindow);
        actionR_gions->setObjectName(QStringLiteral("actionR_gions"));
        actionR_gions->setFont(font);
        actionPeuples = new QAction(MapWindow);
        actionPeuples->setObjectName(QStringLiteral("actionPeuples"));
        actionPeuples->setFont(font);
        actionPouvoirs = new QAction(MapWindow);
        actionPouvoirs->setObjectName(QStringLiteral("actionPouvoirs"));
        actionPouvoirs->setFont(font);
        centralwidget = new QWidget(MapWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MapWindow->setCentralWidget(centralwidget);
        bottomPanel = new QDockWidget(MapWindow);
        bottomPanel->setObjectName(QStringLiteral("bottomPanel"));
        bottomPanel->setEnabled(true);
        bottomPanel->setMinimumSize(QSize(1136, 250));
        bottomPanel->setBaseSize(QSize(0, 0));
        bottomPanel->setFloating(false);
        bottomPanel->setFeatures(QDockWidget::NoDockWidgetFeatures);
        bottomPanel->setAllowedAreas(Qt::AllDockWidgetAreas);
        bottomPanelWindow = new QWidget();
        bottomPanelWindow->setObjectName(QStringLiteral("bottomPanelWindow"));
        bottomPanelWindow->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/mapViewFond.jpg);"));
        pushButtonMapWindow = new QPushButton(bottomPanelWindow);
        pushButtonMapWindow->setObjectName(QStringLiteral("pushButtonMapWindow"));
        pushButtonMapWindow->setGeometry(QRect(1000, 20, 181, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Handwriting"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        pushButtonMapWindow->setFont(font1);
        pushButtonMapWindow->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        groupBoxJ2 = new QGroupBox(bottomPanelWindow);
        groupBoxJ2->setObjectName(QStringLiteral("groupBoxJ2"));
        groupBoxJ2->setGeometry(QRect(10, 120, 901, 111));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Handwriting"));
        font2.setPointSize(14);
        font2.setBold(true);
        font2.setWeight(75);
        groupBoxJ2->setFont(font2);
        combiJ2 = new QLabel(groupBoxJ2);
        combiJ2->setObjectName(QStringLiteral("combiJ2"));
        combiJ2->setEnabled(true);
        combiJ2->setGeometry(QRect(30, 30, 291, 31));
        QFont font3;
        font3.setFamily(QStringLiteral("Lucida Handwriting"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        combiJ2->setFont(font3);
        combiJ2->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/panneau2.png);"));
        pushGoldP2 = new QPushButton(groupBoxJ2);
        pushGoldP2->setObjectName(QStringLiteral("pushGoldP2"));
        pushGoldP2->setGeometry(QRect(780, 30, 101, 61));
        pushGoldP2->setStyleSheet(QStringLiteral("image: url(:/images/Or.png);"));
        groupBoxJ1 = new QGroupBox(bottomPanelWindow);
        groupBoxJ1->setObjectName(QStringLiteral("groupBoxJ1"));
        groupBoxJ1->setEnabled(true);
        groupBoxJ1->setGeometry(QRect(10, 10, 901, 111));
        groupBoxJ1->setFont(font2);
        groupBoxJ1->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        combiJ1 = new QLabel(groupBoxJ1);
        combiJ1->setObjectName(QStringLiteral("combiJ1"));
        combiJ1->setGeometry(QRect(30, 30, 291, 31));
        combiJ1->setFont(font3);
        combiJ1->setStyleSheet(QLatin1String("background-image: url(:/fond/images/panneau2.png);\n"
""));
        pushGoldP1 = new QPushButton(groupBoxJ1);
        pushGoldP1->setObjectName(QStringLiteral("pushGoldP1"));
        pushGoldP1->setGeometry(QRect(780, 30, 101, 61));
        pushGoldP1->setStyleSheet(QStringLiteral("image: url(:/images/Or.png);"));
        pushButtonDeclin = new QPushButton(bottomPanelWindow);
        pushButtonDeclin->setObjectName(QStringLiteral("pushButtonDeclin"));
        pushButtonDeclin->setGeometry(QRect(1000, 110, 181, 61));
        pushButtonDeclin->setFont(font1);
        pushButtonDeclin->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        labelNbTour = new QLabel(bottomPanelWindow);
        labelNbTour->setObjectName(QStringLiteral("labelNbTour"));
        labelNbTour->setGeometry(QRect(1100, 200, 171, 61));
        labelNbTour->setFont(font3);
        labelNbTour->setLayoutDirection(Qt::LeftToRight);
        labelNbTour->setStyleSheet(QStringLiteral("background-image: url(:/fond/Bouton);"));
        labelNbTour->setAlignment(Qt::AlignCenter);
        bottomPanel->setWidget(bottomPanelWindow);
        groupBoxJ2->raise();
        pushButtonMapWindow->raise();
        groupBoxJ1->raise();
        pushButtonDeclin->raise();
        labelNbTour->raise();
        MapWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), bottomPanel);
        menuBar = new QMenuBar(MapWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1264, 23));
        menuBar->setFont(font);
        menuBar->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuMenu->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        menuLexique = new QMenu(menuBar);
        menuLexique->setObjectName(QStringLiteral("menuLexique"));
        menuLexique->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        MapWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuLexique->menuAction());
        menuMenu->addAction(actionQuitter);
        menuLexique->addAction(actionR_gles);
        menuLexique->addAction(actionR_gions);
        menuLexique->addAction(actionPeuples);
        menuLexique->addAction(actionPouvoirs);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QApplication::translate("MapWindow", "MainWindow", 0));
        actionQuitter->setText(QApplication::translate("MapWindow", "Quitter", 0));
        actionR_gles->setText(QApplication::translate("MapWindow", "R\303\250gles", 0));
        actionR_gions->setText(QApplication::translate("MapWindow", "R\303\251gions", 0));
        actionPeuples->setText(QApplication::translate("MapWindow", "Peuples", 0));
        actionPouvoirs->setText(QApplication::translate("MapWindow", "Pouvoirs", 0));
        pushButtonMapWindow->setText(QApplication::translate("MapWindow", "Red\303\251ployer", 0));
        groupBoxJ2->setTitle(QApplication::translate("MapWindow", "GroupBox", 0));
        combiJ2->setText(QApplication::translate("MapWindow", "TextLabel", 0));
        pushGoldP2->setText(QString());
        groupBoxJ1->setTitle(QApplication::translate("MapWindow", "GroupBox", 0));
        combiJ1->setText(QApplication::translate("MapWindow", "TextLabel", 0));
        pushGoldP1->setText(QString());
        pushButtonDeclin->setText(QApplication::translate("MapWindow", "Mode D\303\251clin", 0));
        labelNbTour->setText(QApplication::translate("MapWindow", "<html><head/><body><p>Tour : 0/6</p></body></html>", 0));
        menuMenu->setTitle(QApplication::translate("MapWindow", "Menu", 0));
        menuLexique->setTitle(QApplication::translate("MapWindow", "Lexique", 0));
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
