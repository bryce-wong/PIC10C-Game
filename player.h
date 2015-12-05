#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QGraphicsItem>
#include "score.h"

//! An player class
/*!
 * \brief The player class.
 * Inherits from QGraphicsPixmapItem. Displays a player object.
 */
class player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \brief player
     * \param parent is a QGraphicsItem
     */
    player(QGraphicsItem* parent=0);
    //! A destructor
    ~player();
    //! a public member function that takes a QKeyEvent pointer and returns void
    /*!
     * \brief keyPressEvent();
     * changes the position of the player to right or left
     * with every respective key press to the right or left
     */
    void keyPressEvent(QKeyEvent *);

public slots:
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief rainingEasy();
     * causes the easy difficulty of the rain to be set up
     */
    void rainingEasy();
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief rainingMedium();
     * causes the medium difficulty of the rain to be set up
     */
    void rainingMedium();
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief rainingHard();
     * causes the hard difficulty of the rain to be set up
     */
    void rainingHard();
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief rainPower();
     * causes the powerups to fall
     */
    void rainPower();

private:
    //! A private member variable
    /*!
     * stores a pointer to the QPixmap that the player object displays
     */
    QPixmap* player_image;
    //! A public member variable
    /*!
     * stores a bool that allows powerups to be released every 23 seconds.
     */
    bool releasePower;

};

#endif // PLAYER_H
