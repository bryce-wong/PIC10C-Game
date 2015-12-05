#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <QMainWindow>

/*! \file instructions.h
 * \brief A documented instructions file
 * \namespace Ui
 */
namespace Ui {
class instructions;
}

//! An instructions class
/*!
 * \brief The instructions class.
 * Inherits from QMainWindow. Displays a MainWindow that shows the instructions.
 */
class instructions : public QMainWindow
{
    Q_OBJECT

public:
    //! A constructor
    /*!
     * \brief instructions
     * \param parent is a QWidget
     */
    explicit instructions(QWidget *parent = 0);
    //! A destructor
    ~instructions();

private:
    //! A private variable
    /*!
     * stores a pointer to the ui that the instructions widget displays
     */
    Ui::instructions *ui;

};

#endif // INSTRUCTIONS_H
