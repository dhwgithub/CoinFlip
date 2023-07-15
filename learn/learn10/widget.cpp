#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        posX += 10;
        update();  // 更新绘图
    });
}

void Widget::paintEvent(QPaintEvent *) {
//    QPainter painter(this);

//    QPen pen(QColor(255, 0, 0));
//    pen.setWidth(3);
//    pen.setStyle(Qt::DotLine);
//    painter.setPen(pen);

//    QBrush brush(Qt::green);
//    brush.setStyle(Qt::Dense7Pattern);
//    painter.setBrush(brush);

//    painter.drawLine(QPoint(0, 0), QPoint(100, 100));
//    painter.drawEllipse(QPoint(200, 200), 60, 40);
//    painter.drawRect(QRect(20, 30, 50, 30));
//    painter.drawText(QRect(10, 200, 50, 50),
//                     "好好学习，天天向上");



//    QPainter painter(this);
//    painter.drawEllipse(QPoint(100, 50), 50, 50);
//    painter.setRenderHint(QPainter::Antialiasing); // 抗锯齿
//    painter.drawEllipse(QPoint(200, 50), 50, 50);

//    painter.drawRect(QRect(20, 20, 50, 50));
//    painter.translate(100, 0);  // 相当于移动画家
//    painter.save();
//    painter.drawRect(QRect(20, 20, 50, 50));
//    painter.translate(100, 0);
//    painter.restore();
//    painter.drawRect(QRect(20, 20, 50, 50));



    QPainter painter(this);
    if (posX > this->width()) {
        posX = 0;
    }
    painter.drawPixmap(posX, 50, QPixmap(":/img/BingWallpaper.jpg"));
}

Widget::~Widget()
{
    delete ui;
}
