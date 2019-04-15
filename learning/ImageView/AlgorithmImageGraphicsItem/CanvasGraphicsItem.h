#ifndef CANVASGRAPHICSITEM_H
#define CANVASGRAPHICSITEM_H
#include <QObject>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>


class CanvasGraphicsItem: public QGraphicsItem
{
public:
    CanvasGraphicsItem();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


private:
    int x;
    int y;


};

#endif // CANVASGRAPHICSITEM_H
