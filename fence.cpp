#include "fence.h"
#include <QDebug>
#include <iostream>
Fence::Fence(QGraphicsScene* scene): Structure() {
    setPixmap(QPixmap(":/img/Resources/Fence.png").scaled(61, 58));
    parent = scene;
    maxHealth = 20;
    health = maxHealth;
    costOfWalk = (health/maxHealth) * 100;
    healthBar = nullptr;

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
        healthBar = new HealthBar(this, 50, 10, x*61+5, y*57 + 55,  1);
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
        healthBar = nullptr;
        delete this;
    }else{
        qDebug("Something");
        health += healthChange;
        healthBar->updateBar();
    }
}

