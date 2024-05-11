#include "healthbarliving.h"
#include "enemy.h"
#include <QDebug>
HealthBarLiving::HealthBarLiving(QGraphicsPixmapItem* parent, int w, int h, qreal xPos, qreal yPos, int stroke) {
    this->parent = parent;
    xPosition = xPos;
    yPosition = yPos;
    borderStroke = stroke;
    //The black bar for borders
    blackBar = new QGraphicsRectItem(xPosition, yPosition, w, h);
    blackBar->setBrush(QBrush(Qt::black));
    dynamic_cast<Enemy*>(parent)->parentScene->addItem(blackBar);
    //White bar for empty health
    whiteBar = new QGraphicsRectItem(xPosition+borderStroke, yPosition+borderStroke, w-2*borderStroke, h-2*borderStroke);
    whiteBar->setBrush(QBrush(Qt::white));
    dynamic_cast<Enemy*>(parent)->parentScene->addItem(whiteBar);
    //Red bar for remaining health
    redBar = new QGraphicsRectItem(xPosition+borderStroke, yPosition+borderStroke, w-2*borderStroke, h-2*borderStroke);
    redBar->setBrush(QBrush(Qt::red));
    dynamic_cast<Enemy*>(parent)->parentScene->addItem(redBar);
    width = w;
    height = h;
    qDebug("LivingHealthBar created");
}

HealthBarLiving::~HealthBarLiving()
{

}

void HealthBarLiving::updateBar()
{
    qDebug("Bar updated");
    //xPosition = parent->pos().x() * 61 + 5;
    //yPosition = parent->pos().y() * 57 + 55;
    //blackBar->setRect( xPosition,
    //                yPosition,
    //                width,
    //                  height);
    whiteBar->setRect( xPosition + borderStroke,
                    yPosition + borderStroke,
                    width - 2 * borderStroke,
                    height - 2 * borderStroke);
    redBar->setRect( xPosition + borderStroke,
                    yPosition + borderStroke,
                    dynamic_cast<Enemy*>(parent)->getHealth() / dynamic_cast<Enemy*>(parent)->getMaxHealth() * (width - 2 * borderStroke),
                    height - 2 * borderStroke);
}
