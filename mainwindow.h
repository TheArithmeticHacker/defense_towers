#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void reset();

    void lose();

    void win();

    void on_startGame_clicked();

    void on_settings_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
