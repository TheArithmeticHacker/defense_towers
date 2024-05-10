#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QList>
#include <QObject>
#include <QTimer>
#include <Wall.h>
#include <healthbar.h>
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
    HealthBar *healthBar;
    int currentWalkFrame = 0;
    int currentAttackFrame = 0;
    int currentDeathFrame = 0;
    int animationInterval = 100;

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
    void attackCastle();
    void attackWall(Wall *&);
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
};

#endif // ENEMY_H
