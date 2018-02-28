#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QDebug>
#include <QList>

#include "box.h"
#include "score.h"

Score * score;
Box * BoxArray[9]; // global
Box * LivesArray[3];


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //create the scene
    QGraphicsScene * scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(Qt::lightGray));

    Box * thebox = new Box();
    Score * score = new Score(thebox);

    thebox->CreateTheArray();
    thebox->CreateLivesArray();

    thebox->AddToScene(LivesArray,scene);
    thebox->AddToScene(scene, BoxArray);

    scene->addItem(score);

    //add the view to show something
    QGraphicsView * view = new QGraphicsView(scene);

    view->setFixedSize(450,550);

    view->show();

    return a.exec();
}
