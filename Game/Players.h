#ifndef PLAYERS_H
#define PLAYERS_H
#include <QString>
#include <QColor>
#include <QVector>


#include "PlayerSlot.h"

enum status {NO , YES};

class Players
{
public:
    QString name = NULL;
    status InGame = NO;
    QVector<int> Slots;
    int propertycnt = 0;
    int slotindex = 0;
    int money = 1500;
    int x = 720;
    int y = 535;
};

#endif // PLAYERS_H
