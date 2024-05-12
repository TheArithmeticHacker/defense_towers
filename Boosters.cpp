#include "Boosters.h"
#include "Tower.h"
#include "worker.h"
#include "Wall.h"
Booster::Booster(QGraphicsScene *Scene,Game* game) : Structure() {
    parentscene=game->scene;
    setPixmap(QPixmap(":/img/booster.png"));



    respawnTimer = new QTimer(this);
    connect(respawnTimer, SIGNAL(timeout()), this, SLOT(respawnImage()));;
    respawnTimer->start(10000);
}

void Booster::respawnImage() {

        QList<QGraphicsItem *> collidedItems = collidingItems();

        for (auto item : collidedItems) {
            if (typeid(*item) == typeid(Enemy) ||   typeid(*item) == typeid(Wall) || typeid(*item) == typeid(Tower)||   typeid(*item) == typeid(Castle) || typeid(*item) == typeid(Worker )){

                this->setPos(Getrandomx(),Getrandomy());
                }

             this->setPos(Getrandomx(),Getrandomy());
        }
    }
int Booster::Getrandomx(){
    int newX = QRandomGenerator::global()->bounded(0, static_cast<int>(800 - this->boundingRect().width()));
    return newX;
}
int Booster::Getrandomy(){

     int newY = QRandomGenerator::global()->bounded(0, static_cast<int>(400 - this->boundingRect().height()));
    return newY;
}
