#include <stdlib.h>
#include <QTimer>
#include "box.h"
#include "game.h"

extern Box * BoxArray[9];
extern Box * LivesArray[3];
//extern Score * score;
extern Game * theGame;

static int newValue = 4;
static int oldValue = 4;
static int LifePoint = 2;
//static int points = 0;

Box::Box(QObject *parent) : QObject(parent)
{

}

Box::Box(int x, int y, int width, int heigth)
{
    setRect(x,y,width,heigth);
}


void Box::keyPressEvent(QKeyEvent *event)
{   int t;
    if(event->key() == Qt::Key_7){
        t = 0;
        selectRandomBox(t);
    }
    if(event->key() == Qt::Key_8){
        t = 1;
        selectRandomBox(t);
    }
    if(event->key() == Qt::Key_9){
        t = 2;
        selectRandomBox(t);
    }
    if(event->key() == Qt::Key_4){
        t = 3;
        selectRandomBox(t);
    }
    if(event->key() == Qt::Key_5){
        t = 4;
        selectRandomBox(t);
    }
    if(event->key() == Qt::Key_6){
        t = 5;
        selectRandomBox(t);
    }
    if(event->key() == Qt::Key_1){
        t = 6;
        selectRandomBox(t);
    }
    if(event->key() == Qt::Key_2){
        t = 7;
        selectRandomBox(t);
    }
    if(event->key() == Qt::Key_3){
        t = 8;
        selectRandomBox(t);
    }
}

void Box::selectRandomBox(int tester)
{
    //start the timer at first press.

    if(theGame->getTimerHasStarted() == false){
        theGame->setTimerHasStarted(true);
        theGame->connect(theGame->getTheTimer(),SIGNAL(timeout()),theGame,SLOT(timerTestFunction()));
        //connect(theTimer,SIGNAL(timeout()),this,SLOT(timerTestFunction()));
        theGame->getTheTimer()->start(10000);
    }

    if(BoxArray[tester]->getColor()){
        if(theGame->getStopCounting() == false)
            theGame->increaseScore();
        BoxArray[tester]->setBrush(QBrush(Qt::white));
        BoxArray[tester]->setColor(false);
        oldValue = tester;
    }else{
        RemoveLifePoint();
        BoxArray[newValue]->setBrush(QBrush(Qt::white));
        BoxArray[newValue]->setColor(false);
    }
    while(newValue == oldValue)
        newValue = rand() % 9;

    //qDebug() << "random value = " << newValue << endl;
    oldValue = newValue;

    if(BoxArray[newValue]->ItemIsFocusable){
        BoxArray[oldValue]->clearFocus();
        BoxArray[newValue]->setFocus();
        BoxArray[newValue]->setBrush(QBrush(Qt::red));
        BoxArray[newValue]->setColor(true);
    }
}

void Box::CreateTheArray()
{
    int rectWidth = 50;
    int rectHeight = 50;
    int positionX = 0;
    int positionY = 0;
    int counter = 0;

    for(unsigned int i = 0; i < 9; i++){
        Box * testbox = new Box(positionX,positionY,rectWidth,rectHeight);;
        BoxArray[i] = testbox;

        //make item focusable (making it possible to focus the item)
        BoxArray[i]->setFlag(QGraphicsItem::ItemIsFocusable);

        if(i == 4){
            BoxArray[i]->setFocus();
            BoxArray[i]->setColor(true);
            BoxArray[i]->setBrush(QBrush(Qt::red));
        }else{
            BoxArray[i]->setColor(false);
            BoxArray[i]->setBrush(QBrush(Qt::white));
        }

        positionX += 75;
        if(counter == 2){
            positionY+=75;
            positionX = 0;
            counter = -1;
        }
        counter++;
    }
    qDebug() << "Array is created " << endl;
}

void Box::CreateLivesArray()
{
    int rectWidth = 50;
    int rectHeight = 50;
    int X = 0;
    int Y = 275;

    for(int i = 0; i < 3; i++){
        Box * thebox = new Box(X,Y,rectWidth,rectHeight);
        LivesArray[i] = thebox;
        X+=75;
        LivesArray[i]->setFlag((QGraphicsItem::ItemIsFocusable));
        LivesArray[i]->setBrush(QBrush(Qt::darkGreen));
    }
}

void Box::AddToScene(QGraphicsScene *thescene, Box * theArray[])
{
    for(int i = 0; i < 9; i++){
        thescene->addItem(theArray[i]);
    }
}

void Box::AddToScene(Box *theArray[], QGraphicsScene *thescene)
{
    for(int i = 0; i < 3; i++){
        thescene->addItem(theArray[i]);
    }
}

void Box::RemoveLifePoint()
{
    LivesArray[LifePoint]->setBrush(QBrush(Qt::white));
    LivesArray[LifePoint]->setColor(false);
    if(LifePoint > 0){
        LifePoint--;
        return;
    }
    if(LifePoint == 0){
        qDebug() << "Game Over, you got the points: " << theGame->getScore() << endl;
        return;
    }
}

bool Box::getColor() const
{
    return color;
}

void Box::setColor(bool value)
{
    color = value;
}








