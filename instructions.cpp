#include "instructions.h"
#include "ui_instructions.h"

instructions::instructions(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::instructions)
{
    ui->setupUi(this);
    this->setFixedSize(760, 600);
    this->setWindowTitle("It's Raining Cats and Dogs!");
}

instructions::~instructions()
{
    delete ui;
}
