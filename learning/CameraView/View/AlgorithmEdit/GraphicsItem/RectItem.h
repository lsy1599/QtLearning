#ifndef RECTITEM_H
#define RECTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include "ShapeItem.h"

namespace ZAlgorithm {

class RectItem: public ShapeItem, public QGraphicsRectItem
{
public:
    explicit RectItem(QGraphicsItem* parent = Q_NULLPTR);


    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);

protected:
    void mousePressEvent  (QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent   (QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

    void dragEnterEvent(QGraphicsSceneDragDropEvent* event);
    void dropLeaveEvent(QGraphicsSceneDragDropEvent* event);

    int type() const;




private:
    QPointF  startPos;
    QPointF  endPos;

    QPointF m_centerPointF;
    bool m_Resizing = false;
};

}

#endif // RECTITEM_H
