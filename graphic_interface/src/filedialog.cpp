#include "../include/filedialog.hpp"
#include <QFileDialog>

FileDialog::FileDialog(QWidget *parent)
    : QDialog(parent)
{
    filePathEdit_ = new QLineEdit(this);
    browseButton_ = new QPushButton("Browse", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(filePathEdit_);
    layout->addWidget(browseButton_);

    connect(browseButton_, &QPushButton::clicked, this, &FileDialog::OnBrowseClicked);
}

FileDialog::~FileDialog()
{}

QString FileDialog::GetFilePath() const
{
    return filePathEdit_->text();
}

void FileDialog::OnBrowseClicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Select File");
    if (!filePath.isEmpty()) {
        filePathEdit_->setText(filePath);
    }
}