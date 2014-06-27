#ifndef POWER_H
#define POWER_H
#include <QString>

class Power
{
public:
    Power();
<<<<<<< HEAD
    Power(const Power &);
    Power(QString,int,int);
    QString getName();
    int getBonus();
    int getType();
    int type;


private:

    QString name;
    int bonus,token;
=======

private:
    QString name;
    int bonus;
    int nbToken;

>>>>>>> f280cad727cc927957c86216913252c7260f2ae0
};

#endif // POWER_H
