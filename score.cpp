#include "score.h"
#include "ui_score.h"
#include <QFont>
#include "gameboard2.h"

extern GameBoard2* board;

Score::Score(QGraphicsItem *parent) :
    QGraphicsTextItem(parent)
    //ui(new Ui::Score)
{
    //ui->setupUi(this);
    //score starts at 0
    score = 0;

    //draw score
    setPlainText(QString("Score: ")+QString::number(score));
    setFont(QFont("Helvetica", 12));
}

Score::~Score()
{
    //delete score;
}

void Score::increase(){
    score++;
    setPlainText(QString("Score: ")+QString::number(score));
    board->officialScore = score;
}
