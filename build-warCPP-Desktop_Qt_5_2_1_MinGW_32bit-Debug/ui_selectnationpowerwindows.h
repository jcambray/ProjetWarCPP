/********************************************************************************
** Form generated from reading UI file 'selectnationpowerwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTNATIONPOWERWINDOWS_H
#define UI_SELECTNATIONPOWERWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectNationPowerWindows
{
public:
    QLabel *labelJoueur;
    QLabel *labelTitre;
    QListView *listView;
    QPushButton *pushButton_2;
    QPushButton *pushChoisir;
    QLabel *labelPower;
    QLabel *labelImage;
    QLabel *labelNation;
    QLabel *label;

    void setupUi(QDialog *SelectNationPowerWindows)
    {
        if (SelectNationPowerWindows->objectName().isEmpty())
            SelectNationPowerWindows->setObjectName(QStringLiteral("SelectNationPowerWindows"));
        SelectNationPowerWindows->setEnabled(true);
        SelectNationPowerWindows->resize(754, 517);
        SelectNationPowerWindows->setModal(false);
        labelJoueur = new QLabel(SelectNationPowerWindows);
        labelJoueur->setObjectName(QStringLiteral("labelJoueur"));
        labelJoueur->setGeometry(QRect(60, 30, 201, 31));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Handwriting"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelJoueur->setFont(font);
        labelJoueur->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/panneau2.png);"));
        labelJoueur->setAlignment(Qt::AlignCenter);
        labelTitre = new QLabel(SelectNationPowerWindows);
        labelTitre->setObjectName(QStringLiteral("labelTitre"));
        labelTitre->setGeometry(QRect(370, 20, 371, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Handwriting"));
        font1.setPointSize(13);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        labelTitre->setFont(font1);
        labelTitre->setStyleSheet(QStringLiteral("font: 75 13pt \"Lucida Handwriting\";"));
        listView = new QListView(SelectNationPowerWindows);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(485, 100, 251, 271));
        QFont font2;
        font2.setFamily(QStringLiteral("Lucida Handwriting"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(9);
        listView->setFont(font2);
        listView->setLayoutDirection(Qt::LeftToRight);
        listView->setStyleSheet(QLatin1String("background-image: url(:/fond/Bouton);\n"
"font: 75 12pt \"Lucida Handwriting\";"));
        listView->setAutoScroll(false);
        listView->setAutoScrollMargin(16);
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setProperty("showDropIndicator", QVariant(false));
        listView->setDragEnabled(false);
        listView->setTextElideMode(Qt::ElideMiddle);
        listView->setFlow(QListView::TopToBottom);
        listView->setSpacing(8);
        listView->setBatchSize(100);
        listView->setWordWrap(true);
        listView->setSelectionRectVisible(false);
        pushButton_2 = new QPushButton(SelectNationPowerWindows);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 460, 141, 41));
        QFont font3;
        font3.setFamily(QStringLiteral("Lucida Handwriting"));
        font3.setPointSize(12);
        pushButton_2->setFont(font3);
        pushButton_2->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        pushChoisir = new QPushButton(SelectNationPowerWindows);
        pushChoisir->setObjectName(QStringLiteral("pushChoisir"));
        pushChoisir->setGeometry(QRect(580, 460, 141, 41));
        pushChoisir->setFont(font3);
        pushChoisir->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        labelPower = new QLabel(SelectNationPowerWindows);
        labelPower->setObjectName(QStringLiteral("labelPower"));
        labelPower->setGeometry(QRect(20, 410, 711, 51));
        QFont font4;
        font4.setFamily(QStringLiteral("Lucida Handwriting"));
        font4.setPointSize(11);
        labelPower->setFont(font4);
        labelPower->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        labelPower->setScaledContents(true);
        labelPower->setWordWrap(true);
        labelImage = new QLabel(SelectNationPowerWindows);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setEnabled(true);
        labelImage->setGeometry(QRect(60, 90, 350, 281));
        labelImage->setFont(font3);
        labelNation = new QLabel(SelectNationPowerWindows);
        labelNation->setObjectName(QStringLiteral("labelNation"));
        labelNation->setGeometry(QRect(20, 380, 711, 41));
        labelNation->setFont(font4);
        labelNation->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label = new QLabel(SelectNationPowerWindows);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 761, 521));
        label->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/selectPlayer (754x471).jpg);"));
        label->raise();
        labelJoueur->raise();
        labelTitre->raise();
        listView->raise();
        pushButton_2->raise();
        pushChoisir->raise();
        labelPower->raise();
        labelImage->raise();
        labelNation->raise();

        retranslateUi(SelectNationPowerWindows);
        QObject::connect(pushButton_2, SIGNAL(clicked()), SelectNationPowerWindows, SLOT(close()));

        QMetaObject::connectSlotsByName(SelectNationPowerWindows);
    } // setupUi

    void retranslateUi(QDialog *SelectNationPowerWindows)
    {
        SelectNationPowerWindows->setWindowTitle(QApplication::translate("SelectNationPowerWindows", "WarCpp - S\303\251lection du peuple et de son pouvoir", 0));
        labelJoueur->setText(QApplication::translate("SelectNationPowerWindows", "TextLabel", 0));
        labelTitre->setText(QApplication::translate("SelectNationPowerWindows", "Choisissez votre peuple et son pouvoir !", 0));
        pushButton_2->setText(QApplication::translate("SelectNationPowerWindows", "Retour", 0));
        pushChoisir->setText(QApplication::translate("SelectNationPowerWindows", "Choisir", 0));
        labelPower->setText(QString());
        labelImage->setText(QString());
        labelNation->setText(QString());
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SelectNationPowerWindows: public Ui_SelectNationPowerWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTNATIONPOWERWINDOWS_H
