#include "lexiquewindow.h"
#include "ui_Lexique.h"


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
    if(currentI<lexique.length()-1)
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

    QString pathPic = QLatin1String(":/fond/images/")+pathRes+QLatin1String("/")+QString::number(currentI)+QLatin1String(".jpg");
    ui->labelNameLexique->setText(nameLexique);
    ui->labelText->setText(lexique.at(currentI));
    ui->labelImage->setPixmap(QPixmap(pathPic));

}

void LexiqueWindow::init(){
    currentI = 0;
}

void LexiqueWindow::setLexique(QList <QString> _lexique){
    lexique = _lexique;
}

void LexiqueWindow::setNameLexique(QString _nameLexique){
    nameLexique = _nameLexique;
}

void LexiqueWindow::setPathRes(QString _pathRes){
    pathRes = _pathRes;
}
