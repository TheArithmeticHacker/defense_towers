#include "structure.h"

Structure::Structure(): QObject(), QGraphicsPixmapItem() {
    health = 0;
}

void Structure::changeHealth(int x)
{
    //Update health
    health += x;
}

void Structure::setPosition(int xPos, int yPos)
{
    xx = xPos;
    yy = yPos;
    //Sets the position of the structure into an appropriate position according to 13x13 grid
    if(xx > 12 || xx < 0)
        return;
    if(yy > 12 || yy < 0)
        return;
    //The offsets is due to the upper bar containing health, close button, timer, and score.
    setPos(xx*61+1, yy*57 + 51);

}

bool Structure::isDamaged()
{
    //Used to check if the strucutre health is 0
    return health <= 0;
}
