#include "player.h"

player::player()
{
    name = QLatin1String("player");
    nat = new Nation();
    pow = new Power();
    token =0;
    score =0;
    numeroOrdre=0;
}

player::player(int numOrdre,QString _name, Nation *nation,Power *power)
{
    name = _name;
    numeroOrdre = numOrdre;
    nat = nation;
    pow = power;
}

player::player(const player & p)
{
   numeroOrdre = p.numeroOrdre;
   token = p.token;
   score = p.score;
   name = p.name;
   nat = p.nat;
   pow = p.pow;
}

bool player::operator <(const player &p)
{
    return (numeroOrdre < p.numeroOrdre) ? true : false;
}

Nation * player::getNation(){
    return nat;
}

Power * player::getPower(){
    return pow;
}

int player::getToken(){
    return token;
}

int player::getScore(){
    return score;
}

void player::setNation(Nation * nation)
{
    nat = nation;
}

void player::setPower(Power * power){
    pow = power;
}

void player::setToken(int t){
    token=t;
}

void player::setScore(int s){
    score=s;
}
