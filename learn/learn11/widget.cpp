#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    QPixmap pix(300, 300);
//    pix.fill(Qt::white);

//    QPainter painter(&pix);
//    painter.setPen(QPen(Qt::green));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    pix.save("D:\\MyDataFiles\\QT\\learn06\\pix.png");



//    QImage img(300, 300, QImage::Format_RGB32);
//    img.fill(Qt::white);

//    QPainter painter(&img);
//    painter.setPen(QPen(Qt::blue));
//    painter.drawEllipse(QPoint(150, 150), 100, 100);

//    img.save("D:\\MyDataFiles\\QT\\learn06\\img.png");


    // QPicture绘图工具，可以记录所有绘图操作
    QPicture pic;
    QPainter painter;
    painter.begin(&pic);
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QPoint(150, 150), 100, 100);
    painter.end();
    pic.save("D:\\MyDataFiles\\QT\\learn06\\pic.dhw");
}

void Widget::paintEvent(QPaintEvent *) {
//    QPainter painter(this);

//    QImage img;
//    img.load(":/img/BingWallpaper.jpg");

//    for (int i = 50; i < 100; ++ i) {
//        for (int j = 50; j < 100; ++ j) {
//            QRgb val = qRgb(255, 0, 0);
//            img.setPixel(i, j, val);
//        }
//    }
//    painter.drawImage(0, 0, img);



    // QPicture 重现绘图
    QPainter painter(this);
    QPicture pic;
    pic.load("D:\\MyDataFiles\\QT\\learn06\\pic.dhw");
    painter.drawPicture(0, 0, pic);
}

Widget::~Widget()
{
    delete ui;
}
