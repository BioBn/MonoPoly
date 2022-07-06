#ifndef PLAYERS_H
#define PLAYERS_H
#include <QString>
#include <QColor>

enum status {NO , YES};

class Players
{
public:
    QString name = NULL;
    QColor color;
    status InGame = NO;
};

#endif // PLAYERS_H
