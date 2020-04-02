#include "upwidget.h"

UpWidget::UpWidget(QWidget *parent) :
    QWidget(parent)
{
    upscore = 0;
    labelScore = new QLabel("Score: ", this);
    labelScore->setText(QString("Score: %1 ").arg(upscore));
    setGeometry( 10, 10, 390, 85);
}

void UpWidget::myscore(){
    upscore++;
    labelScore->setText(QString("Score: %1 ").arg(upscore));

}

void UpWidget::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter p(this);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::yellow);
    p.drawRect(rect());
}
