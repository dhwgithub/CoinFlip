#include "mypushbuttom.h"
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>

//MyPushButtom::MyPushButtom(QWidget *parent) :
//    QWidget(parent)
//{
//}

void MyPushButtom::setImg(QString imgPath) {
    QPixmap pix;
    bool ret = pix.load(imgPath);
    if (!ret) {
        qDebug() << "图片加载失败";
        return ;
    }

    this->setFixedSize(pix.width(), pix.height());
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}

MyPushButtom::MyPushButtom(QString normalImg, QString pressImg) {
    this->normalImg = normalImg;
    this->pressImg = pressImg;

    this->setImg(normalImg);
}

void MyPushButtom::zoom(bool flag) {
    QPropertyAnimation *animation = new QPropertyAnimation(this,
                                                           "geometry");
    animation->setDuration(200);

    if (flag) {
        animation->setStartValue(QRect(this->x(), this->y(),
                                       this->width(), this->height()));
        animation->setEndValue(QRect(this->x(), this->y() + 10,
                                     this->width(), this->height()));
    }
    else {
        animation->setStartValue(QRect(this->x(), this->y() + 10,
                                       this->width(), this->height()));
        animation->setEndValue(QRect(this->x(), this->y(),
                                     this->width(), this->height()));
    }
    animation->setEasingCurve(QEasingCurve::OutBounce);  // 设置弹跳曲线
    animation->start();
}

void MyPushButtom::mousePressEvent(QMouseEvent *e){
    if(this->pressImg != ""){
        this->setImg(this->pressImg);
    }

    return QPushButton::mousePressEvent(e);
}

void MyPushButtom::mouseReleaseEvent(QMouseEvent *e){
    if(this->pressImg != ""){
        this->setImg(this->normalImg);
    }

    return QPushButton::mouseReleaseEvent(e);
}
