#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <teacher.h>
#include <student.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Teacher *te;
    Student *st;
    void classIsOver();
};

#endif // MAINWINDOW_H
