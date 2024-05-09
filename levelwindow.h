#ifndef LEVELWINDOW_H
#define LEVELWINDOW_H

#include <QWidget>
#include "game.h"

namespace Ui {
class LevelWindow;
}

class LevelWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LevelWindow(QWidget *parent = nullptr);
     Game* game;
    ~LevelWindow();
signals:
    void back();
private:
    Ui::LevelWindow *ui;
};

#endif // LEVELWINDOW_H
