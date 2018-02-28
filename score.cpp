#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    score = 0;
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",20));
}

void Score::increaseScore()
{
    score++;
}

int Score::getScore() const
{
    return score;
}


