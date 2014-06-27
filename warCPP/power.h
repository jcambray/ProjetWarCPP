#ifndef POWER_H
#define POWER_H
#include <QString>

class Power
{
public:
    Power();

    Power(const Power &);
    Power(QString,int,int);
    QString getName();
    int getBonus();
    int getType();
    int type;


private:

    QString name;
    int bonus,token;
};

#endif // POWER_H
