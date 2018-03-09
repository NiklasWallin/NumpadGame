#include <QGraphicsScene>
#include <QFont>
#include <QGraphicsTextItem>
#include <QTimer>

#include "game.h"
#include "box.h"
//#include "score.h"


Box * BoxArray[9]; // global
Box * LivesArray[3];
extern int oldValue;
extern int newValue;
QGraphicsScene * theScene;

Game::Game(QWidget *parent)  : QWidget(parent)
{
    theScene = new QGraphicsScene();
    theScene->setBackgroundBrush(QBrush(Qt::lightGray));

    theBox->CreateTheArray();
    theBox->CreateLivesArray();
    theBox->AddToScene(LivesArray,theScene);
    theBox->AddToScene(theScene, BoxArray);

    //theText = new QGraphicsTextItem("Score " + this->getScore());
    theText = new QGraphicsTextItem();
    theText->setPlainText("Highscore: " + QString::number(getHighScore()) + "\nScore: " + QString::number(getScore()));
    theText->setFont(QFont("times",16));
    theText->setPos(this->x(),this->y()-95);

    theScene->addItem(theText);

    connect(this,SIGNAL(gameOver()),this,SLOT(gameIsOver()));

    //add the view to show something
    QGraphicsView * view = new QGraphicsView(theScene);

    view->setFixedSize(450,550);

    view->show();

    //timer
    theTimer = new QTimer(this);
}

void Game::resetGame()
{
    resetLifes();
    setStopCounting(false);
    setTimerHasStarted(false);
    setTimeIsOut(false);
    setScore(0);
    acceptUserInput = true;
}

void Game::resetLifes()
{

    for(unsigned int i = 0; i < sizeof(LivesArray)/sizeof(LivesArray[0]); i++){
        if(LivesArray[i]->getColor() == false){
            LivesArray[i]->setBrush(QBrush(Qt::darkGreen));
            LivesArray[i]->setColor(true);
        }
    }
    setLifePoint(3);
}

void Game::increaseScore()
{
    if(getStopCounting() == false){
        score++;
        theText->setPlainText("Highscore: " + QString::number(getHighScore()) + "\nScore: " + QString::number(getScore()));
    }
}

void Game::checkHighScore()
{
    if(score > highScore){
        highScore = score;
        theText->setPlainText("Highscore: " + QString::number(getHighScore()) + "\nScore: " + QString::number(getScore()));
    }
}

void Game::timerTestFunction()
{
    emit gameOver();
}

void Game::gameIsOver()
{
    theTimer->stop();
    theTimer->disconnect();
    acceptUserInput = false;
    setStopCounting(true);
    darkBoxes();
    checkHighScore();
    theTimer->connect(theTimer,SIGNAL(timeout()),this,SLOT(gameOverAnimation()));
    theTimer->start(1500);
}

void Game::darkBoxes()
{
    for(unsigned int i = 0; i < sizeof(BoxArray) / sizeof(BoxArray[0]); i++){
        BoxArray[i]->setBrush(QBrush(Qt::black));
    }
}

void Game::whiteBoxes()
{
    for(unsigned int i = 0; i < sizeof(BoxArray) / sizeof(BoxArray[0]); i++){
        BoxArray[i]->setBrush(QBrush(Qt::white));
        //BoxArray[i]->setColor(false);
        BoxArray[i]->setFlag(QGraphicsItem::ItemIsFocusable);
        //qDebug() << "focused box = " << theBox->focusedBox << endl;
        if(BoxArray[i]->getColor() == true){
            BoxArray[i]->setBrush(QBrush(Qt::red));
            BoxArray[i]->setColor(true);
            BoxArray[i]->setFocus();
        }
    }
    resetGame();
}

void Game::gameOverAnimation()
{
    qDebug() << "slot called..." << endl;
    theTimer->stop();
    theTimer->disconnect();
    whiteBoxes();
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

bool Game::getTimeIsOut() const
{
    return timeIsOut;
}

void Game::setTimeIsOut(bool value)
{
    timeIsOut = value;
}

int Game::getHighScore() const
{
    return highScore;
}

void Game::setHighScore(int value)
{
    highScore = value;
}

void Game::setScore(int value)
{
    score = value;
}

int Game::getLifePoint() const
{
    return lifePoint;
}

void Game::setLifePoint(int value)
{
    lifePoint = value;
}





