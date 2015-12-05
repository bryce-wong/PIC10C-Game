#include "mainwindow.h"
#include "gameboard2.h"
#include "player.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QImage>
#include <QGraphicsScene>
#include <QPixmap>

GameBoard2* board;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

void MainWindow::easy_game_begin() {
    board = new GameBoard2(this, true, false, false);
    this->setCentralWidget(board);
    this->setFixedSize(600,700);
    board->show();
    //QGraphicsView* view = new QGraphicsView(scene);
    //view->show();
}

void MainWindow::medium_game_begin() {
    board = new GameBoard2(this, false, true, false);
    this->setCentralWidget(board);
    this->setFixedSize(600,700);
    board->show();
}

void MainWindow::hard_game_begin() {
    board = new GameBoard2(this, false, false, true);
    this->setCentralWidget(board);
    this->setFixedSize(600,700);
    board->show();
}

void MainWindow::instructions1(){
    read = new instructions(this);
    read->show();
}

/**void MainWindow::game_over() {

    // Take the current board game out of the central widget of MainWindow
    QWidget* wid = this->centralWidget();
    wid->setParent(nullptr);
    // Line above will delete the widget gracefully (no memory errors)

    // Display something which says that you lost, maybe display high score.
    QLabel* loser = new QLabel();
    QString fileName5(":/pictures/Pictures/Screenshots/star.png");
    star_image = new QPixmap(fileName5);
    loser->setPixmap(*star_image);
    QHBoxLayout* loser_layout = new QHBoxLayout(wid);
    loser_layout->addWidget(loser);
    wid->setLayout(loser_layout);

    // Reset the MainWindow with the initial startup screen
    ui->setupUi(this);


}*/

MainWindow::~MainWindow()
{
    delete ui;
}
