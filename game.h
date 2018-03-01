#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
//#include "score.h"
#include "box.h"


class Game : public QWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);

    QGraphicsScene * theScene;
    //Score * theScore;
    Box * theBox;

    void increaseScore();

    int getScore() const;
    void setStopCounting(bool value);

    bool getStopCounting() const;

    bool getTimerHasStarted() const;
    void setTimerHasStarted(bool value);

    QTimer *getTheTimer() const;
    void setTheTimer(QTimer *value);

private:
    bool timerHasStarted = false;
    int score = 0;
    bool stopCounting = false;
    QTimer * theTimer;


signals:

public slots:
    void timerTestFunction();
};

#endif // GAME_H
