#include "gameover.h"
#include "ui_gameover.h"

GameOver::GameOver(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameOver)
{
    ui->setupUi(this);
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_MainMenu_clicked()
{
    emit back();
    delete this;
}


void GameOver::on_tryAgain_clicked()
{
    emit tryAgain();
    delete this;
}

