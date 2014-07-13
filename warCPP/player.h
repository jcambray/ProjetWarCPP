#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include "power.h"
#include "nation.h"

class player
{
public:
    player();
    player(int declin,QString _name, Nation *nation,Power *power);
    player(const player &); 
    bool operator <(const player &);
    Nation * getNation();
    Power * getPower();
    QString getName();
    int getToken();
    int getScore();
    int getDeclin();
    void setNation(Nation * nation);
    void setPower(Power * power);
    void setToken(int t);
    void setScore(int s);
    void setDeclin(int d);
    Nation * nat;
    Power * pow;


private:

    int indiceDeclin,token,score;
    QString name;



};

#endif // PLAYER_H
