#ifndef ENEMY_H
#define ENEMY_H

#include <castle.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QObject>
#include <QTimer>
#include <Wall.h>
#include <healthbar.h>
#include "Tower.h"
class Enemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    double levelSpeed[5];
    double levelHealth[5];
    double levelDamage[5];
    double maxHealth;
    double currHealth;
    double currSpeed;
    double currDamage;
    QList<QPixmap> animatedAttack;
    QList<QPixmap> animatedWalk;
    QList<QPixmap> animatedDeath;
    QTimer *animatedWalkTimer;
    QTimer *animatedAttackTimer;
    QTimer *animatedDeathTimer;
    QTimer *movementTimer;
    QTimer *cooldownTimer;
    HealthBar *healthBar;
    int currentWalkFrame = 0;
    int currentAttackFrame = 0;
    int currentDeathFrame = 0;
    int animationInterval = 100;
    bool isAttackOver;

public:
    Enemy(int, int);
    ~Enemy();

    //setters
    void setDamage(double d);
    void setSpeed(double s);
    void setHealth(double h);
    void increaseHealth(double h);
    void decreaseHealth(double h);
    void setFrame(int frameIndex);
    //getters
    double getDamage();
    double getSpeed();
    double getHealth();

    //functionalities
    void attackCastle(Castle *);
    void attackWall(Wall *);
    void attackTower(Tower *);
    void startWalkingAnimation();
    void startAttackingAnimation();
    void startDeathAnimation();
    void updatePixmap();

public slots:
    void movePath();
    //void moveHealthBar();
    void advanceWalkFrame();
    void advanceAttackFrame();
    void advanceDeathFrame();
    void cooldownTime();
};

#endif // ENEMY_H
