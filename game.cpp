#include <QGraphicsScene>
#include <QFont>
#include <QGraphicsTextItem>
#include <QTimer>

#include "game.h"
#include "box.h"
//#include "score.h"


Box * BoxArray[9]; // global
Box * LivesArray[3];
QGraphicsScene * theScene;

Game::Game(QWidget *parent)  : QWidget(parent)
{
    theScene = new QGraphicsScene();
    theScene->setBackgroundBrush(QBrush(Qt::lightGray));

    theBox->CreateTheArray();
    theBox->CreateLivesArray();
    theBox->AddToScene(LivesArray,theScene);
    theBox->AddToScene(theScene, BoxArray);

    //add the view to show something
    QGraphicsView * view = new QGraphicsView(theScene);

    view->setFixedSize(450,550);

    view->show();

    //timer
    theTimer = new QTimer(this);
   /*
    connect(theTimer,SIGNAL(timeout()),this,SLOT(timerTestFunction()));
    theTimer->start(10000);
    */
}


void Game::increaseScore()
{
    if(getStopCounting() == false)
        score++;
}

int Game::getScore() const
{
    return score;
}

void Game::setStopCounting(bool value)
{
    stopCounting = value;
}

bool Game::getStopCounting() const
{
    return stopCounting;
}

bool Game::getTimerHasStarted() const
{
    return timerHasStarted;
}

void Game::setTimerHasStarted(bool value)
{
    timerHasStarted = value;
}

QTimer *Game::getTheTimer() const
{
    return theTimer;
}

void Game::setTheTimer(QTimer *value)
{
    theTimer = value;
}

void Game::timerTestFunction()
{
    setStopCounting(true);
    qDebug() << "Times up! You got the score: " << score << endl;
}

