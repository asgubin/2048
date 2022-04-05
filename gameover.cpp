#include "gameover.h"
#include "ui_gameover.h"
#include "mainwindow.h"

GameOver::GameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{
    qApp->quit();
}

void GameOver::on_pushButton_2_clicked()
{

    emit buttonTryAgain();
    this->close();
}

void GameOver::setWinLossLabel(QString str)
{
    ui->WinLossLabel->setText(str);
}
