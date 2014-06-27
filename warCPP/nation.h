#ifndef NATION_H
#define NATION_H
#include <QString>

class Nation
{
public:
    Nation();
    Nation(QString,int,int);
    Nation(const Nation &);

private:

    QString name;
    int bonus, token;
};

#endif // NATION_H
