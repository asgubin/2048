#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gameover.h"
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label[0][0]=ui->a00;
    label[0][1]=ui->a01;
    label[0][2]=ui->a02;
    label[0][3]=ui->a03;
    label[1][0]=ui->a10;
    label[1][1]=ui->a11;
    label[1][2]=ui->a12;
    label[1][3]=ui->a13;
    label[2][0]=ui->a20;
    label[2][1]=ui->a21;
    label[2][2]=ui->a22;
    label[2][3]=ui->a23;
    label[3][0]=ui->a30;
    label[3][1]=ui->a31;
    label[3][2]=ui->a32;
    label[3][3]=ui->a33;

    setData();
    ui->highScore->setText(QString::number(game.getHighScore()));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setData(){
    int i, j;
    int cell;
    int size = game.getSize();

    for (i = 0; i < size; i++) {

        for (j = 0; j < size; j++) {
            cell = game.getCell(i, j);

            if (cell != 0) {
                label[i][j]->setText(QString::number(cell));
                setBackgroundColor(label[i][j], cell);
            }

            else {
                label[i][j]->setText("");
                setBackgroundColor(label[i][j], cell);
            }
        }
    }

    ui->score->setText(QString::number(game.getScore()));
}

void MainWindow::setBackgroundColor(QLabel *label, int value)
{
    switch (value) {
    case 0:
        label->setStyleSheet("QLabel{background-color: rgb(204, 204, 153)}");
        break;
    case 2:
        label->setStyleSheet("background-color: rgb(225, 225, 180); font: 48pt; font-weight: 600");
        break;
    case 4:
        label->setStyleSheet("background-color: rgb(180, 180, 190); font: 48pt; font-weight: 600");
        break;
    case 8:
        label->setStyleSheet("background-color: rgb(255, 183, 124); font: 48pt; font-weight: 600");
        break;
    case 16:
        label->setStyleSheet("background-color: rgb(255, 151, 120); font: 48pt; font-weight: 600");
        break;
    case 32:
        label->setStyleSheet("background-color: rgb(255, 140, 0); font: 48pt; font-weight: 600");
        break;
    case 64:
        label->setStyleSheet("background-color: rgb(255, 100, 20); font: 48pt; font-weight: 600");
        break;
    case 128:
        label->setStyleSheet("background-color: rgb(255, 255, 127); font: 38pt; font-weight: 600");
        break;
    case 256:
        label->setStyleSheet("background-color: rgb(208, 255, 201); font: 38pt; font-weight: 600");
        break;
    case 512:
        label->setStyleSheet("background-color: rgb(167, 202, 255); font: 38pt; font-weight: 600");
        break;
    case 1024:
        label->setStyleSheet("background-color: rgb(161, 255, 22); font: 30pt; font-weight: 600");
        break;
    case 2048:
        label->setStyleSheet("background-color: rgb(255, 180, 225); font: 30pt; font-weight: 600");
        break;
    }

}

void MainWindow::on_Restart_clicked()
{
    ui->highScore->setText(QString::number(game.getHighScore()));

    game.restartGame();

    setData();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_W:
        if (game.gameOver() || game.gameWin()) {
            gameOverWindow();
            break;
        }
        else {
            game.moveUp();
            setData();
            break;
        }
    case Qt::Key_S:
        if (game.gameOver() || game.gameWin()) {
            gameOverWindow();
            break;
        }
        else {
            game.moveDown();
            setData();
            break;
        }
    case Qt::Key_A:
        if (game.gameOver() || game.gameWin()) {
            gameOverWindow();
            break;
        }
        else {
            game.moveLeft();
            setData();
            break;
        }
    case Qt::Key_D:
        if (game.gameOver() || game.gameWin()) {
            gameOverWindow();
            break;
        }
        else {
            game.moveRight();
            setData();
            break;
        }
    }
}

void MainWindow::gameOverWindow()
{
    GameOver window;

    connect (&window, SIGNAL(buttonTryAgain ()), this, SLOT(on_Restart_clicked()));

    if (game.gameOver())
        window.setWinLossLabel("Game Over");
    else if (game.gameWin())
        window.setWinLossLabel("2048! You WIN");

    window.setModal(true);
    window.exec();
}
