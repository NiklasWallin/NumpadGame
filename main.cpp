#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QList>

#include "mydialog.h"
#include "game.h"
#include "box.h"


Game * theGame;
MyDialog * theDialog;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    theDialog = new MyDialog();

    //if(theDialog->theText != "")
      //  theGame = new Game();

    return a.exec();
}
