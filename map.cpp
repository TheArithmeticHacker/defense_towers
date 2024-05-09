#include "map.h"
#include <QPixmap>
Map::Map(): QGraphicsPixmapItem() {
    setPixmap(QPixmap(":/img/Resources/Background1.png").scaled(800, 750));
}
