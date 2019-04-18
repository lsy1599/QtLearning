#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QResizeEvent>
#include <QWheelEvent>
#include "GraphicsItem/ShapeItem.h"

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
        PIXMAP,  //图片
    };
    GraphicsScene();

    SHAPE getShape();
    void  setShape(SHAPE shape);

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void resizeEvent(QGraphicsSceneResizeEvent *Event);
    void wheelEvent(QGraphicsSceneWheelEvent *mouseEvent);

    void dragEnterEvent(QGraphicsSceneDragDropEvent* Event);
    void dropLeaveEvent(QGraphicsSceneDragDropEvent* Event);

private:


private:
    SHAPE _shape = CURSOR;
    ShapeItem *_currentShapeItem = Q_NULLPTR;
    bool isDrawing = false;
};

}

#endif // GRAPHICSSCENE_H
