#include "worker.h"

Worker::Worker() {}

int Worker::getHealing()
{
    return healing;
}

bool Worker::isDone()
{
    return doneHealing;
}

void Worker::setHealing(int h)
{
    healing = h;
}

//connect with Timer and stuff
void Worker::healWall(Wall *&w)
{
    while (!doneHealing) {
        //have some availibility bool or something
        setPos(x() - 3, y() - 3); //needs fine-tuning on the map. Random offsets
        moveTimer->stop();
        w->changeHealth(this->getHealing());
        if (w->getHealth() >= w->getMaxHealth()) {
            w->setHealth(w->getMaxHealth());
            doneHealing = true;
            //either here or elsewhere (probably in game class) make the queue idea
        }
    }
}

void Worker::Die()
{
    //game->getScene()->removeItem(this);
    //game->setDeadWorker(getDeadWorker()++);
}
