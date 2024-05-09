#include "game.h"
#include "castle.h"
#include "fence.h"
#include "timerwidget.h"

Game::Game(QWidget *parent) : QGraphicsView(parent) {
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
    CloseButton* close_btn = new CloseButton(parent);
    scene->addItem(close_btn);


    TimerWidget * time = new TimerWidget();
    time->setPos(scene->sceneRect().topRight() - QPointF(time->boundingRect().width()+80, -20));
    scene->addItem(time);
    time->startTimer();


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 800);
    locations->readData();

    build();
}

Game::~Game()
{

    for(int i = 0; i < 13; i++){
        for(int j = 0; j < 13; j++){
            if(locations->coordinates[i][j] == 2 && structures[i][j]->type==0)
                locations->coordinates[i][j] = structures[i][j]->type;
        }
    }

    locations->writeData();

}

bool Game::isThere(QMouseEvent *e, int x, int y, int w, int h)
{
    /*
    if(e->x() >= x && e->x() < x + w && e->y() >= y && e->y() < y+h)
        return true;
    return false;
    */
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
                structures[i][j] = new Castle(scene);
                structures[i][j]->setPosition(j, i);
                scene->addItem(structures[i][j]);
                //scene->addItem(dynamic_cast<Castle*>(structures[i][j])->healthBar);
            }else if(locations->coordinates[i][j] == 2){
                structures[i][j] = new Fence(scene);
                structures[i][j]->setPosition(j, i);
                scene->addItem(structures[i][j]);

            }else if(locations->coordinates[i][j] == 3){
                //
            }else{
                //   qDebug("Not Working");
            }
        }
    }

}
