#ifndef GLOSSARY_H
#define GLOSSARY_H
#include "lexiquewindow.h"
#include <QStringBuilder>
#include <QtGui>
#include <QtXml>
#include <QWidget>


class Glossary
{
private :
    QString name;
    QString path;
    QList <QString> areaList, nationList, powerList, rulesList;
    LexiqueWindow * lexiqueWindow;

public:
    Glossary();
    Glossary(Glossary &glossary);
    ~Glossary();
    void print();
    void getMSG(QList <QString> listLex);
    void getMSGArea();
    void getMSGNation();
    void getMSGPower();
    void getMSGRules();
    void getUIArea();
    void getUINation();
    void getUIPower();
    void getUIRules();
    QList <QString> getAreas();
    QList <QString> getNations();
    QList <QString> getPowers();
    QList <QString> getRules();
};

#endif // GLOSSARY_H
