#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_show, &QPushButton::clicked, [=](){
       qDebug() << ui->Mywidget->getNum();
    });

    connect(ui->btn_half, &QPushButton::clicked, [=](){
        ui->Mywidget->setNum(50);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
