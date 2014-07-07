#include "selectnationpowerwindows.h"
#include "ui_selectnationpowerwindows.h"

SelectNationPowerWindows::SelectNationPowerWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectNationPowerWindows)
{
    lexique = new Glossary();
    debutGame = true;
    namejoueur = tr("");
    ui->setupUi(this);
}

SelectNationPowerWindows::~SelectNationPowerWindows()
{
    delete ui;
}

void SelectNationPowerWindows::prepareSelectNationPower(QString Joueur)
{
    if(namejoueur.isEmpty())
    {
        randomSelectionNationPower();

    }
    namejoueur = Joueur;
    ui->labelJoueur->setText(Joueur);

    modele = new QStringListModel(Combination);
    ui->listView->setModel(modele);

}

void SelectNationPowerWindows::on_listView_doubleClicked(const QModelIndex &index)
{

    QItemSelectionModel *selection = ui->listView->selectionModel();
    QModelIndex indexElementSelectionne = selection->currentIndex();
    QVariant elementSelectionne = modele->data(indexElementSelectionne, Qt::DisplayRole);
    QString choix = elementSelectionne.toString();

    QStringList combi = choix.split(tr(" ; "));
    QString sNation = combi[0];
    QString sPower = combi[1];

    QStringList listTmp;
    QList <QString> listNation = lexique->getNations();
    QList <QString> listPower = lexique->getPowers();
    QList <QString> listRules = lexique->getRules();

    for(int i =0; i<listNation.size();i++)
    {
        listTmp = listNation[i].split(tr(":"));
        if(listTmp[0]==sNation)
        {
            sNation = listNation[i];
        }
        listTmp.clear();
    }

    for(int i =0; i<listPower.size();i++)
    {
        listTmp = listPower[i].split(tr(":"));
        if(listTmp[0]==sPower)
        {
            sPower = listPower[i];
        }
        listTmp.clear();
    }
    ui->labelCombi->setText(sNation+tr(" ")+sPower);
    //ui->labelImage->setPixmap(QPixmap(tr("icone.png")));

}

void SelectNationPowerWindows::randomSelectionNationPower()
{
    int nbAlea = 0;
    bool alreadyPush;
    int y =0;
    Nation.clear();
    Power.clear();
    Nation << tr("Amazones") << tr("Humains") << tr("Squelettes") << tr("Hommes-rats");
    Power << tr("Pirates") << tr("Et leur Dragon") << tr("Bucherons") << tr("Marchands");


    qsrand(QDateTime::currentDateTime().toTime_t());
    nbAlea = qrand()%Nation.size();
    Combination.push_back(Nation[nbAlea]);

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
            Combination.push_back(Nation[nbAlea]);
        }
    }

    for(int v =0; v<Combination.size();v++)
    {
        Combination[v] += tr(" ; ")+Power[v];
    }
}

void SelectNationPowerWindows::on_pushButton_2_clicked()
{
    namejoueur = tr("");
    Combination.clear();
    delete modele;
}

void SelectNationPowerWindows::on_pushChoisir_clicked()
{

    QItemSelectionModel *selection2 = ui->listView->selectionModel();
    QModelIndex indexElementSelectionne2 = selection2->currentIndex();
    QVariant elementSelectionne2 = modele->data(indexElementSelectionne2, Qt::DisplayRole);
    QString choix2 = elementSelectionne2.toString();
    QStringList combi2 = choix2.split(tr(" ; "));
    QString sNation2 = combi2[0];
    QString sPower2 = combi2[1];

    switch( QMessageBox::question(
                    this,
                    tr("Choix de la combinaison"),
                    tr("Etes vou sur de vouloir choisir cette combinaison ?"),

                    QMessageBox::Yes |
                    QMessageBox::No |
                    QMessageBox::Cancel,
                    QMessageBox::Cancel ) )
        {
          case QMessageBox::Yes:
            qDebug( "yes" );
                if(debutGame)
                {
                   Combination.removeAt(indexElementSelectionne2.row());
                   delete modele;
                   ui->pushButton_2->setDisabled(true);
                   emit createJoueur(namejoueur,sNation2,sPower2);
                }
                else
                {
                   //emit UpJoueur(namejoueur,sNation,sNation);
                }
            break;
          case QMessageBox::No:
                qDebug( "no" );
            break;
          case QMessageBox::Cancel:
            qDebug( "cancel" );
            break;
          default:
            qDebug( "close" );
            break;
        }

}
