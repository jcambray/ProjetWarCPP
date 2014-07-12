#ifndef LEXIQUEWINDOW_H
#define LEXIQUEWINDOW_H

#include <QDialog>
#include <QWidget>
#include <QString>
#include <QPushButton>

namespace Ui {
class LexiqueWindow;
}

class Glossary;

class LexiqueWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LexiqueWindow(QWidget *parent = 0);
    ~LexiqueWindow();
    void setLexique(QList <QString> _lexique);
    void setNameLexique(QString _nameLexique);

private slots:
    void on_pushNext_clicked();
    void on_pushPrevious_clicked();

private:
    Ui::LexiqueWindow *ui;
    QList <QString> lexique;
    QString nameLexique;
    int currentI;
    void load();
};

#endif // LEXIQUEWINDOW_H
