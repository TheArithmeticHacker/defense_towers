#ifndef FENCE_H
#define FENCE_H
#include "structure.h"
#include <QGraphicsScene>
#include "healthbar.h"
#include <QGraphicsSceneMouseEvent>


class Fence : public Structure
{
public:
    Fence(QGraphicsScene*);
    HealthBar* healthBar;
    void changeHealth(int);
public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
};

#endif // FENCE_H
