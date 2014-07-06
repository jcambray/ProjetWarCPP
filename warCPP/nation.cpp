#include "nation.h"

Nation::Nation()
{
    name = QLatin1String("");
    bonus = 0;
    token = 0;
}


Nation::Nation(QString nom, int bon, int tok)
{
    name = nom;
    bonus = bon;
    token = tok;
}

Nation::Nation(const Nation &n)
{
    name = n.name;
    bonus = n.bonus;
    token = n.token;
}

void Nation::setName(QString nameNat)
{
    name = nameNat;
}

void Nation::setBonus(int bonusNat)
{
    bonus=bonusNat;
}

void Nation::setToken(int tokenNat)
{
    token=tokenNat;
}

QString Nation::getName()
{
    return name;
}

int Nation::getBonus()
{
    return bonus;
}

int Nation::getToken()
{
    return token;
}
