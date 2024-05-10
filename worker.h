#ifndef WORKER_H
#define WORKER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <Wall.h>
class Wall;

class Worker : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int healing;
    QTimer *moveTimer;
    QTimer *healingTimer;
    QTimer *returnTimer;
    QStringList healingAnimation;
    QStringList deathAnimation;
    bool doneHealing;

public:
    Worker();

    //getters
    int getHealing();
    bool isDone();

    //setters
    void setHealing(int h);
    void decreaseHealth(int h);

    //functionalities
    void healWall(Wall *&);
    void Die();
};

#endif // WORKER_H
