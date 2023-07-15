#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <mycoin.h>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
//    explicit PlayScene(QWidget *parent = 0);
    PlayScene(int levelNum);
    int levelIndex;
    void paintEvent(QPaintEvent *);
    int gameArray[4][4];
    MyCoin* coins[4][4];
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

signals:

    void selectLevelScene();

public slots:

};

#endif // PLAYSCENE_H
