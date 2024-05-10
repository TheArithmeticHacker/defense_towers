#include "Tower.h"
#include "TowerBullet.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QTimer>
#include <QLineF>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QGraphicsScene>
#include "levelwindow.h"
Tower::Tower(QGraphicsScene* Scene, Game* game):Structure() {
    parent = game->scene;
    parentGame = game;
    setPixmap(QPixmap(":/img/Clan_Castle.png"));
    setAcceptHoverEvents(true);
    type=3;
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
    if (!parent || !parentGame) {
        qDebug() << "Error: game or game->scene is null";
        return;
    }

    TowerBullet *bullet = new TowerBullet(this);
    bullet->setPos(x() + 20, y() + 30);

    QLineF ln(QPointF(x() + 20, y() + 30), mapToScene(attackDest));
    double angle = -ln.angle();
    bullet->setRotation(angle);
    parent->addItem(bullet);
}

