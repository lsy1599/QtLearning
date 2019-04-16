#ifndef RECTITEM_H
#define RECTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>

namespace ZAlgorithm {

class RectItem: public QGraphicsRectItem
{
public:
    explicit RectItem(QGraphicsItem* parent = Q_NULLPTR);

    void startCreate(const QPointF &pos);
    void duringCreate(const QPointF &pos);
    void endCreate(const QPointF &pos);
protected:
    void mousePressEvent  (QGraphicsSceneMouseEvent* event);
    void mouseMoveEvent   (QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

    int type() const;

private:
    QPointF  _startPos;
    QPointF  _endPos;

    QPointF m_centerPointF;
    bool m_bResizing = false;
};

}

#endif // RECTITEM_H
