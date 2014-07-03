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

    modele = new QStringListModel(Combination);
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
    bool alreadyPush;
    int y =0;
    Nation << tr("Amazones") << tr("Humains") << tr("Squelettes") << tr("Hommes-rats");
    Power << tr("Pirates") << tr("Et leur Dragon") << tr("Bucherons") << tr("Marchands");

    qsrand(QDateTime::currentDateTime().toTime_t());
    nbAlea = qrand()%Nation.size();
    Combination.push_back(Nation[nbAlea]+ tr(" ; ")+Power[0]);

    while(Combination.size() != Nation.size())
    {
        qsrand(QDateTime::currentDateTime().toTime_t());
        nbAlea = qrand()%Nation.size();

        alreadyPush = false;

        for(int i =0; i<Combination.size();i++)
        {
            if(Combination[i]==Nation[nbAlea])
            {
                alreadyPush = true;
            }
        }

        if(alreadyPush != true)
        {
            y++;
            Combination.push_back(Nation[nbAlea]+tr(" ; ")+Power[y]);
        }
    }
}
