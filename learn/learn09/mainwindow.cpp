#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // 第一种定时器
    id1 = startTimer(1000);
    id2 = startTimer(2000);

    // 第二种定时器
    QTimer *time = new QTimer(this);
    time->start(500);
    connect(time, &QTimer::timeout, [=](){
        static int num = 1;
        ui->label_time3->setText(QString::number(num++));
    });

    // 安装事件过滤器
    ui->label_time->installEventFilter(this);

}

void MainWindow::timerEvent(QTimerEvent *ev) {

    if (ev->timerId() == id1) {
        static int num = 1;
        ui->label_time->setText(QString::number(num++));
    }
    else if (ev->timerId() == id2) {
        static int num2 = 1;
        ui->label_time2->setText(QString::number(num2++));
    }
}

bool MainWindow::event(QEvent *e) {
    if (e->type() == QEvent::MouseButtonPress) {
        QMouseEvent *event = static_cast<QMouseEvent *>(e);
        QString str = QString("EVENT::榧犳爣鎸変笅浜?x=%1, y=%2, globalX=%3")
                .arg(event->x()).arg(event->y()).arg(event->globalX());
        qDebug() << str;

        return true;
    }
    return QWidget::event(e);  // 鍏朵粬浜嬩欢榛樿澶勭悊
}

bool MainWindow::eventFilter(QObject *obj, QEvent *e) {
    if (obj == ui->label_time) {
        if (e->type() == QEvent::MouseButtonPress) {
            QMouseEvent *event = static_cast<QMouseEvent *>(e);
            QString str = QString("eventFilter::鼠标按下了 x=%1, y=%2, globalX=%3")
                    .arg(event->x()).arg(event->y()).arg(event->globalX());
            qDebug() << str;

            return true;
        }

    }
    return QWidget::eventFilter(obj, e);
}

MainWindow::~MainWindow()
{
    delete ui;
}
