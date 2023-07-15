#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionNew, &QAction::triggered, [=](){
//        // 模态对话框（不可以对其他窗口进行操作）
//        QDialog dig(this);
//        dig.exec();
//        qDebug() << "模块对话框弹出";

//        // 非模态对话框（可以对其他窗口进行操作）
//        QDialog *dig2 = new QDialog(this);
//        dig2->show();
//        dig2->setAttribute(Qt::WA_DeleteOnClose);
//        qDebug() << "非模态对话框弹出";

        // 消息对话框
//        QMessageBox::critical(this, "critical对话框", "错误");

//        QMessageBox::information(this, "info", "信息");

//          if (QMessageBox::Save == QMessageBox::question(this, "ques", "提问",
//                                QMessageBox::Save | QMessageBox::Cancel,
//                                QMessageBox::Save)) {
//              qDebug() << "保存";
//          }
//          else {
//              qDebug() << "取消";
//          }

//          QMessageBox::warning(this, "warn", "警告");

//        QColor color = QColorDialog::getColor(QColor(255, 0, 0));
//        qDebug() << "r" << color.red();

//        QString st = QFileDialog::getOpenFileName(this, "打开文件", "", "(*.txt)");
//        qDebug() << st;

//        bool flag;  // 记录是否更改字体（手动选择是否选择）
//        QFont font = QFontDialog::getFont(&flag, QFont("华文彩云", 36));
//        qDebug() << flag;
//        qDebug() << "字体：" << font.family().toUtf8().data()
//                    << " 字号：" << font.pointSize()
//                       << " 是否加粗：" << font.bold()
//                          << " 是否倾斜：" << font.italic();

    });



}

MainWindow::~MainWindow()
{
    delete ui;
}
