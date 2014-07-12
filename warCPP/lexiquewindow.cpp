#include "lexiquewindow.h"
#include "ui_Lexique.h"
//#include "ui_€"


LexiqueWindow::LexiqueWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LexiqueWindow)
{
    currentI = 0;
    ui->setupUi(this);
}


LexiqueWindow::~LexiqueWindow()
{
    delete ui;
}

void LexiqueWindow::on_pushNext_clicked()
{
    if(currentI<lexique.length())
    {
        currentI++;
        load();
    }
}
void LexiqueWindow::on_pushPrevious_clicked()
{
    if(currentI>0)
    {
        currentI--;
        load();
    }
}

void LexiqueWindow::load(){
    ui->labelText->setText(nameLexique);
    ui->labelText->setText(lexique.at(currentI));
    //ui->labelPicture
    //ui->labelImage->setPixmap(QPixmap(tr(":/fond/images/nation/")+listTmp[0]+tr(".jpg")))
}

void LexiqueWindow::setLexique(QList <QString> _lexique){
    lexique = _lexique;
}

void LexiqueWindow::setNameLexique(QString _nameLexique){
    nameLexique = _nameLexique;
}
