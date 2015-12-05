#include "chicken.h"
#include "ui_chicken.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "gameboard2.h"
#include "player.h"
#include <qglobal.h>
#include <QTime>

extern GameBoard2* board;

chicken::chicken(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
    //ui(new Ui::Rain)
{
    //set speed back to normal everytime a new chicken appears
    board->caughtpower=false;

    chickensound = new QMediaPlayer();
    chickensound->setMedia(QUrl("qrc:/sounds/chickencluck.mp3"));
    //ui->setupUi(this);

    int random_num = qrand()%400;
    setPos(random_num, -550);

    //draw chicken
    QString fileName1(":/pictures/Pictures/chicken.png");
    chicken_image = new QPixmap(fileName1);
    setPixmap(*chicken_image);

    //make a timer to connect to move()
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(move()));

    //start timer
    timer->start(100);
}

void chicken::move(){
    //if chicken is caught by the basket, destroy chicken and lose a life
    QList<QGraphicsItem*> caught_chicken = collidingItems();
    for (int i=0, n=caught_chicken.size(); i<n; ++i){
        if(typeid(*(caught_chicken[i]))==typeid(player)){
            //play chicken sound
            if(chickensound->state()==QMediaPlayer::PlayingState){
                chickensound->setPosition(0);
            }
            else if(chickensound->state()==QMediaPlayer::StoppedState){
                chickensound->play();
            }
            //remove chicken
            scene()->removeItem(this);
            delete this;
            //decrease score
            board->myLives->decrease();
            return;
        }
    }

    //if they hit the bottom of the screen delete em
    if(pos().y()>600){
        scene()->removeItem(this);
        delete this;
        return;
    }

    //move chicken down (move slower if a power up is caught)
    if(board->caughtpower==true){
        setPos(x(),y()+1);
    }else setPos(x(),y()+15);


}

chicken::~chicken()
{
    //delete ui;
}
