#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QWidget>

namespace Ui {
class GameOver;
}

class GameOver : public QWidget
{
    Q_OBJECT

public:
    explicit GameOver(QWidget *parent = nullptr);
    ~GameOver();

private slots:
    void on_MainMenu_clicked();

    void on_tryAgain_clicked();

signals:
    void back();

    void tryAgain();

private:
    Ui::GameOver *ui;
};

#endif // GAMEOVER_H
