#ifndef BOX_H
#define BOX_H

#include <QGraphicsRectItem>
#include <QDebug>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

class Box : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit Box(QObject *parent = nullptr);

    Box(int x, int y, int width, int heigth);
    //Box();

    void keyPressEvent(QKeyEvent * event);

    void selectRandomBox(int tester);

    void CreateTheArray();

    void CreateLivesArray();

    void CreateLivesList();

    void AddToScene(QGraphicsScene *thescene, Box * theArray[]);

    void AddToScene(Box * theArray[], QGraphicsScene *thescene);

    void RemoveLifePoint();

    bool getColor() const;

    void setColor(bool value);



private:
    bool color;

signals:

public slots:
};

#endif // BOX_H
