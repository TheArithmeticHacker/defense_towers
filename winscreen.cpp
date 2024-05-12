#include "winscreen.h"
#include "ui_winscreen.h"
#include <QAudioOutput>
#include<QMediaPlayer>

WinScreen::WinScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WinScreen)
{
    ui->setupUi(this);
    QAudioOutput* winaudio = new QAudioOutput();
    winaudio->setVolume(50);
    QMediaPlayer* winmedia = new QMediaPlayer();
    winmedia->setAudioOutput(winaudio);
    winmedia->setSource(QUrl("qrc:/sounds/win.mp3"));
    winmedia->play();
}

WinScreen::~WinScreen()
{
    delete ui;
}

void WinScreen::on_MainMenu_clicked()
{
    emit back();
    delete this;
}


void WinScreen::on_nextLevel_clicked()
{
    emit nextLevel();
    delete this;
}

