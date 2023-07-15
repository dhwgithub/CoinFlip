#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>


class MyCoin : public QPushButton
{
    Q_OBJECT
public:
//    explicit MyCoin(QWidget *parent = 0);
    MyCoin(QString btnImg);
    void mousePressEvent(QMouseEvent *e);

    int posX, posY;
    bool flag;

    void changeFlag();
    QTimer* timer1;
    QTimer* timer2;
    int min = 1;
    int max = 8;

    bool isAnimation;
    bool isWin;

signals:

public slots:

};

#endif // MYCOIN_H
