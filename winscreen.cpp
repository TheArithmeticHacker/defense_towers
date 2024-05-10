#include "winscreen.h"
#include "ui_winscreen.h"

WinScreen::WinScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WinScreen)
{
    ui->setupUi(this);
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

