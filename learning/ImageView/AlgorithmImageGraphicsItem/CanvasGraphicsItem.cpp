#include "CanvasGraphicsItem.h"

CanvasGraphicsItem::CanvasGraphicsItem()
{

}

QRectF CanvasGraphicsItem::boundingRect() const
{

    return QRectF(0,0,0,0);
}

QPainterPath CanvasGraphicsItem::shape() const
{

    return QPainterPath();
}

void CanvasGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{

}

void CanvasGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void CanvasGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void CanvasGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}

