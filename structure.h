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

    int x, y;

    int type;

    float health;

    float costOfWalk;

    void changeHealth(int);

    void setPosition(int, int);

    bool isDamaged();

    QGraphicsScene* parent;
};


#endif // STRUCTURE_H
