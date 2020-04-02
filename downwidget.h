#ifndef DOWNWIDGET_H
#define DOWNWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QKeyEvent>
#include <QResizeEvent>
#include <QTimer>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>

class DownWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DownWidget(QWidget *parent = 0);
    void resizeEvent(QResizeEvent *dragwindow);
    void keyPressEvent(QKeyEvent *press);
    void paintEvent(QPaintEvent *event);

signals:
    void myscore();
    void Signal();
public slots:
    void myballmove();
    void Slot();
    void Slot1();
private:

    QPushButton *accelerate, *stop;
    QLabel *ball, *bat;
    QTimer timer;
    int x, y, dx, dy, db;
    int ballspeed;
    int delay;
//    QPalette palette;

};

#endif // DOWNWIDGET_H
