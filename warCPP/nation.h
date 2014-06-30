#ifndef NATION_H
#define NATION_H
#include <QString>

class Nation
{
public:
    Nation();
    Nation(QString,int,int);
    Nation(const Nation &);
    QString getName();
    int getBonus();
    int getToken();

private:

    QString name;
    int bonus, token;
};

#endif // NATION_H
