#ifndef CASTLE_H
#define CASTLE_H
#include "structure.h"
#include "healthbar.h"
#include <QGraphicsSceneMouseEvent>

class Castle: public Structure
{
public:
    Castle(QGraphicsScene*);
    HealthBar * healthBar;
    void changeHealth(int);

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
};

#endif // CASTLE_H
