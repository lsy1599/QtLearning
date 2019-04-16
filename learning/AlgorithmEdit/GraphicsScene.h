#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

namespace ZAlgorithm {

class GraphicsScene : public QGraphicsScene
{
public:
    enum SHAPE
    {
        CURSOR,
        LINE,    //线
        RECT,    //矩形
        POLYGON, //多边形
        PATH,    //路径
        ELLIPSE, //椭圆
        DELETE,  //删除
    };
    GraphicsScene();

    SHAPE getShape();
    void  setShape(SHAPE shape);

protected:
    bool event(QEvent* event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    QGraphicsItem *getCurDrawShapeItem();


private:
    SHAPE _shape = CURSOR;
    QGraphicsItem *_selectItem = Q_NULLPTR;
};

}

#endif // GRAPHICSSCENE_H
