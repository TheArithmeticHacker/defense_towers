#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsItem>
#include "structure.h"
#include "closebutton.h"
#include "locations.h"
#include "map.h"


class Game : public QGraphicsView
{

public:
    Game(QWidget* parent = 0);

    ~Game();

    QGraphicsScene * scene;



    Map * background;

    Structure***  structures;

    Locations* locations;

    QWidget* parentWidget;

    bool isThere(QMouseEvent* e, int x, int y, int w, int h);

    void build();

    void update();
signals:
    void back();
public slots:
    void mousePressEvent(QMouseEvent*);

};


#endif // GAME_H
