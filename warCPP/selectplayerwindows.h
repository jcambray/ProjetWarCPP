#ifndef SELECTPLAYERWINDOWS_H
#define SELECTPLAYERWINDOWS_H

#include <QDialog>

namespace Ui {
class SelectPlayerWindows;
}

class SelectPlayerWindows : public QDialog
{
    Q_OBJECT

public:
    explicit SelectPlayerWindows(QWidget *parent = 0);
    void enableLineEdit2();
    ~SelectPlayerWindows();
signals:

   void ButtonCommencer(QString,QString,int);

private slots:
    void on_pushButtonCommencer_clicked();

private:
    Ui::SelectPlayerWindows *ui;
};

#endif // SELECTPLAYERWINDOWS_H
