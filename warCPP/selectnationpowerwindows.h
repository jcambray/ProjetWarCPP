#ifndef SELECTNATIONPOWERWINDOWS_H
#define SELECTNATIONPOWERWINDOWS_H

#include <QDialog>
#include <QtWidgets>
#include <QString>
#include <QDateTime>
#include <QModelIndex>
#include "glossary.h"



namespace Ui {
class SelectNationPowerWindows;
}

class SelectNationPowerWindows : public QDialog
{
    Q_OBJECT

public:
    explicit SelectNationPowerWindows(QWidget *parent = 0);
    ~SelectNationPowerWindows();
    void prepareSelectNationPower(QString Joueur);
    void randomSelectionNationPower();
    void setDebutGame(bool val);

signals:
    void createJoueur(QString,QString,QString);
    void retour();
    void UpJoueur(QString,QString,QString);

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushChoisir_clicked();

private:
    Ui::SelectNationPowerWindows *ui;
    QStringListModel *modele;
    Glossary * lexique;
    QList <QString> Nation;
    QList <QString> Power;
    QList <QString> Combination;
    QString namejoueur;
    bool debutGame;
};

#endif // SELECTNATIONPOWERWINDOWS_H
