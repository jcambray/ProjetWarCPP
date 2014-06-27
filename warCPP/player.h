#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include "power.h"
#include "nation.h"

class player
{
public:
    player();
    player(int numOrdre,QString _name, Nation *nation,Power *power);
    player(const player &); 
    bool operator <(const player &);
    Nation getNation();
    Power getPower();
    int getToken();
    int getScore();
    void setNation(Nation &nation);
    void setPower(Power &power);
    void setToken(int t);
    void setScore(int s);


private:

    int numeroOrdre,token,score;
    QString name;
    Nation *nat;
    Power *pow;


};

#endif // PLAYER_H
