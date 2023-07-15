#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    te = new Teacher(this);
    st = new Student(this);

//    // 链接信号和槽函数
//    connect(te, &Teacher::hungry, st, &Student::treat);
//    classIsOver();

    // 函数指针： 返回值类型(*指针名)(参数列表)
    void(Teacher:: *teaherSignal)(QString) = &Teacher::hungry;
    void(Student:: *StudentSlots)(QString) = &Student::treat;
    connect(te, teaherSignal, st, StudentSlots);  // 链接信号和槽函数
    classIsOver();

//    // 点击按钮触发下课
//    QPushButton *btn = new QPushButton("下课", this);
//    this->resize(600, 400);
//    //connect(btn, &QPushButton::clicked, this, &MainWindow::classIsOver);

//    // 信号链接信号（信号之间存在传递性） ==> 老师——学生  按钮——老师
//    void(Teacher:: *teaherSignal2)(void) = &Teacher::hungry;
//    void(Student:: *StudentSlots2)(void) = &Student::treat;
//    connect(te, teaherSignal2, st, StudentSlots2);
//    connect(btn, &QPushButton::clicked, te, teaherSignal2);

//    // 断开链接——参数列表直接复制即可
//    disconnect(te, teaherSignal2, st, StudentSlots2);

//    // lambda表达式使用，最后括号表示将其转换为函数进行调用，而不仅仅是表达式
//    [=](){
//        btn->setText("lambda");
//    }();

    // lambda使用，QT4版本不支持
    QPushButton *btn2 = new QPushButton("关闭", this);
    btn2->move(100, 0);
    connect(btn2, &QPushButton::clicked, this, [=](){
        this->close();
        emit te->hungry("麻辣烫");
    });
}

void MainWindow::classIsOver() {
    emit te->hungry();  // 触发信号
//    emit te->hungry("宫保鸡丁");
}

MainWindow::~MainWindow()
{
    delete ui;
}
