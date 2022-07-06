#include "board.h"
#include "playernaming.h"
#include "qpalette.h"
#include "ui_board.h"

Board::Board(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Board)
{
    ui->setupUi(this);
    QPixmap board("E:/Noobs/Qt/Repository/MonoPoly/Game/map.jpg"); //map
    ui->label->setPixmap(board);
    ui->label->resize(board.size());

    ui->TL1->hide();
    ui->TL2->hide();
    ui->TL3->hide();
    ui->TL4->hide();
    ui->TL5->hide();
    ui->TL6->hide();
    ui->TL7->hide();
    ui->TL8->hide();

    labelHold.push_back(ui->TL1);
    labelHold.push_back(ui->TL2);
    labelHold.push_back(ui->TL3);
    labelHold.push_back(ui->TL4);
    labelHold.push_back(ui->TL5);
    labelHold.push_back(ui->TL6);
    labelHold.push_back(ui->TL7);
    labelHold.push_back(ui->TL8);

    resize(1200 , 600);         // resizing screen

    player = PlayerNaming::p;
    player.shrink_to_fit();



    for (int i = 0 ; i < player.size() ; i++)   //player labels
    {
        labelMain.push_back(labelHold.at(i));

        player[i].color = c[i];

        labelMain[i]->setGeometry(720 , 535 , labelMain[i]->width() , labelMain[i]->height());
        labelMain[i]->show();

    }
    labelMain.shrink_to_fit();
}

Board::~Board()
{
    delete ui;
}
