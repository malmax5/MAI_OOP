#include "../include/infodialog.hpp"

InfoDialog::InfoDialog(QWidget *parent)
    : QDialog(parent)
{
    infoLabel_ = new QLabel(this);
    infoLabel_->setText("NPC Colors:\n"
                       "  Knight - Red\n"
                       "  Pegasus - Green\n"
                       "  Squirrel - Orange\n"
                       "NPC strategy:\n"
                        "  Knight attack Squirrel\n"
                        "  Squirrel attack Pegasus\n"
                        "  Pegasus is peaceful");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(infoLabel_);
}

InfoDialog::~InfoDialog()
{}