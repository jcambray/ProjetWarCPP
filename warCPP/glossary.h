#ifndef GLOSSARY_H
#define GLOSSARY_H
#include <QStringBuilder>
#include <QtGui>
#include <QtXml>
#include <QWidget>


class Glossary
{
private :
    const QString name = QLatin1String("lex");
    const QString path = QLatin1String("../GitHub/ProjetWarCPP/warCPP/lexique.xml");
    QList <QString> areaList, nationList, powerList, rulesList;


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
    QList <QString> getAreas();
    QList <QString> getNations();
    QList <QString> getPowers();
    QList <QString> getRules();
};

#endif // GLOSSARY_H
