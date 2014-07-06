#ifndef NATION_H
#define NATION_H
#include <QString>

class Nation
{
public:
    Nation();
    Nation(QString,int,int);
    Nation(const Nation &);
    void setName(QString nameNat);
    void setBonus(int bonusNat);
    void setToken(int tokenNat);
    QString getName();
    int getBonus();
    int getToken();

private:

    QString name;
    int bonus, token;
};

#endif // NATION_H
