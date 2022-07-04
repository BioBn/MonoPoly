#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "playernaming.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    PlayerNaming PNwindow;
    hide();
    PNwindow.setModal(true);
    PNwindow.exec();

}

void MainWindow::on_pushButton_2_clicked()
{
    close();
}
