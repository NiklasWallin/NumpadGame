#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QList>

#include "game.h"
#include "box.h"


Game * theGame;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    theGame = new Game();

    return a.exec();
}
