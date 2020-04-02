#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "upwidget.h"
#include "downwidget.h"
#include "timewidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPalette>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = 0);

signals:

public slots:

private:
    Timewidget *time;
    UpWidget *topWidget;
    DownWidget *bottomWidget;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QPalette palette;

};

#endif // MAINWIDGET_H
