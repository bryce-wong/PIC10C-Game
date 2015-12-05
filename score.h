#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include "player.h"

//! A score class
/*!
 * \brief The Score class.
 * Inherits from QGraphicsTextItem. Displays the score on the screen.
 */
class Score : public QGraphicsTextItem
{

public:
    //! A constructor
    /*!
     * \brief Score
     * \param parent is a QGraphicsItem
     */
    explicit Score(QGraphicsItem *parent = 0);
    //! A destructor
    ~Score();
    //! a public member function that takes no arguments and returns void
    /*!
     * \brief increase
     * increases the score everytime a dog/cat is caught
     */
    void increase();
    //! A public member variable
    /*!
     * stores an int that stores the current score on the scene
     */
    int score;
};

#endif // SCORE_H
