#include "player.h"

player::player()
{
    name = QLatin1String("player");
    nat = new Nation();
    pow = new Power();
    token =0;
    score =0;
    indiceDeclin=0;
}

player::player(int declin,QString _name, Nation *nation,Power *power)
{
    name = _name;
    indiceDeclin = declin;
    nat = nation;
    pow = power;
}

player::player(const player & p)
{
   indiceDeclin = p.indiceDeclin;
   token = p.token;
   score = p.score;
   name = p.name;
   if(nat != NULL)
   {
       delete nat;
   }
   if(pow != NULL)
   {
       delete pow;
   }
   pow = p.pow;
   nat = p.nat;
}

bool player::operator <(const player &p)
{
    return (indiceDeclin < p.indiceDeclin) ? true : false;
}

QString player::getName()
{
    return name;
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
int player::getDeclin()
{
    return indiceDeclin;
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

void player::setDeclin(int d){
    indiceDeclin=d;
}

