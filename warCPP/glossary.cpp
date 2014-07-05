#include "glossary.h"
#include <QtXml>
#include <qfile.h>
#include <qdom.h>
#include <iostream>
#include <QtDebug>
#include <fstream>
#include <string>

using namespace std;

Glossary::Glossary(){

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
