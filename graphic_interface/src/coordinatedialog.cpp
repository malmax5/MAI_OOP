#include "../include/coordinatedialog.hpp"

CoordinateDialog::CoordinateDialog(QWidget *parent)
    : QDialog(parent)
{
    QLabel *xLabel = new QLabel("X Coordinate:", this);
    xEdit_ = new QLineEdit(this);
    QLabel *yLabel = new QLabel("Y Coordinate:", this);
    yEdit_ = new QLineEdit(this);
    okButton_ = new QPushButton("OK", this);

    QHBoxLayout *xLayout = new QHBoxLayout;
    xLayout->addWidget(xLabel);
    xLayout->addWidget(xEdit_);

    QHBoxLayout *yLayout = new QHBoxLayout;
    yLayout->addWidget(yLabel);
    yLayout->addWidget(yEdit_);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(xLayout);
    mainLayout->addLayout(yLayout);
    mainLayout->addWidget(okButton_);

    connect(okButton_, &QPushButton::clicked, this, &CoordinateDialog::OnOkClicked);
}

CoordinateDialog::~CoordinateDialog()
{}

int CoordinateDialog::GetX() const
{
    return xEdit_->text().toInt();
}

int CoordinateDialog::GetY() const
{
    return yEdit_->text().toInt();
}

void CoordinateDialog::OnOkClicked()
{
    accept();
}
