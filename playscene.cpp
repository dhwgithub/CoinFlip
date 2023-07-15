#include "playscene.h"
#include <QMenuBar>
#include <QDebug>
#include <mypushbuttom.h>
#include <QPainter>
#include <QLabel>
#include <mycoin.h>
#include <dataconfig.h>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QSound>


PlayScene::PlayScene(int levelNum) {
    this->levelIndex = levelNum;
    QString str = QString("第 %1 关").arg(levelNum);
    qDebug() << str;

    this->setFixedSize(320, 588);
    this->setWindowTitle(str);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));

    QMenuBar* menubar =  menuBar();
    setMenuBar(menubar);

    QMenu* startMenu = menubar->addMenu("菜单");

    QAction* quitAction = startMenu->addAction("退出游戏");
    connect(quitAction, &QAction::triggered, [=](){
        this->close();
    });

    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);
    MyPushButtom* backBtn = new MyPushButtom(":/res/BackButton.png",":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width()-backBtn->width()-20, this->height()-backBtn->height()-20);
    connect(backBtn, &QPushButton::clicked, [=](){
        backSound->play();

        emit this->selectLevelScene();
    });

    // 设置关卡提示
    QLabel* label = new QLabel;
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString labelText = QString("Level:%1").arg(levelNum);
    label->setText(labelText);
    label->setGeometry(30, this->height() - 60, 200, 50);

    // 从初始化关卡数据
    dataConfig config;
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    // 胜利标识图片
    QLabel* winLabel = new QLabel;
    QPixmap tmpPix;
    tmpPix.load(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0, 0, tmpPix.width(), tmpPix.height());
    winLabel->setPixmap(tmpPix);
    winLabel->setParent(this);
    winLabel->move( (this->width() - tmpPix.width())*0.5 , -tmpPix.height());

    QSound *flipSound = new QSound(":/res/ConFlipSound.wav",this);
    QSound *winSound = new QSound(":/res/LevelWinSound.wav",this);


    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            // 设置游戏背景
            QPixmap pix = QPixmap(":/res/BoardNode.png");
            QLabel* label = new QLabel;
            label->setGeometry(0, 0, pix.width(), pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57 + i*50, 200 + j*50);

            QString str;
            if (this->gameArray[i][j] == 1) {
                str = ":/res/Coin0001.png";
            }
            else {
                str = ":/res/Coin0008.png";
            }
            MyCoin *coin = new MyCoin(str);
            coin->setParent(label);
            coin->move(2, 2);


            coin->posX = i;
            coin->posY = j;
            coin->flag = this->gameArray[i][j];
            coins[i][j] = coin;

            connect(coin, &MyCoin::clicked, [=](){
                flipSound->play();

                coin->changeFlag();
                for (int k = 0; k < 4; ++ k) {
                    int x = coin->posX + dir[k][0];
                    int y = coin->posY + dir[k][1];
                    if (x > 3 || x < 0 || y < 0 || y > 3) continue;
                    coins[x][y]->changeFlag();
                }

                bool isWin = true;
                for(int u = 0; u < 4 && isWin; u++){
                    for(int v = 0; v < 4 && isWin; v++){
                        isWin &= this->coins[u][v]->flag;
                    }
                }
                if (isWin) {
                    winSound->play();

                    for(int u = 0; u < 4; u++){
                        for(int v = 0; v < 4; v++){
                            coins[u][v]->isWin = true;
                        }
                    }

                    // 胜利展示
                    QPropertyAnimation* ani = new QPropertyAnimation(winLabel, "geometry");
                    ani->setDuration(1000);
                    ani->setStartValue(QRect(winLabel->x(), winLabel->y(),
                                             winLabel->width(), winLabel->height()));
                    ani->setEndValue(QRect(winLabel->x(), winLabel->y() + 154,
                                           winLabel->width(),winLabel->height()));
                    ani->setEasingCurve(QEasingCurve::OutBounce);
                    ani->start();
                }
            });

        }
    }

}

void PlayScene::paintEvent(QPaintEvent *){
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");

    QPainter painter(this);
    painter.drawPixmap(0, 0,
        this->width(), this->height(),
        pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap(this->width() * 0.5 - pix.width() * 0.6, 40,
        pix.width() * 1.2, pix.height() * 1.2,
        pix);
}
