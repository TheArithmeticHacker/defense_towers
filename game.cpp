#include"Boosters.h"
#include "Wall.h"
#include "castle.h"
#include "timerwidget.h"
#include "worker.h"
#include "Tower.h"
#include "enemy.h"

Game::Game(QWidget *parent) : QGraphicsView(parent) {
    parentWidget = parent;
    //Scene setting
    scene = new QGraphicsScene(this);
    setScene(scene);
    //Creating a 2D vecotrs for Structure pointers
    structures = new Structure**[13];
    for(int i = 0; i < 13; i++)
        structures[i] = new Structure*[13];

    //Map formatiom
    background = new Map();
    background->setPos(0, 50);
    scene->addItem(background);

    //Read data from files to know locations of structures
    locations = new Locations();
    CloseButton* close_btn = new CloseButton(parentWidget);
    scene->addItem(close_btn);

    //Timer of the game
    TimerWidget * time = new TimerWidget(this);
    time->setPos(scene->sceneRect().topRight() - QPointF(time->boundingRect().width()+80, -20));
    scene->addItem(time);
    time->startTimer();

    Booster * boost = new Booster (scene, this);
    scene->addItem(boost);



    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 800);
    locations->readData();

    build();


        Enemy *enemy = new Enemy(scene, 700, 700);
        scene->addItem(enemy);

    Tower *tower = new Tower(scene, this);
    tower->setPos(420,430);
    scene->addItem(tower);

    Worker* worker1 = new Worker(400, 400);
    scene->addItem(worker1);
}

Game::~Game()
{



}

bool Game::isThere(QMouseEvent *e, int x, int y, int w, int h)
{
    if(e->x() >= x && e->x() < x + w && e->y() >= y && e->y() < y+h)
        return true;
    return false;
    return true;
}

void Game::mousePressEvent(QMouseEvent* e)
{
    QGraphicsView::mousePressEvent(e);
}

void Game::build(){
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            if(locations->coordinates[i][j] == 0){
                structures[i][j] = nullptr;
            }else if(locations->coordinates[i][j] == 1){

                structures[i][j] = new Castle(scene, this);
                structures[i][j]->setPosition(j, i);
                scene->addItem(structures[i][j]);
                qDebug("Test");
            }else if(locations->coordinates[i][j] == 2){
                structures[i][j] = new Wall(scene);
                structures[i][j]->setPosition(j, i);
                scene->addItem(structures[i][j]);

            }else if(locations->coordinates[i][j] == 3){
                structures[i][j] = new Tower(scene, this);
                structures[i][j]->setPosition(j, i);
                scene->addItem(structures[i][j]);
            }else{
                //   qDebug("Not Working");
            }
        }
    }
    qDebug("Test");

}

void Game::update()
{
    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            if(locations->coordinates[i][j] != 0 && structures[i][j]->getType()==0)
                locations->coordinates[i][j] = structures[i][j]->getType();
        }
    }

    locations->writeData();
}
