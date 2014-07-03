#include "selectnationpowerwindows.h"
#include "ui_selectnationpowerwindows.h"

SelectNationPowerWindows::SelectNationPowerWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectNationPowerWindows)
{
    debutGame = true;
    ui->setupUi(this);
}

SelectNationPowerWindows::~SelectNationPowerWindows()
{
    delete ui;
}

void SelectNationPowerWindows::prepareSelectNationPower(QString Joueur)
{
    ui->labelJoueur->setText(Joueur);

    if(debutGame)
    {
        randomSelectionNationPower();
    }
    QStringList listePays;
    listePays << tr("France") << tr("Espagne") << tr("Italie") << tr("Portugal") << tr("Suisse");
    modele = new QStringListModel(listePays);
    ui->listView->setModel(modele);

}

void SelectNationPowerWindows::on_listView_doubleClicked(const QModelIndex &index)
{
    QMessageBox::warning(
        this,
        tr("Attention"),
        tr("Vous avez oublié de choisir le joueur qui commence le premier !") );

}

void SelectNationPowerWindows::on_pushButton_clicked()
{

}

void SelectNationPowerWindows::randomSelectionNationPower()
{
    int nbAlea = 0;
    Nation << tr("Amazones") << tr("Humains") << tr("Squelettes") << tr("Hommes-rats");
    Power << tr("Pirates") << tr("Et leur Dragon") << tr("Bucherons") << tr("Marchands");

    for(int i = 0; i < Nation.size(); i++)
    {
        qsrand(QDateTime::currentDateTime().toTime_t());
        nbAlea = qrand()%4;

        Combination.push_back(Nation[nbAlea]);
    }

    /*QString str = QString::number(nbAlea);
    QMessageBox::information(this,tr("Attention"),str);*/

}
