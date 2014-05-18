/********************************************************************************
** Form generated from reading UI file 'converterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTERWINDOW_H
#define UI_CONVERTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QHBoxLayout *horizontalLayout;
    QPushButton *addbutton;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(576, 264);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QStringLiteral("treeView"));
        treeView->setRootIsDecorated(false);
        treeView->setUniformRowHeights(true);
        treeView->setItemsExpandable(false);
        treeView->header()->setStretchLastSection(false);

        gridLayout->addWidget(treeView, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        addbutton = new QPushButton(centralWidget);
        addbutton->setObjectName(QStringLiteral("addbutton"));

        horizontalLayout->addWidget(addbutton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setEnabled(false);
        saveButton->setText(QStringLiteral("Save all as v0.8.0 compatible"));

        horizontalLayout->addWidget(saveButton);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tiled Automapping Rule Files Converter", 0));
        addbutton->setText(QApplication::translate("MainWindow", "Add new Automapping rules", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTERWINDOW_H
