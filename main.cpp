#include "mainwindow.h"
#include "player.h"
#include <QApplication>

//GameBoard2* board;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.setWindowTitle("It's Raining Cats and Dogs!");

    w.show();

    return a.exec();
}
