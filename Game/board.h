#ifndef BOARD_H
#define BOARD_H

#include <Players.h>
#include <qcolor.h>
#include <QPalette>
#include "QLabel"
#include <qpalette.h>
#include <QDialog>

namespace Ui {
class Board;
}

class Board : public QDialog , public QColor , QPalette
{
    Q_OBJECT

public:
    explicit Board(QWidget *parent = nullptr);
    ~Board();

private:
    int sex;
    QVector<QLabel *> labelHold;
    QVector<QLabel *> labelMain;
    QVector<Players> player;
    const QColor c[8] = {Qt::red , Qt::blue , Qt::green , Qt::yellow , Qt::cyan , QColor::fromRgb(222 , 118 , 255) , QColor::fromRgb(255 , 140 , 60) , Qt::black};

    Ui::Board *ui;
};

#endif // BOARD_H
