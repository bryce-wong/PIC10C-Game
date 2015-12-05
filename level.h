#ifndef LEVEL_H
#define LEVEL_H

#include <QGraphicsTextItem>
#include "player.h"
#include <QMediaPlayer>

//! A level class
/*!
 * \brief The level class.
 * Inherits from QGraphicsTextItem. Displays the level on the screen.
 */
class level : public QGraphicsTextItem
{

public:
    //! A constructor
    /*!
     * \brief level
     * \param parent is a QGraphicsItem
     */
    explicit level(QGraphicsItem *parent = 0);
    //! A destructor
    ~level();
    //! a public member function that takes no arguments and returns void
    /*!
     * \brief increase
     * increases the level everytime 20 points are reached
     */
    void increase();
    //! A public member variable
    /*!
     * stores an int that stores the current level on the scene
     */
    int levelnum;
    //! A private variable
    /*!
     * stores the sound that the level object plays when it increases
     */
    QMediaPlayer* levelSound;
};

#endif // SCORE_H
