#include "castle.h"
#include <QDebug>
#include "levelwindow.h"


Castle::Castle(QGraphicsScene* Scene, Game* game): Structure() {
    //Parent Scene is necessary so that HealthBar can be implemented
    parent = game->scene;
    //We use the game pointer in order to access the signals of LevelWindow through Game Object
    parentGame = game;
    setPixmap(QPixmap(":/img/Resources/Castle.png").scaled(50, 50));
    setMaxHealth(20);
    setType(1);
    setHealth(getMaxHealth());
    healthBar = new HealthBar(this, 400, 50, 0, 0, 3);
    setCost(0);
}

void Castle::mousePressEvent(QGraphicsSceneMouseEvent * e)
{
    if(e->button() == Qt::LeftButton){
        changeHealth(-2);
    }else if(e->button() == Qt::RightButton){
        changeHealth(1);
    }
}

//Function that handles the healthBar of the Castle
void Castle::changeHealth(double x)
{
    if (getHealth() + x > getMaxHealth()) {
        setHealth(getMaxHealth());
    } else if (getHealth() + x <= 0) {
        //Placeholder code for now
        setHealth(0);
        healthBar->updateBar();
        //Code that trigers lose condition of the game
        emit dynamic_cast<LevelWindow*>(parentGame->parentWidget)->loseScreen();
        delete parentGame->parentWidget;
    } else {
        setHealth(getHealth() + x);
        healthBar->updateBar();
    }
}
