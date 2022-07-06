#include "buy.h"
#include "ui_buy.h"
#include "board.h"


Buy::Buy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Buy)
{
    ui->setupUi(this);
    ui->Name->setText(Board::sendname);
    ui->Rent->setNum(Board::sendrent);
    ui->Price->setNum(Board::sendprice);
}

Buy::~Buy()
{
    delete ui;
}

void Buy::on_pushButton_clicked()
{
    Board::sLOT[Board::player[Board::turn].slotindex].buy = OFF;
    Board::player[Board::turn].Slots.push_back(Board::player[Board::turn].slotindex);
    Board::player[Board::turn].propertycnt++;
    Board::player[Board::turn].money -= Board::sLOT[Board::player[Board::turn].slotindex].cost;
    close();
}

