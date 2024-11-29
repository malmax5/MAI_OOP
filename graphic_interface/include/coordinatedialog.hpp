#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

class CoordinateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CoordinateDialog(QWidget *parent = nullptr);
    ~CoordinateDialog();

    int GetX() const;
    int GetY() const;

private slots:
    void OnOkClicked();

private:
    QLineEdit *xEdit_;
    QLineEdit *yEdit_;
    QPushButton *okButton_;
};