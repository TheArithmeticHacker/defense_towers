#ifndef CASTLE_H
#define CASTLE_H
#include "structure.h"
#include "healthbar.h"
#include <QGraphicsSceneMouseEvent>
#include "game.h"

class Castle: public Structure
{
public:
    Castle(QGraphicsScene*, Game*);
    HealthBar * healthBar;
    void changeHealth(int);
    Game* parentGame;
    QGraphicsScene* parentScene;

public slots:
    void mousePressEvent(QGraphicsSceneMouseEvent*);
};

#endif // CASTLE_H
