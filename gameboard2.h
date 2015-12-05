#ifndef GAMEBOARD2_H
#define GAMEBOARD2_H

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QKeyEvent>
#include <QLabel>
#include <QGraphicsScene>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>
#include <QGraphicsTextItem>

#include "player.h"
#include "score.h"
#include "lives.h"
#include "level.h"

#include <iostream>

//! A GameBoard2 class
/*!
 * \brief The GameBoard2 class.
 * Inherits from QGraphicsView. Creates the gameboard that displays all gaming objects.
 */
class GameBoard2 : public QGraphicsView
{

public slots:

signals:

public:
    //! A constructor
    /*!
     * \brief GameBoard2
     * \param parent is a QWidget
     * \param easy is a bool set to false (no difficulty levels left yet)
     * \param medium is a bool set to false
     * \param hard is a bool set to false
     */
    GameBoard2(QWidget* parent=0, bool easy = false, bool medium = false, bool hard = false);
    //! A destructor
    ~GameBoard2();
    //! a public member function that takes no arguments and returns void
    /*!
     * \brief game_over
     * sets the gameboard to the game_over image and deletes all other board objects
     */
    void game_over();

    //! A public member variable
    /*!
     * stores the pointer to the scene that the board object displays
     */
    QGraphicsScene* scene;
    //! A public member variable
    /*!
     * stores the pointer to the player that the board object displays
     */
    player* myPlayer;
    //! A public member variable
    /*!
     * stores the pointer to the score that the board object displays
     */
    Score* myScore;
    //! A public member variable
    /*!
     * stores the pointer to the lives that the board object displays
     */
    Lives* myLives;
    //! A public member variable
    /*!
     * stores the pointer to the level that the board object displays
     */
    level* myLevel;
    //! A public member variable
    /*!
     * stores a bool that represents whether a powerup is captured
     */
    bool caughtpower;
    //! A public member variable
    /*!
     * stores an int that stores the current score of the scene
     */
    int officialScore;
    //! A public member variable
    /*!
     * stores an int that stores the current interval of the scene (which increases
     * with each level)
     */
    int interval;

private:

    //! A private member variable
    /*!
     * stores a pointer to the QPixmap that the gameover board displays
     */
    QPixmap* star_image;

};

#endif // GAMEBOARD2_H
