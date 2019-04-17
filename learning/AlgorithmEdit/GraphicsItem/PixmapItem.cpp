#include "PixmapItem.h"
#include <QDebug>
#include <QGraphicsScene>

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
    qDebug() << scene()->width()<<scene()->height();
    this->moveBy(
                (scene()->width() - img.width())/2 ,
                (scene()->height() - img.height())/2 );
}

void PixmapItem::wheelEvent(QGraphicsSceneWheelEvent *mouseEvent)
{
    qDebug()<<mouseEvent->scenePos();

}



}
