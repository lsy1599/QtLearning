#include "GraphicsScene.h"
#include "GraphicsItem/RectItem.h"
#include "GraphicsItem/PixmapItem.h"
#include <QDebug>

namespace ZAlgorithm {

GraphicsScene::GraphicsScene()
{
    setItemIndexMethod(QGraphicsScene::NoIndex);
}

GraphicsScene::SHAPE GraphicsScene::getShape()
{
    return _shape;
}

void GraphicsScene::setShape(GraphicsScene::SHAPE shape)
{
    if(shape == PIXMAP)
    {
        QImage img(":/Algorithm/ico/test.jpg");

    //    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pix);
        PixmapItem *pixmapItem = new PixmapItem();
        addItem(pixmapItem);
        pixmapItem->loadImage(img);

        _shape = CURSOR;
        return;
    }
    _shape = shape;

}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(_currentShapeItem && isDrawing)
    {
        _currentShapeItem->drawing(mouseEvent);
    }
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    switch(_shape)
    {
    case RECT:
        {
            RectItem* rect = new RectItem;
            addItem(rect);
            _currentShapeItem  = rect;
            break;
        }
    default:
        _currentShapeItem = Q_NULLPTR;
        break;
    }

    if(_currentShapeItem)
    {
        _currentShapeItem->startDraw(mouseEvent);
        isDrawing = true;
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    isDrawing = false;
    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}

void GraphicsScene::resizeEvent(QGraphicsSceneResizeEvent *Event)
{
    qDebug()<<Event->newSize();

}

void GraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *mouseEvent)
{
    QGraphicsScene::wheelEvent(mouseEvent);
}


}

