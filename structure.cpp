#include "structure.h"

Structure::Structure(): QObject(), QGraphicsPixmapItem() {
    health = 0;
}

double Structure::getHealth()
{
    return health;
}

double Structure::getMaxHealth()
{
    return maxHealth;
}

int Structure::getType()
{
    return type;
}

int Structure::getX()
{
    return x;
}
int Structure::getY()
{
    return y;
}

void Structure::changeHealth(int x)
{
    //Update health
    health += x;
}

void Structure::setPosition(int xPos, int yPos)
{
    x = xPos;
    y = yPos;
    //Sets the position of the structure into an appropriate position according to 13x13 grid
    if(x > 12 || x < 0)
        return;
    if(y > 12 || y < 0)
        return;
    //The offsets is due to the upper bar containing health, close button, timer, and score.
    setPos(x*61+1, y*57 + 51);

}

void Structure::setType(int t)
{
    type = t;
}

void Structure::setHealth(double h)
{
    health = h;
}

void Structure::setMaxHealth(double h)
{
    maxHealth = h;
}

void Structure::setCost(double c)
{
    costOfWalk = c;
}

bool Structure::isDamaged()
{
    //Used to check if the strucutre is damaged
    return health < maxHealth;
}
