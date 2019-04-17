#ifndef PIXMAPITEM_H
#define PIXMAPITEM_H

#include "RectItem.h"

namespace ZAlgorithm {

class PixmapItem:
        public ShapeItem, public QGraphicsPixmapItem
{
public:
    explicit PixmapItem(QGraphicsItem* paraent = Q_NULLPTR);

    void startDraw(QGraphicsSceneMouseEvent * event);
    void drawing(QGraphicsSceneMouseEvent * event);

    void loadImage(QImage &img);
    void wheelEvent(QGraphicsSceneWheelEvent *mouseEvent);
};

}

#endif // PIXMAPITEM_H
