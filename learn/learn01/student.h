#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = 0);

signals:

public slots:
    void treat();  // 槽函数
    void treat(QString);  // 槽函数
};

#endif // STUDENT_H
