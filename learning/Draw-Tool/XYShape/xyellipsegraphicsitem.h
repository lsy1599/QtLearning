#ifndef XYELLIPSEGRAPHICSITEM_H
#define XYELLIPSEGRAPHICSITEM_H

#include "xymovablegraphicsitem.h"

class XYEllipseGraphicsItem : public XYMovableGraphicsItem
{
    Q_OBJECT
public:
    explicit XYEllipseGraphicsItem(const QRectF &rect = QRectF(), QGraphicsItem *parent = 0);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *w) Q_DECL_OVERRIDE;
private:
    QRectF moRect;

    friend class XYGraphicsScene;
};

#endif // XYELLIPSEGRAPHICSITEM_H
