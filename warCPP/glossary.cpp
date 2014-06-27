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
    name = QLatin1String("");
}

Glossary::Glossary(Glossary &glossary){
    name = glossary.getName();
}

Glossary::Glossary(QString newName){
    name = newName;
}


Glossary::~Glossary(){

}

void Glossary::print(){

    QDomDocument dom(QLatin1String("lex"));
    QFile xml_doc(QLatin1String("../warCPP/lexique.xml"));

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


void Glossary::setName(QString newName){
    name = newName;
}

QString Glossary::getName(){
    return name;
}
