#include <QTimer>
#include "horse.h"
#include "ui_horse.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "gameboard2.h"
#include <qglobal.h>
#include <QTime>

extern GameBoard2* board;

horse::horse(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
    //ui(new Ui::Rain)
{

    horsesound = new QMediaPlayer();
    horsesound->setMedia(QUrl("qrc:/sounds/horseneigh.wav"));

    //ui->setupUi(this);
    int random_num = qrand()%400;
    setPos(random_num, -550);

    //draw horse
    QString fileName1(":/pictures/Pictures/horse.png");
    horse_image = new QPixmap(fileName1);
    setPixmap(*horse_image);

    //make a timer to connect to move()
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(move()));

    //start timer
    timer->start(100);
}

void horse::move(){
    //if horse is caught by the basket, destroy horse and lose a life
    QList<QGraphicsItem*> caught_horse = collidingItems();
    for (int i=0, n=caught_horse.size(); i<n; ++i){
        if(typeid(*(caught_horse[i]))==typeid(player)){
            //play horse sound
            if(horsesound->state()==QMediaPlayer::PlayingState){
                horsesound->setPosition(0);
            }
            else if(horsesound->state()==QMediaPlayer::StoppedState){
                horsesound->play();
            }
            //remove horse
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

    //move horse down (move slower if a power up is caught)
    if(board->caughtpower==true){
        setPos(x(),y()+1);
    }else setPos(x(),y()+15);
}


horse::~horse()
{
    //delete ui;
}
