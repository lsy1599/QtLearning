#ifndef SHAPEITEM_H
#define SHAPEITEM_H
#include <QGraphicsSceneMouseEvent>
#include <QImage>

namespace ZAlgorithm {

class ShapeItem
{
public:
    ShapeItem();
    virtual void startDraw(QGraphicsSceneMouseEvent * event) = 0;
    virtual void drawing(QGraphicsSceneMouseEvent * event) = 0;

    virtual void loadImage(QImage &img);
};

}

#endif // SHAPEITEM_H
