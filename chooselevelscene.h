#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <playscene.h>
namespace Ui {
class ChooseLevelScene;
}

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChooseLevelScene(QWidget *parent = 0);
    ~ChooseLevelScene();

    void paintEvent(QPaintEvent *);
    PlayScene* playScene = NULL;

signals:
    void chooseBackScene();

private:
    Ui::ChooseLevelScene *ui;
};

#endif // CHOOSELEVELSCENE_H
