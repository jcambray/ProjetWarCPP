/********************************************************************************
** Form generated from reading UI file 'Lexique.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEXIQUE_H
#define UI_LEXIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LexiqueWindow
{
public:
    QLabel *labelNameLexique;
    QPushButton *pushPrevious;
    QPushButton *pushNext;
    QLabel *labelImage;
    QLabel *label;
    QLabel *labelText;

    void setupUi(QDialog *LexiqueWindow)
    {
        if (LexiqueWindow->objectName().isEmpty())
            LexiqueWindow->setObjectName(QStringLiteral("LexiqueWindow"));
        LexiqueWindow->setEnabled(true);
        LexiqueWindow->resize(754, 517);
        LexiqueWindow->setModal(false);
        labelNameLexique = new QLabel(LexiqueWindow);
        labelNameLexique->setObjectName(QStringLiteral("labelNameLexique"));
        labelNameLexique->setGeometry(QRect(60, 30, 201, 31));
        QFont font;
        font.setFamily(QStringLiteral("Lucida Handwriting"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        labelNameLexique->setFont(font);
        labelNameLexique->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/panneau2.png);"));
        labelNameLexique->setAlignment(Qt::AlignCenter);
        pushPrevious = new QPushButton(LexiqueWindow);
        pushPrevious->setObjectName(QStringLiteral("pushPrevious"));
        pushPrevious->setGeometry(QRect(30, 460, 141, 41));
        QFont font1;
        font1.setFamily(QStringLiteral("Lucida Handwriting"));
        font1.setPointSize(12);
        pushPrevious->setFont(font1);
        pushPrevious->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        pushNext = new QPushButton(LexiqueWindow);
        pushNext->setObjectName(QStringLiteral("pushNext"));
        pushNext->setGeometry(QRect(580, 460, 141, 41));
        pushNext->setFont(font1);
        pushNext->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/nouvelle_partie.jpg);"));
        labelImage = new QLabel(LexiqueWindow);
        labelImage->setObjectName(QStringLiteral("labelImage"));
        labelImage->setEnabled(true);
        labelImage->setGeometry(QRect(10, 90, 350, 281));
        labelImage->setFont(font1);
        label = new QLabel(LexiqueWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 761, 521));
        label->setStyleSheet(QStringLiteral("background-image: url(:/fond/images/rules/font.jpg);"));
        labelText = new QLabel(LexiqueWindow);
        labelText->setObjectName(QStringLiteral("labelText"));
        labelText->setEnabled(true);
        labelText->setGeometry(QRect(370, 90, 371, 331));
        labelText->setFont(font1);
        labelText->setStyleSheet(QStringLiteral("background-image: url(:/fond/Bouton);"));
        labelText->setWordWrap(true);
        labelText->setMargin(10);
        label->raise();
        labelNameLexique->raise();
        pushPrevious->raise();
        pushNext->raise();
        labelImage->raise();
        labelText->raise();

        retranslateUi(LexiqueWindow);

        QMetaObject::connectSlotsByName(LexiqueWindow);
    } // setupUi

    void retranslateUi(QDialog *LexiqueWindow)
    {
        LexiqueWindow->setWindowTitle(QApplication::translate("LexiqueWindow", "WarCpp - Lexique", 0));
        labelNameLexique->setText(QApplication::translate("LexiqueWindow", "Name Lexique", 0));
        pushPrevious->setText(QApplication::translate("LexiqueWindow", "Pr\303\251c\303\251dent", 0));
        pushNext->setText(QApplication::translate("LexiqueWindow", "Suivant", 0));
        labelImage->setText(QString());
        label->setText(QString());
        labelText->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LexiqueWindow: public Ui_LexiqueWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEXIQUE_H
