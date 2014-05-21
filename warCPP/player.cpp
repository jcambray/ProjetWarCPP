#include "player.h"

player::player()
{
}

player::player(const player & p)
{
   numeroOrdre = p.numeroOrdre;
   token = p.token;
   score = p.score;
   name = p.name;
   nation = p.nation;
   power = p.power;
}

bool player::operator <(const player &p)
{
    return (numeroOrdre < p.numeroOrdre) ? true : false;
}
