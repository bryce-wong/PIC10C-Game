#include "ui_gameboard2.h"
#include "gameboard2.h"
#include "player.h"
#include <QPushButton>
#include <QPixmap>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "score.h"
#include <QMediaPlayer>
#include <iostream>

//GameBoard2::GameBoard2(QWidget *parent) :
    //QWidget(parent),
    //ui(new Ui::GameBoard2)
GameBoard2::GameBoard2(QWidget* parent, bool easy, bool medium, bool hard)

{
    //ui->setupUi(this);
    //set caught power ups to false
    caughtpower = false;

    //set final score initially to 0
    officialScore = 0;

    //create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,700);
    setBackgroundBrush(QBrush(QImage(":/pictures/Pictures/background.jpg")));

    //set the scene
    setScene(scene);

    //create the player
    myPlayer = new player();
    myPlayer->setPos(350,600);
    myPlayer->setFlag(QGraphicsItem::ItemIsFocusable);
    myPlayer->setFocus();
    scene->addItem(myPlayer);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create score
    myScore = new Score();
    myScore->setPos(10,40);
    scene->addItem(myScore);

    //create level
    myLevel = new level();
    myLevel->setPos(250,40);
    scene->addItem(myLevel);

    //create lives
    myLives = new Lives();
    myLives->setPos(500,40);
    scene->addItem(myLives);

    //start rain
    interval = 4000;
    QTimer* timer = new QTimer();
    QTimer* timer2 = new QTimer();
    QTimer* timer3 = new QTimer();
    if (easy){
        QObject::connect(timer, SIGNAL(timeout()),myPlayer,SLOT(rainingEasy()));
    } else if (medium){
        QObject::connect(timer, SIGNAL(timeout()),myPlayer,SLOT(rainingEasy()));
        QObject::connect(timer2, SIGNAL(timeout()),myPlayer,SLOT(rainingMedium()));
    } else if (hard){
        QObject::connect(timer, SIGNAL(timeout()),myPlayer,SLOT(rainingEasy()));
        QObject::connect(timer2, SIGNAL(timeout()),myPlayer,SLOT(rainingMedium()));
        QObject::connect(timer3, SIGNAL(timeout()),myPlayer,SLOT(rainingHard()));
    }
    timer->start(interval);
    timer2->start(8000);
    timer3->start(12000);

    //play background music
    QMediaPlayer* music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    music->play();

    //QGraphicsView* view = new QGraphicsView(scene);
    show();



    //this->show();

}

    GameBoard2::~GameBoard2()
    {
        delete scene;
    }

    void GameBoard2::game_over() {
        delete myPlayer;

        delete scene;

        scene = new QGraphicsScene(this);
        scene->setSceneRect(0,0,600,680);

        setScene(scene);

        setBackgroundBrush(QBrush(QImage(":/pictures/Pictures/Screenshots/star.png")));

        QGraphicsTextItem* printScore = new QGraphicsTextItem();
        printScore->setPlainText(QString("Your final score is: ")+QString::number(officialScore));
        printScore->setFont(QFont("Helvetica [Cronyx]", 30));

        //add final score to end screen
        printScore->setPos(80,100);
        scene->addItem(printScore);

        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    }
