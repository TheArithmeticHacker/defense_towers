#ifndef WINSCREEN_H
#define WINSCREEN_H

#include <QWidget>

namespace Ui {
class WinScreen;
}

class WinScreen : public QWidget
{
    Q_OBJECT

public:
    explicit WinScreen(QWidget *parent = nullptr);
    ~WinScreen();

private slots:
    void on_MainMenu_clicked();

    void on_nextLevel_clicked();

signals:
    void back();

    void nextLevel();

private:
    Ui::WinScreen *ui;
};

#endif // WINSCREEN_H
