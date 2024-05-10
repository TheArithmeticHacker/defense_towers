#include "enemy.h"
#include <QGraphicsScene>
#include <QObject>
#include <QPixmap>
#include <QTime>
#include <QTimer>
#include <Wall.h>
#include <castle.h>
#include <worker.h>
Enemy::Enemy(int x, int y)
{
    setPixmap(QPixmap(":/img/Enemy/baseSprite.png")
                  .scaled(120, 100)); //needs some refining until graphically appealing
    setPos(x, y);
    //int l = game->getLevel();
    //maxHealth = currHealth = levelHealth[l];
    //currSpeed = levelSpeed[l];
    //currDamage = levelDamage[l];
    for (int i = 1; i <= 11; ++i) {
        QString filePath = ":/img/Enemy/run_" + QString::number(i) + ".png";
        animatedWalk.append(QPixmap(filePath));
    }
    for (int i = 1; i <= 12; ++i) {
        QString filePath = ":/img/Enemy/attack_" + QString::number(i) + ".png";
        animatedAttack.append(QPixmap(filePath));
    }
    for (int i = 1; i <= 16; ++i) {
        QString filePath = ":/img/Enemy/die_" + QString::number(i) + ".png";
        animatedDeath.append(QPixmap(filePath));
    }
    animatedWalkTimer = new QTimer(this);
    animatedAttackTimer = new QTimer(this);
    animatedDeathTimer = new QTimer(this);
    connect(animatedWalkTimer, &QTimer::timeout, this, &Enemy::advanceWalkFrame);
    connect(animatedAttackTimer, &QTimer::timeout, this, &Enemy::advanceAttackFrame);
    connect(animatedDeathTimer, &QTimer::timeout, this, &Enemy::advanceDeathFrame);
}

Enemy::~Enemy() {}

void Enemy::setDamage(double d)
{
    currDamage = d;
}

void Enemy::setSpeed(double s)
{
    currSpeed = s;
}

void Enemy::setHealth(double h)
{
    currHealth = h;
}

void Enemy::increaseHealth(double h)
{
    currHealth += h;
}

void Enemy::decreaseHealth(double h)
{
    currHealth -= h;
}

double Enemy::getDamage()
{
    return currDamage;
}

double Enemy::getSpeed()
{
    return currSpeed;
}

double Enemy::getHealth()
{
    return currHealth;
}

void Enemy::attackCastle() {}

void Enemy::attackWall(Wall *&) {}

void Enemy::movePath()
{
    //stuff for A*

    QList<QGraphicsItem *> collided_items = collidingItems();
    for (auto &item : collided_items) {
        if (typeid(*item) == typeid(Wall)) {
            Wall *w = dynamic_cast<Wall *>(item);
            if (w->getHealth() > 0)
                attackWall(w);
        } else if (typeid(*item) == typeid(Worker)) {
            Worker *w = dynamic_cast<Worker *>(item);
            w->Die();
        } else if (typeid(*item) == typeid(Castle)) {
            attackCastle();
        }
    }
}

void Enemy::startWalkingAnimation()
{
    animatedWalkTimer->start(animationInterval);
    animatedAttackTimer->stop();
    animatedDeathTimer->stop();
}

void Enemy::startAttackingAnimation()
{
    animatedWalkTimer->stop();
    animatedAttackTimer->start(animationInterval);
    animatedDeathTimer->stop();
}

void Enemy::startDeathAnimation()
{
    animatedWalkTimer->stop();
    animatedAttackTimer->stop();
    animatedDeathTimer->start(animationInterval);
}

void Enemy::advanceWalkFrame()
{
    currentWalkFrame = (currentWalkFrame + 1) % animatedDeath.size();
    updatePixmap();
}

void Enemy::advanceAttackFrame()
{
    currentAttackFrame = (currentAttackFrame + 1) % animatedAttack.size();
    updatePixmap();
}

void Enemy::advanceDeathFrame()
{
    currentDeathFrame = (currentDeathFrame + 1) % animatedDeath.size();
    updatePixmap();
}

void Enemy::updatePixmap()
{
    if (animatedWalkTimer->isActive()) {
        setPixmap(animatedWalk[currentWalkFrame]);
    } else if (animatedAttackTimer->isActive()) {
        setPixmap(animatedAttack[currentAttackFrame]);
    } else if (animatedDeathTimer->isActive()) {
        setPixmap(animatedDeath[currentDeathFrame]);
    }
}
