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
        if(_pixmapItem != Q_NULLPTR)
        {
            removeItem(_pixmapItem);
            delete _pixmapItem;
        }

        QImage img(":/Algorithm/ico/test.bmp");
        _srcImg = img.copy();


        _pixmapItem = new PixmapItem();
        addItem(_pixmapItem);
        _pixmapItem->loadImage(img);
        _shape = CURSOR;
        return;
    }else if(shape == VIEW) {
        if(_Rect != Q_NULLPTR && _pixmapItem != Q_NULLPTR)
        {
           //qDebug()<<_pixmapItem->scenePos().toPoint()<<_pixmapItem->pixmap().size();
           //qDebug()<<"size:"<<_Rect->rect().toRect();
           //qDebug()<<"sceneRect:"<< sceneRect();

            QPoint imagePoint = _pixmapItem->scenePos().toPoint();
            QSize  imageSize  = _pixmapItem->pixmap().size();

            QPoint RoiPoint = QPoint(_Rect->rect().toRect().x(), _Rect->rect().toRect().y());
            QSize  RoiSize  = _Rect->rect().toRect().size();

           //qDebug()<<imagePoint<<imageSize;
           //qDebug()<<RoiPoint<<RoiSize;

            if(imagePoint.x() > RoiPoint.x() || (RoiPoint.x() + RoiSize.width()) > (imagePoint.x() + imageSize.width()))
                return; //
            if(imagePoint.y() > RoiPoint.y() || (RoiPoint.y() + RoiSize.height()) > (imagePoint.y() + imageSize.height()))
                return;

            QPoint absRoi((RoiPoint.x() - imagePoint.x()), (RoiPoint.y() - imagePoint.y()));
            //qDebug()<<absRoi<<RoiSize;
            QRect absRect(absRoi, RoiSize);
            _RoiImg = _srcImg.copy(absRect);
            _pixmapItem->loadImage(_RoiImg);
            removeItem(_Rect);
            delete _Rect;
            _Rect = Q_NULLPTR;

            _RoiImg.save("ROI.bmp","BMP");
        }
    }
    _shape = shape;

}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsScene::mouseMoveEvent(mouseEvent);
    if(_currentShapeItem && isDrawing)
    {
        _currentShapeItem->drawing(mouseEvent);
    }
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

    QGraphicsScene::mousePressEvent(mouseEvent);
    if(selectedItems().size() > 0)
    {
        QGraphicsScene::mousePressEvent(mouseEvent);
        return;
    }


    switch(_shape)
    {
    case RECT:
    {

        if(_Rect != Q_NULLPTR)
        {
            removeItem(_Rect);
            delete _Rect;
        }

        _Rect = new RectItem;
        addItem(_Rect);
        _currentShapeItem  = _Rect;
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

void GraphicsScene::dragEnterEvent(QGraphicsSceneDragDropEvent *Event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<Event->pos();
    QGraphicsScene::dragEnterEvent(Event);
}

void GraphicsScene::dropLeaveEvent(QGraphicsSceneDragDropEvent *Event)
{
    qDebug()<<__FILE__<<__FUNCTION__<<Event->pos();
    QGraphicsScene::dragLeaveEvent(Event);
}


}

