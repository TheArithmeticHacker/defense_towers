#include "Tower.h"
#include "TowerBullet.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>
#include <QLineF>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "levelwindow.h"

Tower::Tower(QGraphicsScene* Scene, Game* game):Structure() {
    parent = game->scene;
    parentGame = game;
    setPixmap(QPixmap(":/img/Clan_Castle.png").scaled(50, 50));
    setAcceptHoverEvents(true);
    type=3;
    healthBar = nullptr;
    maxHealth = 20;
    health = maxHealth;
    costOfWalk = 50;
}
double Tower:: distanceTo(QGraphicsItem * item){
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if(event->button() == Qt::LeftButton){
        fire(event->pos());

    }else if(event->button() == Qt::RightButton){
        changeHealth(-1);
    }
}

void Tower::fire(const QPointF &attackDest) {
    if (!parent || !parentGame) {
        qDebug() << "Error: game or game->scene is null";
        return;
    }

    TowerBullet *bullet = new TowerBullet(this);
    bullet->setPos(x() + 20, y() + 30);

    QLineF ln(QPointF(x() + 20, y() + 30), mapToScene(attackDest));
    double angle = -ln.angle();
    bullet->setRotation(angle);
    parent->addItem(bullet);
}

void Tower::changeHealth(int healthChange){
    if(healthBar == nullptr){
        healthBar = new HealthBar(this, 50, 10,  xx*61+10, yy*57 + 55,  1);
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

