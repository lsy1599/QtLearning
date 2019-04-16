#include "GraphicsScene.h"
#include "GraphicsItem/RectItem.h"
#include <QDebug>

namespace ZAlgorithm {

GraphicsScene::GraphicsScene()
{

}

GraphicsScene::SHAPE GraphicsScene::getShape()
{
    return _shape;
}

void GraphicsScene::setShape(GraphicsScene::SHAPE shape)
{
    _shape = shape;
}

bool GraphicsScene::event(QEvent *event)
{
    QGraphicsScene::event(event);

    return true;
}

void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(_selectItem != Q_NULLPTR)
    {
        switch(_shape)
        {
        case RECT:
            RectItem* rectItem = static_cast<RectItem*>(_selectItem);
            rectItem->duringCreate(mouseEvent->scenePos());
            qDebug()<<mouseEvent->scenePos();
            break;
        }

    }
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsItem* item = getCurDrawShapeItem();
    if(_selectItem != Q_NULLPTR)
    {
        switch(_shape)
        {
        case RECT:
            RectItem* rectItem = static_cast<RectItem*>(_selectItem);
            rectItem->startCreate(mouseEvent->scenePos());
            break;
        }

    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

QGraphicsItem *GraphicsScene::getCurDrawShapeItem()
{
    QGraphicsItem* item = Q_NULLPTR;
    switch(_shape)
    {
    case RECT:
        item = new RectItem;
        this->addItem(item);
        _selectItem  = item;
        break;
    default:
        _selectItem = Q_NULLPTR;
        break;
    }
    return item;
}

}

