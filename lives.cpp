#include "lives.h"
#include "ui_lives.h"
#include <QFont>
#include "mainwindow.h"

//extern MainWindow* window;
extern GameBoard2* board;

Lives::Lives(QGraphicsItem *parent) :
    QGraphicsTextItem(parent)
    //ui(new Ui::Score)
{
    //ui->setupUi(this);
    //lives starts at 3
    lives = 3;

    //draw lives
    setPlainText(QString("Lives: ")+QString::number(lives));
    setFont(QFont("Helvetica", 12));
}

Lives::~Lives()
{
    //delete score;
}

void Lives::decrease(){
    if (lives<2){
       board->game_over();
       return;
    }
    lives--;
    setPlainText(QString("Lives: ")+QString::number(lives));
}

