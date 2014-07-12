#include "glossary.h"
#include "lexiquewindow.h"
#include <QtXml>
#include <qfile.h>
#include <qdom.h>
#include <iostream>
#include <QtDebug>
#include <fstream>
#include <string>
#include <QMessageBox>

using namespace std;

Glossary::Glossary(){

    name = QLatin1String("lex");
    path = QLatin1String("../ProjetWarCPP/warCPP/lexique.xml");
    lexiqueWindow = new LexiqueWindow();
    QDomDocument dom(name);
    QFile xml_doc(path);

    if(!xml_doc.open(QIODevice::ReadOnly))
    {
        qDebug() <<"Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé";
        return;
    }
    if (!dom.setContent(&xml_doc))
    {
     xml_doc.close();
        qDebug() <<"Le document XML n'a pas pu être attribué à l'objet QDomDocument.";
     return;
    }
    QDomElement dom_element = dom.documentElement();
    QDomNode noeud = dom_element.firstChild();
    while(!noeud.isNull())
    {
        QDomElement e = noeud.toElement();

        if(QLatin1String("area") == e.tagName())
            areaList.append(e.attribute(QLatin1String("value")));
        else if(QLatin1String("nation") == e.tagName())
            nationList.append(e.attribute(QLatin1String("value")));
        else if(QLatin1String("power") == e.tagName())
            powerList.append(e.attribute(QLatin1String("value")));
        else if(QLatin1String("rules") == e.tagName())
            rulesList.append(e.attribute(QLatin1String("value")));

        noeud = noeud.nextSibling();

    }
}

Glossary::Glossary(Glossary &glossary){
    areaList = glossary.getAreas();
    nationList = glossary.getNations();
    powerList = glossary.getPowers();
    rulesList = glossary.getRules();
}


Glossary::~Glossary(){

}

void Glossary::print(){

    QDomDocument dom(name);
    QFile xml_doc(path);

    if(!xml_doc.open(QIODevice::ReadOnly))
    {
        qDebug() <<"Le document XML n'a pas pu être ouvert. Vérifiez que le nom est le bon et que le document est bien placé";
        return;
    }
    if (!dom.setContent(&xml_doc))
    {
     xml_doc.close();
        qDebug() <<"Le document XML n'a pas pu être attribué à l'objet QDomDocument.";
     return;
    }
    QDomElement dom_element = dom.documentElement();
    QDomNode noeud = dom_element.firstChild();
    while(!noeud.isNull())
    {
        QDomElement e = noeud.toElement();

        if(name == e.tagName())
            qDebug() <<e.attribute(QLatin1String("value"));

        noeud = noeud.nextSibling();

    }



}

void Glossary::getMSGArea(){
    QMessageBox box;
    box.setIcon(QMessageBox::Information);
    QString msg = QLatin1String("");
    int i = 0;
    int length = areaList.length();

    while (i<length){
        msg += areaList.at(i);
        msg += QLatin1String("\n");
        i++;
    }

    box.setText(msg);
    box.exec();
}

void Glossary::getMSGNation(){
    QMessageBox box;
    box.setIcon(QMessageBox::Information);
    QString msg = QLatin1String("");
    int i = 0;
    int length = nationList.length();

    while (i<length){
        msg += nationList.at(i);
        msg += QLatin1String("\n");
        i++;
    }

    box.setText(msg);
    box.exec();
}

void Glossary::getMSGPower(){
    QMessageBox box;
    box.setIcon(QMessageBox::Information);
    QString msg = QLatin1String("");
    int i = 0;
    int length = powerList.length();

    while (i<length){
        msg += powerList.at(i);
        msg += QLatin1String("\n");
        i++;
    }

    box.setText(msg);
    box.exec();
}

void Glossary::getMSGRules(){
    QMessageBox box;
    box.setIcon(QMessageBox::Information);
    QString msg = QLatin1String("");
    int i = 0;
    int length = rulesList.length();

    while (i<length){
        msg += rulesList.at(i);
        msg += QLatin1String("\n");
        i++;
    }

    box.setText(msg);
    box.exec();
}

void Glossary::getUIArea(){
    lexiqueWindow->init();
    lexiqueWindow->setLexique(areaList);
    lexiqueWindow->setNameLexique(QLatin1String("Regions"));
    lexiqueWindow->show();
}

void Glossary::getUINation(){
    lexiqueWindow->init();
    lexiqueWindow->setLexique(nationList);
    lexiqueWindow->setNameLexique(QLatin1String("Peuples"));
    lexiqueWindow->show();
}

void Glossary::getUIPower(){
    lexiqueWindow->init();
    lexiqueWindow->setLexique(powerList);
    lexiqueWindow->setNameLexique(QLatin1String("Pouvoirs"));
    lexiqueWindow->show();
}

void Glossary::getUIRules(){
    lexiqueWindow->setLexique(rulesList);
    lexiqueWindow->setNameLexique(QLatin1String("Regles"));
    lexiqueWindow->show();
}

QList <QString> Glossary::getAreas(){
    return areaList;
}

QList <QString> Glossary::getNations(){
    return nationList;
}

QList <QString> Glossary::getPowers(){
    return powerList;
}

QList <QString> Glossary::getRules(){
    return rulesList;
}
