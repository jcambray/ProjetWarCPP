#include "nation.h"

Nation::Nation()
{
    name = "";
    bonus = "";
    token = "";
}


Nation::Nation(QString nom, int bon, int tok)
{
    name = nom;
    bonus = bon;
    token = tok;
}

Power::Power(const Nation &n)
{
    name = n.name;
    bonus = n.bonus;
    token = n.token;
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
