#ifndef CATRAIN_H
#define CATRAIN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixMap>
#include <QMediaPlayer>

//! A catRain class
/*!
 * \brief The catRain class, inherited from QGraphicsPixmapItem.
 * Creates cat objects that fall from the sky.
 */
class catRain : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \brief catRain constructor
     * \param parent is a QGraphicsItem
     */
    explicit catRain(QGraphicsItem *parent = 0);

    //! a destructor
    ~catRain();

public slots:
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief move()
     * causes catRain objects to fall
     */
    void move();

private:
    //! A private variable
    /*!
     * stores the image that the cat object displays
     */
    QPixmap* cat_image;
    //! A private variable
    /*!
     * stores the sound that the cat object plays when caught
     */
    QMediaPlayer* catsound;
};

#endif // CATRAIN_H
