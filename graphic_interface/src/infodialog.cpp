#include "../include/infodialog.hpp"

InfoDialog::InfoDialog(QWidget *parent)
    : QDialog(parent)
{
    infoLabel_ = new QLabel(this);
    infoLabel_->setText("Game Commands and NPC Colors:\n"
                       "Knight - Red\n"
                       "Pegasus - Green\n"
                       "Squirrel - Orange\n");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(infoLabel_);
}

InfoDialog::~InfoDialog()
{
}