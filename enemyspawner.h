#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H
#include "enemy.h"
#include <QGraphicsScene>
#include <QVector>

class EnemySpawner
{
public:
    EnemySpawner(QGraphicsScene*);
    QVector<Enemy*> activeEnemies;
    QGraphicsScene* parentScene;
    void spawnEnemy();
};

#endif // ENEMYSPAWNER_H
