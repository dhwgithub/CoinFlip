#include "mylable.h"
#include <QDebug>
#include <QMouseEvent>

MyLable::MyLable(QWidget *parent) :
    QLabel(parent)
{
    // 设置鼠标追踪
    setMouseTracking(true);

}

void MyLable::mousePressEvent(QMouseEvent * event) {
//    if (event->button() == Qt::LeftButton) {
        QString str = QString("鼠标按下了 x=%1, y=%2, globalX=%3")
                .arg(event->x()).arg(event->y()).arg(event->globalX());
        qDebug() << str;
//    }
}

void MyLable::mouseMoveEvent(QMouseEvent * event) {
//    if (event->buttons() & Qt::LeftButton) {
        QString str = QString("鼠标移动了 x=%1, y=%2, globalX=%3")
                .arg(event->x()).arg(event->y()).arg(event->globalX());
        qDebug() << str;
//    }
}


bool MyLable::event(QEvent *e) {
    if (e->type() == QEvent::MouseButtonPress) {
        QMouseEvent *event = static_cast<QMouseEvent *>(e);
        QString str = QString("EVENT::鼠标按下了 x=%1, y=%2, globalX=%3")
                .arg(event->x()).arg(event->y()).arg(event->globalX());
        qDebug() << str;

        return true;
    }
    return QLabel::event(e);  // 其他事件默认处理
}

