#ifndef TIMEWIDGET_H
#define TIMEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QTimer>
#include <QString>
#include <QDateTime>

class Timewidget : public QWidget
{
    Q_OBJECT
public:
    explicit Timewidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    void timerUpdate();
private:
    QLabel *label;
    QTimer * timer;
};

#endif // TIMEWIDGET_H
