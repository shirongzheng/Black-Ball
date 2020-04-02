#ifndef UPWIDGET_H
#define UPWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QString>
#include <QPaintEvent>
#include <QPainter>


class UpWidget : public QWidget
{
    Q_OBJECT
public:
    explicit UpWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    void myscore();
private:
    QLabel *labelScore;
    QString string;
    int upscore;
    QPalette palette;
};

#endif // UPWIDGET_H

