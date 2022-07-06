#ifndef SLOT_H
#define SLOT_H
#include <QString>


enum stats{OFF , ON};
class Slot
{
public:
    QString name;
    int x;
    int y;
    int rent;
    int cost;
    stats buy = OFF;
};

#endif // SLOT_H
