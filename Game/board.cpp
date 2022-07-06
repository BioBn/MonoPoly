#include "board.h"
#include "playernaming.h"
#include "qpalette.h"
#include "ui_board.h"
#include "buy.h"
#include <time.h>
#include <stdlib.h>

int Board::turn = 0;
Slot Board::sLOT[40];
QString Board::sendname;
int Board::sendrent;
int Board::sendprice;
QVector<Players> Board::player;
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

    //intializing SLOTs

     sLOT[0].name = "GO";
     sLOT[0].x = 720;
     sLOT[0].y = 535;
     sLOT[0].buy = ON;
     sLOT[0].cost = 0;
     sLOT[0].rent = -200;

     sLOT[1].name = "M Avenue";
     sLOT[1].x = 640;
     sLOT[1].y = 535;
     sLOT[1].buy = ON;
     sLOT[1].cost = 60;
     sLOT[1].rent = 2;

     sLOT[2].name = "chest";
     sLOT[2].x = 570;
     sLOT[2].y = 535;
     sLOT[2].buy = OFF;
     sLOT[2].cost = 0;
     sLOT[2].rent = 0;

     sLOT[3].name = "B Avenue";
     sLOT[3].x = 520;
     sLOT[3].y = 535;
     sLOT[3].buy = ON;
     sLOT[3].cost = 60;
     sLOT[3].rent = 4;

     sLOT[4].name = "Income Tax";
     sLOT[4].x = 470;
     sLOT[4].y = 535;
     sLOT[4].buy = OFF;
     sLOT[4].cost = 0;
     sLOT[4].rent = 200;

     sLOT[5].name = "Reading Railroad";
     sLOT[5].x = 430;
     sLOT[5].y = 535;
     sLOT[5].buy = ON;
     sLOT[5].cost = 200;
     sLOT[5].rent = 25;

     sLOT[6].name = "O Avenue";
     sLOT[6].x = 380;
     sLOT[6].y = 535;
     sLOT[6].buy = ON;
     sLOT[6].cost = 100;
     sLOT[6].rent = 6;

     sLOT[7].name = "Chance";
     sLOT[7].x = 340;
     sLOT[7].y = 535;
     sLOT[7].buy = OFF;
     sLOT[7].cost = 0;
     sLOT[7].rent = 0;

     sLOT[8].name = "V Avenue";
     sLOT[8].x = 290;
     sLOT[8].y = 535;
     sLOT[8].buy = ON;
     sLOT[8].cost = 100;
     sLOT[8].rent = 6;

     sLOT[9].name = "C Avenue";
     sLOT[9].x = 235;
     sLOT[9].y = 535;
     sLOT[9].buy = ON;
     sLOT[9].cost = 120;
     sLOT[9].rent = 8;

     sLOT[10].name = "In j/jv";
     sLOT[10].x = 160;
     sLOT[10].y = 535;
     sLOT[10].buy = ON;
     sLOT[10].cost = 0;
     sLOT[10].rent = 0;

     sLOT[11].name = "St.c Place";
     sLOT[11].x = 160;
     sLOT[11].y = 480;
     sLOT[11].buy = ON;
     sLOT[11].cost = 140;
     sLOT[11].rent = 10;

     sLOT[12].name = "Electric company";
     sLOT[12].x = 160;
     sLOT[12].y = 440;
     sLOT[12].buy = ON;
     sLOT[12].cost = 150;

     sLOT[13].name = "S Avenue";
     sLOT[13].x = 160;
     sLOT[13].y = 400;
     sLOT[13].buy = ON;
     sLOT[13].cost = 140;
     sLOT[13].rent = 10;

     sLOT[14].name = "V Avenue";
     sLOT[14].x = 160;
     sLOT[14].y = 350;
     sLOT[14].buy = ON;
     sLOT[14].cost  = 160;
     sLOT[14].rent = 12;

     sLOT[15].name = "P railroad";
     sLOT[15].x = 160;
     sLOT[15].y = 310;
     sLOT[15].buy = ON;
     sLOT[15].cost = 200;
     sLOT[15].rent = 25;

     sLOT[16].name = "St.J Place";
     sLOT[16].x = 160;
     sLOT[16].y = 260;
     sLOT[16].buy = ON;
     sLOT[16].cost = 180;
     sLOT[16].rent = 14;

     sLOT[17].name = "Community chest";
     sLOT[17].x = 160;
     sLOT[17].y = 220;
     sLOT[17].buy = OFF;
     sLOT[17].cost = 0;
     sLOT[17].rent = 0;

     sLOT[18].name = "T Avenue";
     sLOT[18].x = 160;
     sLOT[18].y = 170;
     sLOT[18].buy = ON;
     sLOT[18].cost = 180;
     sLOT[18].rent = 14;

     sLOT[19].name = "NY Avenue";
     sLOT[19].x = 160;
     sLOT[19].y = 120;
     sLOT[19].buy = ON;
     sLOT[19].cost = 200;
     sLOT[19].rent = 16;

     sLOT[20].name = "Parking";
     sLOT[20].x = 160;
     sLOT[20].y = 60;
     sLOT[20].buy = OFF;
     sLOT[20].cost = 0;
     sLOT[20].rent = 0;

     sLOT[21].name = "K Avenue";
     sLOT[21].x = 235;
     sLOT[21].y = 60;
     sLOT[21].buy = ON;
     sLOT[21].cost = 220;
     sLOT[21].rent = 18;

     sLOT[22].name = "Chance";
     sLOT[22].x = 290;
     sLOT[22].y = 60;
     sLOT[22].buy = OFF;
     sLOT[22].cost = 0;
     sLOT[22].rent = 0;

     sLOT[23].name = "I Avenue";
     sLOT[23].x = 340;
     sLOT[23].y = 60;
     sLOT[23].buy = ON;
     sLOT[23].cost = 220;
     sLOT[23].rent = 18;

     sLOT[24].name = "II Avenue";
     sLOT[24].x = 380;
     sLOT[24].y = 60;
     sLOT[24].buy = ON;
     sLOT[24].cost = 240;
     sLOT[24].rent = 20;

     sLOT[25].name = "B&Q Railroad";
     sLOT[25].x = 430;
     sLOT[25].y = 60;
     sLOT[25].buy = ON;
     sLOT[25].cost = 200;
     sLOT[25].rent = 25;

     sLOT[26].name = "A Avenue";
     sLOT[26].x = 470;
     sLOT[26].y = 60;
     sLOT[26].buy = ON;
     sLOT[26].cost = 260;
     sLOT[26].rent = 22;

     sLOT[27].name = "V Avenue";
     sLOT[27].x = 520;
     sLOT[27].y = 60;
     sLOT[27].buy = ON;
     sLOT[27].cost = 260;
     sLOT[27].rent = 22;

     sLOT[28].name = "Water Works";
     sLOT[28].x = 570;
     sLOT[28].y = 60;
     sLOT[28].buy = ON;
     sLOT[28].cost = 150;

     sLOT[29].name = "M Gardens";
     sLOT[29].x = 640;
     sLOT[29].y = 60;
     sLOT[29].buy = ON;
     sLOT[29].cost = 280;
     sLOT[29].rent = 24;

     sLOT[30].name = "Jail";
     sLOT[30].x = 720;
     sLOT[30].y = 60;
     sLOT[30].buy = OFF;
     sLOT[30].cost = 0;
     sLOT[30].rent = 0;

     sLOT[31].name = "P Avenue";
     sLOT[31].x = 720;
     sLOT[31].y = 120;
     sLOT[31].buy = ON;
     sLOT[31].cost = 300;
     sLOT[31].rent = 26;

     sLOT[32].name = "NC Avenue";
     sLOT[32].x = 720;
     sLOT[32].y = 170;
     sLOT[32].buy = ON;
     sLOT[32].cost = 300;
     sLOT[32].rent = 26;

     sLOT[33].name = "Community chest";
     sLOT[33].x = 720;
     sLOT[33].y = 220;
     sLOT[33].buy = OFF;
     sLOT[33].cost = 0;
     sLOT[33].rent = 0;

     sLOT[34].name = "P Avenue";
     sLOT[34].x = 720;
     sLOT[34].y = 260;
     sLOT[34].buy = ON;
     sLOT[34].cost = 320;
     sLOT[34].rent = 28;

     sLOT[35].name = "Shortline";
     sLOT[35].x = 720;
     sLOT[35].y = 310;
     sLOT[35].buy = ON;
     sLOT[35].cost = 200;
     sLOT[35].rent = 25;

     sLOT[36].name = "Chance";
     sLOT[36].x = 720;
     sLOT[36].y = 350;
     sLOT[36].buy = OFF;
     sLOT[36].cost  = 0;
     sLOT[36].rent = 0;


     sLOT[37].name = "Park Place";
     sLOT[37].x = 720;
     sLOT[37].y = 400;
     sLOT[37].buy = ON;
     sLOT[37].cost = 350;
     sLOT[37].rent = 35;

     sLOT[38].name = "Luxury Task";
     sLOT[38].x = 720;
     sLOT[38].y = 440;
     sLOT[38].buy = OFF;
     sLOT[38].cost = 0;
     sLOT[38].rent = 100;

     sLOT[39].name = "Boardwalk";
     sLOT[39].x = 720;
     sLOT[39].y = 535;
     sLOT[39].buy = ON;
     sLOT[39].cost = 400;
     sLOT[39].rent = 50;

     //player labels
    for (int i = 0 ; i < player.size() ; i++)
    {
        labelMain.push_back(labelHold.at(i));


        labelMain[i]->setGeometry(sLOT[0].x , sLOT[0].y , labelMain[i]->width() , labelMain[i]->height());
        labelMain[i]->show();

    }
    labelMain.shrink_to_fit();
    ui->turn->setNum(turn + 1);


    labelHold.clear();
    labelHold.push_back(ui->n1);
    labelHold.push_back(ui->n2);
    labelHold.push_back(ui->n3);
    labelHold.push_back(ui->n4);
    labelHold.push_back(ui->n5);
    labelHold.push_back(ui->n6);
    labelHold.push_back(ui->n7);
    labelHold.push_back(ui->n8);
    ui->n1->hide();
    ui->n2->hide();
    ui->n3->hide();
    ui->n4->hide();
    ui->n5->hide();
    ui->n6->hide();
    ui->n7->hide();
    ui->n8->hide();
    ui->w1->hide();
    ui->w2->hide();
    ui->w3->hide();
    ui->w4->hide();
    ui->w5->hide();
    ui->w6->hide();
    ui->w7->hide();
    ui->w8->hide();

    for (int i = 0 ; i < player.size() ; i++)
    {
        labelHold[i]->setNum(player[i].money);
        labelHold[i]->show();
    }
    labelHold.clear();
    labelHold.push_back(ui->w1);
    labelHold.push_back(ui->w2);
    labelHold.push_back(ui->w3);
    labelHold.push_back(ui->w4);
    labelHold.push_back(ui->w5);
    labelHold.push_back(ui->w6);
    labelHold.push_back(ui->w7);
    labelHold.push_back(ui->w8);

    for (int i = 0 ; i < player.size() ; i++)
    {
        labelHold[i]->setText(player[i].name);
        labelHold[i]->show();
    }
    labelHold.clear();
    labelHold.push_back(ui->n1);
    labelHold.push_back(ui->n2);
    labelHold.push_back(ui->n3);
    labelHold.push_back(ui->n4);
    labelHold.push_back(ui->n5);
    labelHold.push_back(ui->n6);
    labelHold.push_back(ui->n7);
    labelHold.push_back(ui->n8);
}

Board::~Board()
{
    delete ui;
}

void Board::on_pushButton_clicked()
{
    srand(time(NULL));
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    ui->dice1->setNum(dice1);
    ui->dice2->setNum(dice2);
    player[turn].slotindex += dice1 + dice2;
    if(player[turn].slotindex > 39)
    {
        player[turn].slotindex -= 40;
        player[turn].money += 200;
    }
    player[turn].x = sLOT[player[turn].slotindex].x;
    player[turn].y = sLOT[player[turn].slotindex].y;
    labelMain[turn]->setGeometry(player[turn].x , player[turn].y , labelMain[turn]->width() , labelMain[turn]->height());

    if(sLOT[player[turn].slotindex].buy)
    {
        sendname = sLOT[player[turn].slotindex].name;
        sendrent = sLOT[player[turn].slotindex].rent;
        sendprice = sLOT[player[turn].slotindex].cost;
        Buy bwindow;
        bwindow.setModal(true);
        bwindow.exec();
    }
    else
    {
        int rnttest = 0;
        for(int i = 0 ; i < player[turn].propertycnt ; i++)
        {
            if(player[turn].slotindex == player[turn].Slots[i])
            {
                rnttest++;
            }
        }
        if(rnttest == 0)
        {
            player[turn].money -= sLOT[player[turn].slotindex].rent;
        }
    }
    turn++;
    for (int i = 0 ; i < player.size() ; i++)
    {
        labelHold[i]->setNum(player[i].money);
    }
}
