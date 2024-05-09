#include "structure.h"

Structure::Structure(): QObject(), QGraphicsPixmapItem() {
    health = 0;
    x = 0;
    y = 0;

}

void Structure::changeHealth(int x)
{
    //Update health
    health += x;
}

void Structure::setPosition(int x, int y)
{
    //Sets the position of the structure into an appropriate position according to 13x13 grid
    if(x > 12 || x < 0)
        return;
    if(y > 12 || y < 0)
        return;
    //The offsets is due to the upper bar containing health, close button, timer, and score.
    setPos(x*61+1, y*57 + 51);
}

bool Structure::isDamaged()
{
    //Used to check if the strucutre health is 0
    return health <= 0;
}
