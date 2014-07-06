#include "selectplayerwindows.h"
#include "ui_selectplayerwindows.h"

SelectPlayerWindows::SelectPlayerWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectPlayerWindows)
{
    ui->setupUi(this);
}

SelectPlayerWindows::~SelectPlayerWindows()
{
    delete ui;
}
void SelectPlayerWindows::enableLineEdit2()
{
    ui->lineEdit_2->setEnabled(true);
    ui->lineEdit_2->setText(QLatin1String(""));
}

void SelectPlayerWindows::on_pushButtonCommencer_clicked()
{
    QString NameJ1 = ui->lineEdit->text();
    QString NameJ2 = ui->lineEdit_2->text();

    if(!(NameJ1.isEmpty() || NameJ2.isEmpty()))
    {
        if(ui->radioButtonJ1->isChecked())
        {
            emit ButtonCommencer(NameJ1,NameJ2);
        }
        else if(ui->radioButtonJ2->isChecked())
        {
            emit ButtonCommencer(NameJ2,NameJ1);
        }else
        {
            QMessageBox::warning(
                this,
                tr("Attention"),
                tr("Vous avez oublié de choisir le joueur qui commence le premier !") );
        }
    }else
    {
        QMessageBox::warning(
            this,
            tr("Attention"),
            tr("Vous avez oublié de saisir le nom d'un ou des joueurs !") );
    }
}
