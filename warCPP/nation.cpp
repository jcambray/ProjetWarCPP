#include "nation.h"

Nation::Nation()
{
}


Nation::Nation(QString nom, int bon, int tok)
{
    name = nom;
    bonus = bon;
    token = tok;
}

