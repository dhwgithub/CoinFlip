#ifndef MYLABLE_H
#define MYLABLE_H

#include <QLabel>

class MyLable : public QLabel
{
    Q_OBJECT
public:
    explicit MyLable(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);

    bool event(QEvent *e);  // 事件分发器
signals:

public slots:

};

#endif // MYLABLE_H
