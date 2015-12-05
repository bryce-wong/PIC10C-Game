#include "level.h"
#include "ui_level.h"
#include <QFont>
#include "gameboard2.h"

extern GameBoard2* board;

level::level(QGraphicsItem *parent) :
    QGraphicsTextItem(parent)
    //ui(new Ui::Score)
{
    levelSound = new QMediaPlayer();
    levelSound->setMedia(QUrl("qrc:/sounds/ding.mp3"));
    //ui->setupUi(this);
    //score starts at 0
    levelnum = 1;

    //draw score
    setPlainText(QString("Level: ")+QString::number(levelnum));
    setFont(QFont("Helvetica", 12));
}

level::~level()
{
    //delete score;
}

void level::increase(){
    //every 20 points increase level
    if(board->officialScore%20 == 0){
        levelnum++;
        setPlainText(QString("Level: ")+QString::number(levelnum));
        //play new level sound
        if(levelSound->state()==QMediaPlayer::PlayingState){
            levelSound->setPosition(0);
        }
        else if(levelSound->state()==QMediaPlayer::StoppedState){
            levelSound->play();
        }
        board->interval += 50;
    }
}
