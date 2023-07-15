#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 添加QT资源  ": + 前缀名 + 文件名"
    ui->actionOpen->setIcon(QIcon(":/pre/img/BingWallpaper.jpg"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
