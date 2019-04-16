#include "PixmapItem.h"

namespace ZAlgorithm {

PixmapItem::PixmapItem(QGraphicsItem* parent)
    :QGraphicsPixmapItem(parent)
{
 setCacheMode(DeviceCoordinateCache);
}

void PixmapItem::startDraw(QGraphicsSceneMouseEvent *event)
{

}

void PixmapItem::drawing(QGraphicsSceneMouseEvent *event)
{

}

void PixmapItem::loadImage(QImage &img)
{
    if(img.isNull())
        return;
    setPixmap(QPixmap::fromImage(img));
}



}
