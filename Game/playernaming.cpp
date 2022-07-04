#include "playernaming.h"
#include "ui_playernaming.h"

PlayerNaming::PlayerNaming(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerNaming)
{
    ui->setupUi(this);
}

PlayerNaming::~PlayerNaming()
{
    delete ui;
}
