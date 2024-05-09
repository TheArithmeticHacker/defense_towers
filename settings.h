#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_save_clicked();

    void on_sound_valueChanged(int value);

signals:
    void back();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
