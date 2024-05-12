#include "gameover.h"
#include "ui_gameover.h"
#include <QAudioOutput>
#include<QMediaPlayer>

GameOver::GameOver(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameOver)
{
    ui->setupUi(this);
    QAudioOutput* loseaudio = new QAudioOutput();
    loseaudio->setVolume(50);
    QMediaPlayer* losemedia = new QMediaPlayer();
    losemedia->setAudioOutput(loseaudio);
    losemedia->setSource(QUrl("qrc:/sounds/lose.mp3"));
    losemedia->play();
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

