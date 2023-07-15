#include "mainscene.h"
#include "ui_mainscene.h"
#include <mypushbuttom.h>
#include <QTimer>
#include <QTime>
#include <QSound>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    // 主窗口设置
    setFixedSize(320, 588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("翻金币");

    // 菜单栏设置
    connect(ui->actionQuit, &QAction::triggered, [=](){
        this->close();
    });

    // 主界面设置——开始界面
    MyPushButtom *startBtn = new MyPushButtom(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    startBtn->move(this->width() * 0.5 - startBtn->width() / 2,
                   this->height() * 0.7);

    choice = new ChooseLevelScene();

    connect(choice, &ChooseLevelScene::chooseBackScene, this, [=](){
        this->setGeometry(choice->geometry());
        choice->hide();
        this->show();
    });

    QSound *startSound = new QSound(":/res/myDouDZ.wav", this);
//    startSound->setLoops(-1);

    connect(startBtn, &MyPushButtom::clicked, [=](){
        startSound->play();

        // 弹起特效
        startBtn->zoom(true);
        startBtn->zoom(false);

        sleep(200);
        this->hide();
        choice->setGeometry(this->geometry());
        choice->show();

    });

}

void MainScene::sleep(int ms){
    QTime reachTime = QTime::currentTime().addMSecs(ms);
    while(QTime::currentTime() < reachTime){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 50);
    }
}

void MainScene::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width() * 0.6, pix.height() * 0.6);
    painter.drawPixmap(10, 30, pix);
}

MainScene::~MainScene()
{
    delete ui;
}
