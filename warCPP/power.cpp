#include "power.h"

Power::Power()
{
}
<<<<<<< HEAD

Power::Power(QString _name,int _bonus,int _type)
{
    name = _name;
    bonus = _bonus;
    type = _type;
}

Power::Power(const Power &p)
{
    name = p.name;
    bonus = p.bonus;
    type = p.type;
}

int Power::getBonus()
{
    return bonus;
}

int Power::getType()
{
    return type;
}
=======
>>>>>>> f280cad727cc927957c86216913252c7260f2ae0
