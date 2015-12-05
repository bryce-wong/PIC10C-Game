#ifndef LIVES_H
#define LIVES_H

#include <QGraphicsTextItem>
#include "player.h"

//! A lives class
/*!
 * \brief The lives class.
 * Inherits from QGraphicsTextItem. Displays the number of lives on the screen.
 */
class Lives : public QGraphicsTextItem
{

public:
    //! A constructor
    /*!
     * \brief Lives
     * \param parent is a QGraphicsItem
     */
    explicit Lives(QGraphicsItem *parent = 0);
    //! A destructor
    ~Lives();
    //! a public member function that takes no arguments and returns void
    /*!
     * \brief decrease
     * decreases the number of lives everytime a horse/chicken is cat or a cat/dog hits the bottom
     * of the screen
     */
    void decrease();
    //! A public member variable
    /*!
     * stores an int that stores the current number of lives on the scene
     */
    int lives;
};

#endif // LIVES_H
