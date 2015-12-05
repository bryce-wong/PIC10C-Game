#include "catRain.h"
#include "ui_catrain.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "gameboard2.h"
#include "player.h"
#include <qglobal.h>
#include <QTime>

extern GameBoard2* board;

catRain::catRain(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
    //ui(new Ui::Rain)
{

    catsound = new QMediaPlayer();
    catsound->setMedia(QUrl("qrc:/sounds/catmeow.wav"));

    //ui->setupUi(this);
    //create a seed for random
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    int random_num = qrand()%500;
    setPos(random_num, 0);

    //draw cat
    QString fileName1(":/pictures/Pictures/cat.png");
    cat_image = new QPixmap(fileName1);
    setPixmap(*cat_image);

    //make a timer to connect to move()
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,SLOT(move()));

    //start timer
    timer->start(50);
}

void catRain::move(){
    //if catRain is caught by the basket, destroy catRain
    QList<QGraphicsItem*> caught_cat = collidingItems();
    for (int i=0, n=caught_cat.size(); i<n; ++i){
        if(typeid(*(caught_cat[i]))==typeid(player)){
            //play cat sound
            if(catsound->state()==QMediaPlayer::PlayingState){
                catsound->setPosition(0);
            }
            else if(catsound->state()==QMediaPlayer::StoppedState){
                catsound->play();
            }
            //increase score
            board->myScore->increase();
            //increase level if appropriate
            board->myLevel->increase();
            //remove cat from the scene
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

    //move cat down (move slower if a power up is caught)
    if(board->caughtpower==true){
        setPos(x(),y()+4);
    }else setPos(x(),y()+8);
}


catRain::~catRain()
{
    //delete ui;
}
