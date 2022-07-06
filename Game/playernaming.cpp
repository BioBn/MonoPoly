#include "playernaming.h"
#include "ui_playernaming.h"
#include "getname.h"
#include "board.h"

int PlayerNaming::cnt = 0;
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
    cnt++;
}

void PlayerNaming::on_pushButton_2_clicked()
{
    p.resize(cnt);
   if(prevPCnt > 1)
   {
    Board PNwindow;
    hide();
    PNwindow.setModal(true);
    PNwindow.exec();
   }
}
