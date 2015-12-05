#ifndef HORSE_H
#define HORSE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixMap>
#include <QMediaPlayer>

//! A horse class
/*!
 * \brief The horse class.
 * Inherits from QGraphicsPixmapItem. Creates horse objects that fall from the sky.
 */
class horse : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \brief horse
     * \param parent is a QGraphicsItem
     */
    explicit horse(QGraphicsItem *parent = 0);
    //! A destructor
    ~horse();

public slots:
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief move()
     * causes horse objects to fall
     */
    void move();

private:
    //! A private variable
    /*!
     * stores the image that the horse object displays
     */
    QPixmap* horse_image;
    //! A private variable
    /*!
     * stores the sound that the horse object plays when caught
     */
    QMediaPlayer* horsesound;
};

#endif // HORSE_H
