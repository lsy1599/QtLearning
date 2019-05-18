#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QResizeEvent>
#include <QWheelEvent>
#include "GraphicsItem/ShapeItem.h"
#include "GraphicsItem/RectItem.h"
#include "GraphicsItem/PixmapItem.h"

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
        VIEW,
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

    RectItem *  _Rect = Q_NULLPTR;
    PixmapItem* _pixmapItem = Q_NULLPTR;
    QImage _srcImg;
    QImage _RoiImg;
};

}

#endif // GRAPHICSSCENE_H
