#ifndef SELECTNATIONPOWERWINDOWS_H
#define SELECTNATIONPOWERWINDOWS_H

#include <QDialog>

namespace Ui {
class SelectNationPowerWindows;
}

class SelectNationPowerWindows : public QDialog
{
    Q_OBJECT

public:
    explicit SelectNationPowerWindows(QWidget *parent = 0);
    ~SelectNationPowerWindows();

private:
    Ui::SelectNationPowerWindows *ui;
};

#endif // SELECTNATIONPOWERWINDOWS_H
