#include "fence.h"
#include <QDebug>
#include <iostream>
Fence::Fence(QGraphicsScene* scene): Structure() {
    setPixmap(QPixmap(":/img/Resources/Fence.png").scaled(61, 58));
    parent = scene;
    type = 2;
    maxHealth = 20;
    health = maxHealth;
    costOfWalk = (health/maxHealth) * 100;
    healthBar = nullptr;

}

Fence::~Fence()
{


}

void Fence::mousePressEvent(QGraphicsSceneMouseEvent * e)
{
    if(e->button() == Qt::LeftButton){
        changeHealth(-2);

    }else if(e->button() == Qt::RightButton){
        changeHealth(1);

    }
}

void Fence::changeHealth(int healthChange){
    if(healthBar == nullptr){
        qDebug("Working");
        healthBar = new HealthBar(this, 50, 10, xx*61+10, yy*57 + 55,  1);
    }

    if(health + healthChange >= maxHealth){
        health = maxHealth;
        qDebug("Max");
        delete healthBar;
        healthBar = nullptr;
    }else if(health + healthChange <= 0){
        //Destruc object and emit game over
        delete healthBar;
        qDebug("Zero");
        parent->removeItem(this);
        type = 0;
    }else{
        qDebug("Something");
        health += healthChange;
        healthBar->updateBar();
    }
}

