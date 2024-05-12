#ifndef Booster_H
#define Booster_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QList>
#include <QRandomGenerator>
#include "structure.h"
#include"game.h"

class Booster : public Structure {
    Q_OBJECT
public:
    explicit Booster(QGraphicsScene* Scene,Game* game);

private slots:
    void respawnImage();

private:
    QGraphicsScene *parentscene;
    QGraphicsPixmapItem *imageItem;
    QTimer *respawnTimer;
    Game*  parentgame;
};

#endif // Booster_H
