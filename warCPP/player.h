#ifndef PLAYER_H
#define PLAYER_H
#include <QString>

class player
{
public:
    player();
    player(int numOrdre,QString _name, QString nation,QString power);
    player(const player &); 
    bool operator <(const player &);
    int getToken();
    int getScore();
    void setToken(int t);
    void setScore(int s);


private:

    int numeroOrdre,token,score;
    QString name,nation,power;

};

#endif // PLAYER_H
