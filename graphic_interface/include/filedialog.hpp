#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

class FileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileDialog(QWidget *parent = nullptr);
    ~FileDialog();

    QString GetFilePath() const;

private slots:
    void OnBrowseClicked();

private:
    QLineEdit *filePathEdit_;
    QPushButton *browseButton_;
};
