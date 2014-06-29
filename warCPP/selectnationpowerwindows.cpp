#include "selectnationpowerwindows.h"
#include "ui_selectnationpowerwindows.h"

SelectNationPowerWindows::SelectNationPowerWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectNationPowerWindows)
{
    ui->setupUi(this);
}

SelectNationPowerWindows::~SelectNationPowerWindows()
{
    delete ui;
}
