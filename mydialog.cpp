#include "mydialog.h"
#include "ui_mydialog.h"
#include <QDebug>
#include <QApplication>
#include "game.h"

extern Game * theGame;

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    this->setModal(true);
    this->exec();
}

MyDialog::~MyDialog()
{
    delete ui;
}



void MyDialog::on_pushButton_clicked()
{
    qDebug() << "continue pressed" << endl;
    theText = ui->lineEdit->text();
    if(theText != ""){
        close();
        theGame = new Game(theText);
    }
}

void MyDialog::on_pushButton_2_clicked()
{
    qDebug() << "Exit pressed" << endl;
    close();
    exit(0);
}
