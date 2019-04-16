#ifndef RECTGRAPHICSITEM_H
#define RECTGRAPHICSITEM_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

class RectGraphicsItem : public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit RectGraphicsItem(QGraphicsItem  *parent = nullptr);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

signals:

public slots:

private:
     QPointF m_centerPointF;
     bool m_bResizing;

};

#endif // RECTGRAPHICSITEM_H
