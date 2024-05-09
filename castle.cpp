#include "castle.h"

Castle::Castle(): Structure() {
    setPixmap(QPixmap(":/img/Resources/Castle.png").scaled(50, 50));
    health = 20;
}
