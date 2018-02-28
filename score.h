#ifndef SCORE_H
#define SCORE_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
public:

    Score(QGraphicsItem * parent = 0);

    void increaseScore();

    int getScore() const;

private:
    int score;
signals:

public slots:
};

#endif // SCORE_H
