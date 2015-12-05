#include <QTimer>
#include "dogRain.h"
#include "ui_dograin.h"
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "gameboard2.h"
#include <qglobal.h>
#include <QTime>

extern GameBoard2* board;

dogRain::dogRain(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
    //ui(new Ui::Rain)
{
    dogsound = new QMediaPlayer();
    dogsound->setMedia(QUrl("qrc:/sounds/dogwoof.wav"));

    //ui->setupUi(this);
    int random_num = qrand()%500;
    setPos(random_num, 0);

    //draw dog
    QString fileName1(":/pictures/Pictures/dog.png");
    dog_image = new QPixmap(fileName1);
    setPixmap(*dog_image);

    //make a timer to connect to move()
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(move()));

    //start timer
    timer->start(100);
}

void dogRain::move(){
    //if dogRain is caught by the basket, destroy dogRain
    QList<QGraphicsItem*> caught_dog = collidingItems();
    for (int i=0, n=caught_dog.size(); i<n; ++i){
        if(typeid(*(caught_dog[i]))==typeid(player)){
            //play dog sound
            if(dogsound->state()==QMediaPlayer::PlayingState){
                dogsound->setPosition(0);
            }
            else if(dogsound->state()==QMediaPlayer::StoppedState){
                dogsound->play();
            }
            //increase score
            board->myScore->increase();
            //increase level if appropriate
            board->myLevel->increase();
            //remove dog from the scene
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    //if they hit the bottom of the screen
    //blah blah blah board->myLives->decrease();
    if(pos().y()>600){
        scene()->removeItem(this);
        delete this;
        board->myLives->decrease();
        return;
    }
    //move dog down (move slower if a power up is caught)
    if(board->caughtpower==true){
        setPos(x(),y()+4);
    }else setPos(x(),y()+8);
}


dogRain::~dogRain()
{
    //delete ui;
}
