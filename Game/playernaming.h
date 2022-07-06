#ifndef PLAYERNAMING_H
#define PLAYERNAMING_H


#include <QDialog>
#include "Players.h"
#include "QVector"

namespace Ui {
class PlayerNaming;
}

class PlayerNaming : public QDialog
{
    Q_OBJECT

public:
    static int cnt;
    static short int playerCnt;
    static QVector<Players> p;
    explicit PlayerNaming(QWidget *parent = nullptr);
    ~PlayerNaming();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:

    short int prevPCnt = 0;
    Ui::PlayerNaming *ui;


};

#endif // PLAYERNAMING_H
