#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) :
    QObject(parent)
{
}

void Student::treat() {
    qDebug() << "请老师吃饭";
}

void Student::treat(QString foodName) {
    // QString -> char*   ==> foodName.toUtf8().data()
    qDebug() << "老师要吃" << foodName.toUtf8().data();
}
