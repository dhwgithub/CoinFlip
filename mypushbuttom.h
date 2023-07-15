#ifndef MYPUSHBUTTOM_H
#define MYPUSHBUTTOM_H

#include <QWidget>
#include <QPushButton>

class MyPushButtom : public QPushButton
{
    Q_OBJECT

    void setImg(QString);

public:
//    explicit MyPushButtom(QWidget *parent = 0);

    MyPushButtom(QString normalImg, QString pressImg="");
    void zoom(bool);

    QString normalImg;
    QString pressImg;

    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);

signals:


public slots:

};

#endif // MYPUSHBUTTOM_H
