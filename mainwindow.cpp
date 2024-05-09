#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include "levelwindow.h"
#include "settings.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(800, 800);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::reset()
{
    ui->setupUi(this);
}

void MainWindow::on_startGame_clicked()
{
    // Game * game = new Game();
    LevelWindow * level = new LevelWindow();
    setCentralWidget(level);
    QObject::connect(level,&LevelWindow::back,this,&MainWindow::reset);
}


void MainWindow::on_settings_clicked()
{
    Settings * settings = new Settings();
    setCentralWidget(settings);
    QObject::connect(settings,&Settings::back,this,&MainWindow::reset);
}

