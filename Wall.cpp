#include "Wall.h"
#include <QDebug>
#include <iostream>
Wall::Wall(QGraphicsScene *scene)
    : Structure()
{
    setPixmap(QPixmap(":/img/Resources/Fence.png").scaled(61, 58));
    parent = scene;
    setType(2);
    setMaxHealth(20);
    setHealth(getMaxHealth());
    setCost((getHealth() / getMaxHealth()) * 100);
    healthBar = nullptr;
}

Wall::~Wall() {}

void Wall::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        changeHealth(-2);

    }else if(e->button() == Qt::RightButton){
        changeHealth(1);

    }
}

void Wall::changeHealth(int healthChange)
{
    if(healthBar == nullptr){
<<<<<<< HEAD
        healthBar = new HealthBar(this, 50, 10, getX() * 61 + 5, getY() * 57 + 55, 1);
=======
        healthBar = new HealthBar(this, 50, 10, xx*61+5, yy*57 + 55,  1);
>>>>>>> 3f134e7376b384d8cd454fc483b78d5f8b126192
    }

    if (getHealth() + healthChange >= getMaxHealth()) {
        setHealth(getMaxHealth());
        qDebug("Max");
        delete healthBar;
        healthBar = nullptr;
    } else if (getHealth() + healthChange <= 0) {
        //Destruc object and emit game over
        delete healthBar;
        qDebug("Zero");
        parent->removeItem(this);
        setType(0);
    } else {
        qDebug("Something");
        setHealth(getHealth() + healthChange);
        healthBar->updateBar();
    }
}
