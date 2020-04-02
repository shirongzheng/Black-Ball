#include "timewidget.h"

Timewidget::Timewidget(QWidget *parent) : QWidget(parent)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
    timer->start(1000);

    label = new QLabel(this);
    label->setText(QString("Score: %1 ").arg(0));
    label->setGeometry(0, 0, 300, 20);
}

void Timewidget::timerUpdate(){
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    label->setText(str);
}



void Timewidget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::green);
    p.drawRect(rect());
}
