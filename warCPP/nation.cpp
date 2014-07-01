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
