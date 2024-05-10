#include "levelwindow.h"
#include "ui_levelwindow.h"
#include "gameover.h"



LevelWindow::LevelWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LevelWindow)
{
    ui->setupUi(this);

    game = new Game(this);
    setFixedHeight(800);
    setFixedWidth(800);
    game->showFullScreen();
}

LevelWindow::~LevelWindow()
{

    delete game;
    delete ui;
}
