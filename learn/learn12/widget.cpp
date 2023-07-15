#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, [=](){
        QString path = QFileDialog::getOpenFileName(this,
                                                    "打开文件",
                                                    "C:\\Users\\DHW\\Desktop");
        ui->lineEdit->setText(path);

        QTextCodec *codec = QTextCodec::codecForName("utf8");

        QFile file(path);
        file.open(QIODevice::ReadOnly);

        QByteArray array ;
//        array= file.readAll();
        while (!file.atEnd()) {
            array += file.readLine();
        }

        ui->textEdit->setText(codec->toUnicode(array));
        file.close();


//        file.open(QIODevice::Append);
//        file.write("我写了条数据");
//        file.close();


        QFileInfo info(path);
        qDebug() << "大小(字节): " << info.size()
                    << "后缀名: " << info.suffix()
                       << "文件名称: " << info.fileName()
                          << "文件路径: " << info.filePath();
        qDebug() << "创建日期: " << info.created().toString("yyyy/MM/dd hh:mm:ss");
        qDebug() << "最后修改日期: " << info.lastModified().toString("yyyy/MM/dd hh:mm:ss");

    });
}

Widget::~Widget()
{
    delete ui;
}
