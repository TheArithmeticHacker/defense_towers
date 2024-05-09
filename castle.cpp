#include "castle.h"
#include <QDebug>


Castle::Castle(QGraphicsScene* parent): Structure() {
    this->parent = parent;
    setPixmap(QPixmap(":/img/Resources/Castle.png").scaled(50, 50));
    maxHealth = 20;
    type = 1;
    health = maxHealth;
    healthBar = new HealthBar(this, 400, 50, 0, 0, 3);
    costOfWalk = 20;
}

void Castle::mousePressEvent(QGraphicsSceneMouseEvent * e)
{
    if(e->button() == Qt::LeftButton){
        changeHealth(-2);
    }else if(e->button() == Qt::RightButton){
        changeHealth(1);
    }
}

void Castle::changeHealth(int x){
    if(health + x > maxHealth){
        health = maxHealth;
    }else if(health + x <= 0){
        //Placeholder code for now
        health = 0;
        healthBar->updateBar();
        qDebug("Health Over");
    }else{
        health += x;
        healthBar->updateBar();
    }
}
