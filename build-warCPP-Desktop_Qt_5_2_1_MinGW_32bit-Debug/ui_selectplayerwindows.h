/********************************************************************************
** Form generated from reading UI file 'selectplayerwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTPLAYERWINDOWS_H
#define UI_SELECTPLAYERWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_SelectPlayerWindows
{
public:
    QLabel *labeljoueur1;
    QLabel *labeljoueur2;
    QPushButton *pushButtonCommencer;
    QPushButton *pushButtonRetour;
    QRadioButton *radioButtonJ1;
    QRadioButton *radioButtonJ2;
    QLabel *labelNom;
    QLabel *labelFirst;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;

    void setupUi(QDialog *SelectPlayerWindows)
    {
        if (SelectPlayerWindows->objectName().isEmpty())
            SelectPlayerWindows->setObjectName(QStringLiteral("SelectPlayerWindows"));
        SelectPlayerWindows->resize(532, 247);
        labeljoueur1 = new QLabel(SelectPlayerWindows);
        labeljoueur1->setObjectName(QStringLiteral("labeljoueur1"));
        labeljoueur1->setGeometry(QRect(70, 83, 131, 31));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Handwriting"));
        font.setPointSize(12);
        labeljoueur1->setFont(font);
        labeljoueur1->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/panneau2.png);"));
        labeljoueur1->setAlignment(Qt::AlignCenter);
        labeljoueur2 = new QLabel(SelectPlayerWindows);
        labeljoueur2->setObjectName(QStringLiteral("labeljoueur2"));
        labeljoueur2->setGeometry(QRect(70, 124, 131, 30));
        labeljoueur2->setFont(font);
        labeljoueur2->setStyleSheet(QLatin1String("background-image: url(:/fond/images/panneau2.png);\n"
"border-top-color: rgb(0, 0, 0);"));
        labeljoueur2->setAlignment(Qt::AlignCenter);
        pushButtonCommencer = new QPushButton(SelectPlayerWindows);
        pushButtonCommencer->setObjectName(QStringLiteral("pushButtonCommencer"));
        pushButtonCommencer->setGeometry(QRect(330, 190, 181, 41));
        pushButtonCommencer->setFont(font);
        pushButtonCommencer->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        pushButtonRetour = new QPushButton(SelectPlayerWindows);
        pushButtonRetour->setObjectName(QStringLiteral("pushButtonRetour"));
        pushButtonRetour->setGeometry(QRect(20, 190, 121, 41));
        pushButtonRetour->setFont(font);
        pushButtonRetour->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        radioButtonJ1 = new QRadioButton(SelectPlayerWindows);
        radioButtonJ1->setObjectName(QStringLiteral("radioButtonJ1"));
        radioButtonJ1->setGeometry(QRect(356, 90, 31, 21));
        radioButtonJ2 = new QRadioButton(SelectPlayerWindows);
        radioButtonJ2->setObjectName(QStringLiteral("radioButtonJ2"));
        radioButtonJ2->setGeometry(QRect(356, 122, 31, 31));
        labelNom = new QLabel(SelectPlayerWindows);
        labelNom->setObjectName(QStringLiteral("labelNom"));
        labelNom->setGeometry(QRect(250, 50, 61, 31));
        labelNom->setFont(font);
        labelNom->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        labelFirst = new QLabel(SelectPlayerWindows);
        labelFirst->setObjectName(QStringLiteral("labelFirst"));
        labelFirst->setGeometry(QRect(340, 50, 91, 31));
        labelFirst->setFont(font);
        labelFirst->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(SelectPlayerWindows);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 89, 113, 20));
        lineEdit->setMaxLength(15);
        lineEdit_2 = new QLineEdit(SelectPlayerWindows);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        lineEdit_2->setGeometry(QRect(220, 129, 113, 21));
        lineEdit_2->setMaxLength(15);
        label = new QLabel(SelectPlayerWindows);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 541, 251));
        label->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/selectNation (532x333).jpg);"));
        label->raise();
        labeljoueur1->raise();
        labeljoueur2->raise();
        pushButtonCommencer->raise();
        pushButtonRetour->raise();
        radioButtonJ1->raise();
        radioButtonJ2->raise();
        labelNom->raise();
        labelFirst->raise();
        lineEdit->raise();
        lineEdit_2->raise();

        retranslateUi(SelectPlayerWindows);
        QObject::connect(pushButtonRetour, SIGNAL(clicked()), SelectPlayerWindows, SLOT(close()));

        QMetaObject::connectSlotsByName(SelectPlayerWindows);
    } // setupUi

    void retranslateUi(QDialog *SelectPlayerWindows)
    {
        SelectPlayerWindows->setWindowTitle(QApplication::translate("SelectPlayerWindows", "WarCpp - S\303\251lection des joueurs", 0));
        labeljoueur1->setText(QApplication::translate("SelectPlayerWindows", "Joueur1 :", 0));
        labeljoueur2->setText(QApplication::translate("SelectPlayerWindows", "Joueur2 :", 0));
        pushButtonCommencer->setText(QApplication::translate("SelectPlayerWindows", "Commencer", 0));
        pushButtonRetour->setText(QApplication::translate("SelectPlayerWindows", "Retour", 0));
        radioButtonJ1->setText(QString());
        radioButtonJ2->setText(QString());
        labelNom->setText(QApplication::translate("SelectPlayerWindows", "Nom", 0));
        labelFirst->setText(QApplication::translate("SelectPlayerWindows", "First", 0));
        lineEdit_2->setText(QApplication::translate("SelectPlayerWindows", "AlbatorBot", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectPlayerWindows: public Ui_SelectPlayerWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTPLAYERWINDOWS_H
