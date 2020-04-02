#include "downwidget.h"

DownWidget::DownWidget(QWidget *parent) :
    QWidget(parent)
{
    int delay = 50;

    accelerate = new QPushButton("accelerate", this);
    stop = new QPushButton("stop",this);
    connect(accelerate, SIGNAL(clicked(bool)), this, SLOT(Slot()));
    connect(stop, SIGNAL(clicked(bool)), this, SLOT(Slot1()));
    stop->setGeometry(0, 30, 93, 29);

    bat = new QLabel(this);
    bat->setStyleSheet("background-color:gray; border-radius:5px");
    bat->setGeometry(40, 40, 100, 50);

    ball = new QLabel(this);
    ball->resize(50, 50);
    ball->setStyleSheet("background-color:black; border-radius:25px");

    x = y = 0;
    dx = dy = 1;
    db = 20;
    resize(780, 500);
    connect(&timer, SIGNAL(timeout()), this, SLOT(myballmove()));
    timer.start(10);
}

void DownWidget::Slot(){
    timer.setInterval(delay++);
    timer.start();

}

void DownWidget::Slot1(){
    timer.stop();
}


void DownWidget::myballmove(){
    x += dx;
    y += dy;
    if(y > this->height() - ball->height())
        timer.stop();
    else if(x > (bat->x() - 25) && x <(bat->x() +75) && y > (bat->y() - 50)){
        dy = -1;
        myscore();

    }
    else if (x > this->width() - ball->width())
        dx = -1;
    else if(y == 0)
        dy = 1;
    else if(x == 0)
        dx = 1;

    ball->move(x, y);

}

void  DownWidget::resizeEvent(QResizeEvent *dragwindow){
    if(dragwindow){
        bat->move(bat->x(), this->height() - 30);
    }
}

void  DownWidget::keyPressEvent(QKeyEvent *press)
{
    switch (press->key()) {
    case Qt::Key_A:
        if(bat->x() > 0)
        bat->move(bat->x() - db, bat->y());
        break;
    case Qt::Key_D:
        if(bat->x() < this->width() - 100)
        bat->move(bat->x() + db, bat->y());
        break;
    default:
        break;
    }
}

void DownWidget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::white);
    p.drawRect(rect());
}
