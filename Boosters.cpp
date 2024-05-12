#include "Boosters.h"
#include "Tower.h"
#include "worker.h"
#include "Wall.h"
#include "TowerBullet.h"
Booster::Booster(QGraphicsScene *Scene,Game* game) : Structure() {
    parentscene=Scene;


    // Load image
    QPixmap image(":/img/booster.png");
    imageItem = parentscene->addPixmap(image);



    respawnTimer = new QTimer(this);
    connect(respawnTimer, &QTimer::timeout, this, &Booster::respawnImage);
    respawnTimer->start(10000);
}

void Booster::respawnImage() {
    bool overlapped = true;
    while (overlapped) {
        int newX = QRandomGenerator::global()->bounded(0, static_cast<int>(800 - imageItem->boundingRect().width()));
        int newY = QRandomGenerator::global()->bounded(0, static_cast<int>(400 - imageItem->boundingRect().height()));

        overlapped = false;
        QList<QGraphicsItem*> collidingItems;
        for (auto item : {Tower::Type, Castle::Type, Enemy::Type, Worker::Type, Wall::Type, TowerBullet::Type}) {
            collidingItems = parentscene->items(imageItem->mapToScene(imageItem->boundingRect()).translated(newX, newY), Qt::IntersectsItemShape);
            if (!collidingItems.isEmpty()) {
                for (QGraphicsItem* item : collidingItems) {
                    if (item->type() == TowerBullet::Type) {
                        TowerBullet* towerBullet = dynamic_cast<TowerBullet*>(item);
                        if (towerBullet && towerBullet->scene() == parentscene) {
                            parentscene->removeItem(towerBullet);
                            delete towerBullet;
                            qDebug() << "TowerBullet deleted";
                        } else {
                            qDebug() << "TowerBullet is null or belongs to a different scene!";
                        }
                    } else {
                        overlapped = true;
                        break;
                    }
                }
            }
        }

        if (overlapped)
            continue;

        imageItem->setPos(newX, newY);
    }
}
