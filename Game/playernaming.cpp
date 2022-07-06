#include "playernaming.h"
#include "ui_playernaming.h"
#include "getname.h"
#include "board.h"


QVector<Players> PlayerNaming::p;
short int PlayerNaming::playerCnt = 0;
PlayerNaming::PlayerNaming(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerNaming)
{
    ui->setupUi(this);
    p.resize(8);
}

PlayerNaming::~PlayerNaming()
{
    delete ui;
}

void PlayerNaming::on_pushButton_clicked()
{
    GetName GNwindow;
    GNwindow.setModal(true);
    GNwindow.exec();
    if(GNwindow.close() && prevPCnt != playerCnt)
    {
        ui->listWidget->addItem(p[prevPCnt].name);
        prevPCnt = playerCnt;
    }
}

void PlayerNaming::on_pushButton_2_clicked()
{
   if(prevPCnt > 1)
   {
    Board PNwindow;
    hide();
    PNwindow.setModal(true);
    PNwindow.exec();
   }
}
