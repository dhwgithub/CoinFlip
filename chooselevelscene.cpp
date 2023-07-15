#include "chooselevelscene.h"
#include "ui_chooselevelscene.h"
#include <QPainter>
#include <QDebug>
#include <QTimer>
#include <MyPushButtom.h>
#include <QLabel>
#include <QSound>

ChooseLevelScene::ChooseLevelScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChooseLevelScene)
{
    ui->setupUi(this);

    this->setFixedSize(320, 588);
    this->setWindowTitle("关卡选择");
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));


    connect(ui->actionClose, &QAction::triggered, [=](){
        this->close();
    });

    // 音效设置
    QSound *chooseSound = new QSound(":/res/TapButtonSound.wav",this);
    QSound *backSound = new QSound(":/res/BackButtonSound.wav",this);


    MyPushButtom* backBtn = new MyPushButtom(":/res/BackButton.png",
                                     ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() - 20,
                  this->height() - backBtn->height() - 20);

    connect(backBtn, &QPushButton::clicked, [=](){
        backSound->play();
        emit this->chooseBackScene();
    });


    for(int i = 0; i < 20; i++){
        MyPushButtom* selectBtn = new MyPushButtom(":/res/LevelIcon.png");
        selectBtn->setParent(this);
        selectBtn->move(30 + i % 4 * 70, 180 + i / 4 * 70);

        connect(selectBtn, &QPushButton::clicked,[=](){
            chooseSound->play();

            QString str = QString("No. %1 was selected.").arg(i+1);
            qDebug() << str;

            // 进入游戏场景
            this->hide();
            this->playScene = new PlayScene(i+1);
            playScene->setGeometry(this->geometry());
            this->playScene->show();

            connect(this->playScene, &PlayScene::selectLevelScene, [=](){
                this->setGeometry(playScene->geometry());
                this->show();
                delete playScene;
                playScene = NULL;
            });
        });

        QLabel* label = new QLabel;
        label->setParent(selectBtn);
        label->setFixedSize(selectBtn->width(), selectBtn->height());
        label->setText(QString::number(i+1));
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        // 鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }

}

void ChooseLevelScene::paintEvent(QPaintEvent *){
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

ChooseLevelScene::~ChooseLevelScene()
{
    delete ui;
}
