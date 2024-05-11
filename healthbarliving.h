#ifndef HEALTHBARLIVING_H
#define HEALTHBARLIVING_H
#include <QGraphicsPixmapItem>
class HealthBarLiving
{
public:
    HealthBarLiving(QGraphicsPixmapItem*, int w, int h, qreal xPos, qreal yPos, int stroke);
    ~HealthBarLiving();
    qreal xPosition, yPosition;
    int width;
    int height;
    void updateBar();
    int borderStroke;
    QGraphicsRectItem * blackBar;
    QGraphicsRectItem * whiteBar;
    QGraphicsRectItem * redBar;
    QGraphicsPixmapItem* parent;
};

#endif // HEALTHBARLIVING_H
