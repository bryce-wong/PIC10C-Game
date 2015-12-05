#ifndef DOGRAIN_H
#define DOGRAIN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixMap>
#include <QMediaPlayer>

//! A dogRain class
/*!
 * \brief The dogRain class.
 * Inherits from QGraphicsPixmapItem. Creates dog objects that fall from the sky.
 */
class dogRain : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \brief dogRain
     * \param parent is a QGraphicsItem
     */
    explicit dogRain(QGraphicsItem *parent = 0);
    //! A destructor
    ~dogRain();

public slots:
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief move()
     * causes dog objects to fall
     */
    void move();

private:
    //! A private variable
    /*!
     * stores the image that the dog object displays
     */
    QPixmap* dog_image;
    //! A private variable
    /*!
     * stores the sound that the dog object plays when caught
     */
    QMediaPlayer* dogsound;
};

#endif // CATRAIN_H
