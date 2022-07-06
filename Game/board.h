#ifndef BOARD_H
#define BOARD_H

#include <Players.h>
#include <qcolor.h>
#include <QPalette>
#include "QLabel"
#include <qpalette.h>
#include <QDialog>
#include "Slot.h"

namespace Ui {
class Board;
}

class Board : public QDialog , public QColor , QPalette
{
    Q_OBJECT

public:
    static Slot sLOT[40];
    static int turn ;
    explicit Board(QWidget *parent = nullptr);
    ~Board();
    static QVector<Players> player;
    static QString sendname;
    static int sendprice;
    static int sendrent;

private slots:
    void on_pushButton_clicked();

private:
    int dice1 , dice2;

    QVector<QLabel *> labelHold;
    QVector<QLabel *> labelMain;

    const QColor c[8] = {Qt::red , Qt::blue , Qt::green , Qt::yellow , Qt::cyan , QColor::fromRgb(222 , 118 , 255) , QColor::fromRgb(255 , 140 , 60) , Qt::black};

    Ui::Board *ui;
};

#endif // BOARD_H
