#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void timerEvent(QTimerEvent *);

    int id1, id2;  // 定时器id

    bool event(QEvent *e);
    bool eventFilter(QObject *, QEvent *);  // 事件过滤器（最高层拦截）

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
