#ifndef SELECTNATIONPOWERWINDOWS_H
#define SELECTNATIONPOWERWINDOWS_H

#include <QDialog>
#include <QtWidgets>
#include <QString>
#include <QDateTime>


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

private slots:
    void on_listView_doubleClicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::SelectNationPowerWindows *ui;
    QStringListModel *modele;
    QList <QString> Nation;
    QList <QString> Power;
    QList <QString> Combination;
    bool debutGame;
};

#endif // SELECTNATIONPOWERWINDOWS_H
