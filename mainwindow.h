#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "instructions.h"
#include "gameboard2.h"
#include "player.h"

/*! \file mainwindow.h
 * \brief A documented mainwindow file
 * \namespace Ui
 */
namespace Ui {
class MainWindow;
}

//! An MainWindow class
/*!
 * \brief The MainWindow class.
 * Inherits from QMainWindow. Displays a MainWindow that shows the gameboard.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief easy_game_begin();
     * causes the easy difficulty of the board to be set up
     */
    void easy_game_begin();
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief medium_game_begin();
     * causes the medium difficulty of the board to be set up
     */
    void medium_game_begin();
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief hard_game_begin();
     * causes the hard difficulty of the board to be set up
     */
    void hard_game_begin();
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief instructions1();
     * causes the instructions window to be displayed
     */
    void instructions1();

public:
    //! A constructor
    /*!
     * \brief MainWindow
     * \param parent is a QWidget
     */
    explicit MainWindow(QWidget *parent = 0);
    //! A destructor
    ~MainWindow();

private:
    //! A private variable
    /*!
     * stores a pointer to the ui that the MainWindow widget displays
     */
    Ui::MainWindow *ui;
    //! A private member variable
    /*!
     * stores a pointer to the instructions that the instructions window displays
     */
    instructions* read;
    //! A private member variable
    /*!
     * stores a pointer to the player that the gameboard displays
     */
    player* myPlayer;
};

#endif // MAINWINDOW_H
