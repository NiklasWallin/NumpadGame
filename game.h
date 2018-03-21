#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QTimer>
#include "box.h"
//#include "mydialog.h"

class Game : public QWidget
{
    Q_OBJECT
public:
    //explicit Game(QWidget *parent = nullptr, QString name);

    Game(QString theName);

    QGraphicsScene * theScene;
    Box * theBox;
    //MyDialog theDialog; //komenter bort kanske?

    QGraphicsTextItem * theText;

    void resetGame();
    void resetLifes();

    void increaseScore();
    void checkHighScore();

    void writeToFile();
    void readFromFile();

    int getScore() const;
    void setStopCounting(bool value);

    bool getStopCounting() const;

    bool getTimerHasStarted() const;
    void setTimerHasStarted(bool value);

    bool getTimeIsOut() const;
    void setTimeIsOut(bool value);

    int getHighScore() const;
    void setHighScore(int value);

    void setScore(int value);

    int getLifePoint() const;
    void setLifePoint(int value);

    void darkBoxes();

    QString PlayerName;

    QString HighScoreName;
    void setTheHighScore();

    bool acceptUserInput = true;
    QTimer * theTimer;

private:

    int lifePoint = 3;
    int score = 0;
    int highScore = 0;
    bool timerHasStarted = false;
    bool stopCounting = false;
    bool timeIsOut = false;

signals:
    void gameOver();

public slots:
    void timerTestFunction();
    void gameIsOver();
    void whiteBoxes();
    void gameOverAnimation();
};

#endif // GAME_H
