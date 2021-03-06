#include "power.h"

Power::Power()
{
    name = QLatin1String("");
    bonus = 0;
    token = 0;
}

Power::Power(const Power &p)
{
    name = p.name;
    bonus = p.bonus;
    token = p.token;
}

Power::Power(QString _name,int _bonus,int _token)
{
    name = _name;
    bonus = _bonus;
    token = _token;
}

void Power::setName(QString namePow)
{
    name=namePow;
}

void Power::setBonus(int bonusPow)
{
    bonus=bonusPow;
}

void Power::setToken(int tokenPow)
{
    token=tokenPow;
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


