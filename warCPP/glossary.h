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
    const QString path = QLatin1String("../ProjetWarCPP/warCPP/lexique.xml");
    QList <QString> areaList, nationList, powerList, rulesList;
    QList <QString> getAreas();
    QList <QString> getNations();
    QList <QString> getPowers();
    QList <QString> getRules();


public:
    Glossary();
    Glossary(Glossary &glossary);
    ~Glossary();
    void print();

};

#endif // GLOSSARY_H
