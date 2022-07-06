#include "getname.h"
#include "ui_getname.h"
#include "playernaming.h"

GetName::GetName(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetName)
{
    ui->setupUi(this);
}

GetName::~GetName()
{
    delete ui;
}

void GetName::on_pushButton_clicked()
{
    if(PlayerNaming::playerCnt < 8)
    {
        PlayerNaming::p[PlayerNaming::playerCnt].name = ui->lineEdit->text();
        PlayerNaming::playerCnt++;
        close();
    }
}
