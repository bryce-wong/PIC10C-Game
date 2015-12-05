#include "powerup.h"
#include "ui_powerup.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "gameboard2.h"
#include "player.h"

extern GameBoard2* board;

powerup::powerup(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
    //ui(new Ui::Rain)
{
    applesound = new QMediaPlayer();
    applesound->setMedia(QUrl("qrc:/sounds/applecrunch.mp3"));
    //ui->setupUi(this);
    int random_num = rand()%400;
    setPos(random_num, 0);

    //draw powerup
    QString fileName1(":/pictures/Pictures/powerup.png");
    powerup_image = new QPixmap(fileName1);
    setPixmap(*powerup_image);

    //make a timer to connect to move()
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(move()));

    //start timer
    timer->start(50);
}

void powerup::backToFalse(){
    //sets caughtpower back to false
    board->caughtpower=false;
}

void powerup::move(){
    //if powerup is caught by the basket, destroy powerup
    QList<QGraphicsItem*> caught_powerup = collidingItems();
    for (int i=0, n=caught_powerup.size(); i<n; ++i){
        if(typeid(*(caught_powerup[i]))==typeid(player)){
            //cause chickens and horses to slow down
            board->caughtpower = true;
            if(applesound->state()==QMediaPlayer::PlayingState){
                applesound->setPosition(0);
            }
            else if(applesound->state()==QMediaPlayer::StoppedState){
                applesound->play();
            }
            //remove apple
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    //if they hit the bottom of the screen delete em
    if(pos().y()>600){
        scene()->removeItem(this);
        delete this;
        return;
    }

    //move powerup down
    setPos(x(),y()+15);


}

powerup::~powerup()
{
    //delete ui;
}
