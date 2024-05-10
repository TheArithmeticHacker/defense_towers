#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QPair>


class Structure: public QObject, public QGraphicsPixmapItem
{
public:
    Structure();

    //position of the structure
    int x, y;

    //Type
    int type;

    float health;

    float maxHealth;

    float costOfWalk;

    virtual void changeHealth(int);

    void setPosition(int, int);

    bool isDamaged();

    //HealthBar* healthBar;
    //virtual void updateHealthBar() = 0;

    //Since I cannot use Game as it has a Structures array, I use the QGraphicsScene to add elements that other structures add
    QGraphicsScene* parent;
};


#endif // STRUCTURE_H
