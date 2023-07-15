#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(600, 400);

    // 设置菜单栏，最多有一个
    QMenuBar *bar = menuBar();
    setMenuBar(bar);

    // 1. 创建菜单
    QMenu *fileMenu = bar->addMenu("文件");
    QMenu *editMenu = bar->addMenu("编辑");

    // 创建菜单项
    QAction *createAction = fileMenu->addAction("新建");
    fileMenu->addSeparator();
    QAction *openAction = fileMenu->addAction("打开");

    // 2. 工具栏，可以有多个
    QToolBar *toolBar = new QToolBar(this);
    addToolBar(Qt::LeftToolBarArea, toolBar);
    toolBar->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    toolBar->setFloatable(false);
//    toolBar->setMovable(false);  // 设置移动总开关
    toolBar->addAction(createAction);
    toolBar->addSeparator();
    toolBar->addAction(openAction);

    QPushButton *btn = new QPushButton("按钮", this);
    toolBar->addWidget(btn);

    // 3. 状态栏 最多一个
    QStatusBar *stBar = statusBar();
    setStatusBar(stBar);
    QLabel *label = new QLabel("提示信息", this);
    stBar->addWidget(label);
    QLabel *label2 = new QLabel("右侧的提示信息", this);
    stBar->addPermanentWidget(label2);

    // 4. 设置中心部件 只能一个
    QTextEdit *edit = new QTextEdit(this);
    setCentralWidget(edit);

    // 5. 铆接部件（浮动窗口 可以多个
    QDockWidget *dockWidget = new QDockWidget("浮动", this);
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);
    dockWidget->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

}


MainWindow::~MainWindow()
{

}
