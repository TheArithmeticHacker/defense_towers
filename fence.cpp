#include "fence.h"

Fence::Fence(QGraphicsScene* scene): Structure() {
    setPixmap(QPixmap(":/img/Resources/Fence.png").scaled(61, 58));
    parent = scene;
    health = 20;
}


