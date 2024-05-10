#include "Tower.h"
#include "TowerBullet.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>
#include <QLineF>
#include <QGraphicsRectItem>
#include"Game.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "levelwindow.h"
Tower::Tower( QGraphicsScene * scene):Structure() {
    this->parent = scene; // this is where the problem is
    setPixmap(QPixmap(":/img/Clan_Castle.png"));
    setAcceptHoverEvents(true);
    setType(3);
}
double Tower:: distanceTo(QGraphicsItem * item){
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    qDebug() << "Tower clicked";
    fire(event->pos());
}

void Tower::fire(const QPointF &attackDest) {
    if (parent) {
        qDebug() << "Error: game or game->scene is null";
        return;
    }

    TowerBullet *bullet = new TowerBullet();
    bullet->setPos(getX() + 40, getY() + 48);

    QLineF ln(QPointF(getX() + 40, getY() + 48), mapToScene(attackDest));
    double angle = -ln.angle();
    bullet->setRotation(angle);
    parent->addItem(bullet);
}

