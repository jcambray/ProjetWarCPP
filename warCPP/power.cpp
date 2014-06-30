#include "power.h"

Power::Power()
{
    name = "";
    bonus = "";
    token = "";
}

Power::Power(const Power &p)
{
    name = p.name;
    bonus = p.bonus;
    type = p.token;
}

Power::Power(QString _name,int _bonus,int _token)
{
    name = _name;
    bonus = _bonus;
    token = _token;
}

QString Power::getName()
{
    return name;
}

int Power::getBonus()
{
    return bonus;
}

int Power::getToken()
{
    return token;
}


