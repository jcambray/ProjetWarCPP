#include "selectplayerwindows.h"
#include "ui_selectplayerwindows.h"

SelectPlayerWindows::SelectPlayerWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectPlayerWindows)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButtonCommencer,SIGNAL(clicked()),this,SLOT(on_pushButtonCommencer_clicked()));
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
    int first =0;
    QString NameJ1 = ui->lineEdit->text();
    QString NameJ2 = ui->lineEdit_2->text();
    if(ui->radioButtonJ1->isChecked())
    {
        first = 1;
    }
    if(ui->radioButtonJ2->isChecked())
    {
        first = 2;
    }

    emit ButtonCommencer(NameJ1,NameJ2,first);
}
