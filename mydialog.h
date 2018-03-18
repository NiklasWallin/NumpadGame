#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include "game.h"

namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

    QString theText;


private slots:



    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MyDialog *ui;
};

#endif // MYDIALOG_H
