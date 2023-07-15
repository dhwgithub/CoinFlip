#include "mycoin.h"
#include <QDebug>


MyCoin::MyCoin(QString btnImg) {
    QPixmap pix;
    bool res = pix.load(btnImg);
    if(!res){
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug() << str;
        return;
    }
    this->setFixedSize(pix.width(), pix.height());

    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));

    isAnimation = false;
    isWin = false;

    // 初始化定时器
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    // 监听翻转定时器
    connect(timer1, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->min++);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        // 翻转完成
        if(this->min > this->max){
            this->min = 1;
            timer1->stop();
            isAnimation = false;
        }
    });
    connect(timer2, &QTimer::timeout, [=](){
        QPixmap pix;
        QString str = QString(":/res/Coin000%1.png").arg(this->max--);
        pix.load(str);

        this->setFixedSize(pix.width(), pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(), pix.height()));
        // 翻转完成
        if(this->min > this->max){
            this->max = 8;
            timer2->stop();
            isAnimation = false;
        }
    });
}

void MyCoin::mousePressEvent(QMouseEvent *e) {
    if (this->isAnimation || this->isWin) {
        return;
    }
    else {
        QPushButton::mousePressEvent(e);
    }
}

void MyCoin::changeFlag() {
    if(this->flag){
        timer1->start(30);
        this->flag = false;
        isAnimation = true;
    }else{
        timer2->start(30);
        this->flag = true;
        isAnimation = true;
    }
}
