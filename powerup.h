#ifndef POWERUP_H
#define POWERUP_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixMap>
#include <QMediaPlayer>

//! A powerup class
/*!
 * \brief The powerup class.
 * Inherits from QGraphicsPixmapItem. Creates powerup objects that fall from the sky.
 */
class powerup : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \brief powerup
     * \param parent is a QGraphicsItem
     */
    explicit powerup(QGraphicsItem *parent = 0);
    //! A destructor
    ~powerup();

public slots:
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief move()
     * causes powerup objects to fall
     */
    void move();
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief backToFalse()
     * sets a bool member variable of the GameBoard2 class back to false.
     */
    void backToFalse();

private:
    //! A private variable
    /*!
     * stores the image that the powerup object displays (an apple).
     */
    QPixmap* powerup_image;
    //! A private variable
    /*!
     * stores the sound that the apple object plays when caught
     */
    QMediaPlayer* applesound;
};

#endif // POWERUP_H
