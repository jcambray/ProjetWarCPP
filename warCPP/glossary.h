#ifndef GLOSSARY_H
#define GLOSSARY_H
#include <QStringBuilder>
#include <QtGui>
#include <QtXml>
#include <QWidget>


class Glossary
{
private :
    QString name;

public:
    Glossary();
    Glossary(Glossary &glossary);
    Glossary(QString newName);
    ~Glossary();
    void print();
    void setName(QString newName);
    QString getName();
};

#endif // GLOSSARY_H
