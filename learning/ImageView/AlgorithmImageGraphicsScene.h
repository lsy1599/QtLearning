#ifndef ALGORITHMIMAGEGRAPHICSSCENE_H
#define ALGORITHMIMAGEGRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>

class AlgorithmImageGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum SHAPE{
        CURSOR,
        RECT,
        DELETE,
    };
    explicit AlgorithmImageGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = Q_NULLPTR);
    ~AlgorithmImageGraphicsScene();

    SHAPE getShape();
    void  SetShape(SHAPE shape);



private:
    SHAPE meShape = CURSOR;
    QGraphicsItem* selectItem = Q_NULLPTR;
};

#endif // ALGORITHMIMAGEGRAPHICSSCENE_H
