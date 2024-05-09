
#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QGraphicsTextItem>
#include <QTimer>

class TimerWidget : public QGraphicsTextItem {
    Q_OBJECT
public:
    TimerWidget(QGraphicsItem *parent = nullptr);
    void startTimer();
    void stopTimer();

private slots:
    void updateTime();

private:
    int timeRemaining;
    QTimer *timer;
};

#endif // TIMERWIDGET_H
