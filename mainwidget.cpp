#include "mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
{
    time = new Timewidget(this);
    topWidget = new UpWidget(this);
    bottomWidget = new DownWidget(this);

    connect(bottomWidget, SIGNAL(myscore()), topWidget, SLOT(myscore()));

    hbox = new QHBoxLayout;
    hbox->addWidget(time);
    topWidget->setFixedHeight(30);
    time->setFixedHeight(30);
    hbox->addWidget(topWidget);
    vbox = new QVBoxLayout();
    vbox->addLayout(hbox);
    vbox->addWidget(bottomWidget);
    setLayout(vbox);
    resize(800, 600);
    palette.setBrush(this->backgroundRole(), Qt::lightGray);
    this->setPalette(palette);
}
