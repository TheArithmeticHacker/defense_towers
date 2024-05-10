#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "levelwindow.h"
#include "settings.h"
#include "gamesettings.h"
#include "winscreen.h"
#include "gameover.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    GameSettings settings;
    ui->setupUi(this);
    setFixedSize(800, 800);
    ui->startGame->setText("Play Level " + QString::number(settings.currLevel));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::reset()
{
    ui->setupUi(this);
    GameSettings settings;
    ui->startGame->setText("Play Level " + QString::number(settings.currLevel));

}

void MainWindow::lose()
{
    GameOver * gameOverScreen = new GameOver();
    setCentralWidget(gameOverScreen);
    QObject::connect(gameOverScreen, &GameOver::back, this, &MainWindow::reset);
    QObject::connect(gameOverScreen, &GameOver::tryAgain, this, &MainWindow::on_startGame_clicked);
}

void MainWindow::win()
{
    WinScreen* winScreen = new WinScreen();
    GameSettings settings;
    settings.updateLevel();
    setCentralWidget(winScreen);
    QObject::connect(winScreen, &WinScreen::back, this, &MainWindow::reset);
    QObject::connect(winScreen, &WinScreen::nextLevel, this, &MainWindow::on_startGame_clicked);
}

void MainWindow::on_startGame_clicked()
{
    // Game * game = new Game();
    LevelWindow * level = new LevelWindow();
    setCentralWidget(level);
    QObject::connect(level,&LevelWindow::back,this,&MainWindow::reset);
    QObject::connect(level,&LevelWindow::winScreen,this,&MainWindow::win);
    QObject::connect(level,&LevelWindow::loseScreen,this,&MainWindow::lose);
}


void MainWindow::on_settings_clicked()
{
    Settings * settings = new Settings();
    setCentralWidget(settings);
    QObject::connect(settings,&Settings::back,this,&MainWindow::reset);
}

