#pragma once

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>

class InfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InfoDialog(QWidget *parent = nullptr);
    ~InfoDialog();

private:
    QLabel *infoLabel_;
};