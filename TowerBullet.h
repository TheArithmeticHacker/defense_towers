#ifndef TOWERBULLET_H
#define TOWERBULLET_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
class TowerBullet : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    TowerBullet(QGraphicsItem * parent=0);
public slots:
    void move();
private:



};



#endif // TOWERBULLET_H
