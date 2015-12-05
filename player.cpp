#include "player.h"
#include "ui_player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "catRain.h"
#include "dograin.h"
#include "horse.h"
#include "chicken.h"
#include <QList>
#include "gameboard2.h"
#include "mainwindow.h"
#include "powerup.h"
#include <QTimer>

//extern GameBoard2* board; //external var that we can change score on

player::player(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    releasePower=false;

    // set player graphic
    QString fileName(":/pictures/Pictures/basket.png");
    player_image = new QPixmap(fileName);
    setPixmap(*player_image);

    //allowes a powerup every 23 seconds
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),this,SLOT(rainPower()));
    timer->start(23000);
}

player::~player()
{
    //delete ui;
}

void player::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt ::Key_Left){
        if (pos().x()>10)
      setPos(x()-15, y());
    }
    else if(event->key()==Qt::Key_Right){
        if(pos().x()+100<570)
      setPos(x()+15, y());
    }
}

void player::rainingEasy(){
    //create a catRain
    catRain* cat = new catRain();
    scene()->addItem(cat);
    //create a dogRain
    dogRain* dog = new dogRain();
    scene()->addItem(dog);
}

void player::rainingMedium(){
    //create a horse
    horse* horserain = new horse();
    scene()->addItem(horserain);
    //create a powerup
    if(this->releasePower == true){
        powerup* rainapples = new powerup();
        scene()->addItem(rainapples);
    }
    releasePower=false;
}

void player::rainingHard(){
    //create a chicken
    chicken* chickenrain = new chicken();
    scene()->addItem(chickenrain);
}

//allows a powerup every 23 seconds
void player::rainPower(){
    releasePower = true;
}
