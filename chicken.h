#ifndef CHICKEN_H
#define CHICKEN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QPixMap>
#include <QMediaPlayer>

//! A chicken class
/*!
 * \brief The chicken class.
 * Inherits from QGraphicsPixmapItem. Creates chicken objects that fall from the sky.
 */
class chicken : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \brief chicken
     * \param parent is a QGraphicsItem
     */
    explicit chicken(QGraphicsItem *parent = 0);
    //! A destructor
    ~chicken();

public slots:
    //! A public slot that takes no arguments and returns void
    /*!
     * \brief move()
     * causes chicken objects to fall
     */
    void move();

private:
    //! A private variable
    /*!
     * stores the image that the chicken object displays
     */
    QPixmap* chicken_image;
    //! A private variable
    /*!
     * stores the sound that the chicken object plays when caught
     */
    QMediaPlayer* chickensound;
};

#endif // CHICKEN_H
