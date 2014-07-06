#ifndef POWER_H
#define POWER_H
#include <QString>

class Power
{
public:
    Power();
    Power(const Power &);
    Power(QString,int,int);
    void setName(QString namePow);
    void setBonus(int bonusPow);
    void setToken(int tokenPow);
    QString getName();
    int getBonus();
    int getToken();

private:

    QString name;
    int bonus,token;
};

#endif // POWER_H
