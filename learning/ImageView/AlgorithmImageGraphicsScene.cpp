#include "AlgorithmImageGraphicsScene.h"
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

AlgorithmImageGraphicsScene::AlgorithmImageGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent):
  QGraphicsScene(x, y, width, height, parent)
{

    setItemIndexMethod(QGraphicsScene::NoIndex);
}

AlgorithmImageGraphicsScene::~AlgorithmImageGraphicsScene()
{

}

AlgorithmImageGraphicsScene::SHAPE AlgorithmImageGraphicsScene::getShape()
{
    return meShape;
}

void AlgorithmImageGraphicsScene::setShape(AlgorithmImageGraphicsScene::SHAPE shape)
{
    meShape = shape;
}

void AlgorithmImageGraphicsScene::addPixmapItem(const QString &file, const QPointF &pos)
{

}

void AlgorithmImageGraphicsScene::stickItem()
{

}

void AlgorithmImageGraphicsScene::zoomUpItem()
{

}

void AlgorithmImageGraphicsScene::zoomDownItem()
{

}

void AlgorithmImageGraphicsScene::rotationItem()
{

}

void AlgorithmImageGraphicsScene::setItemText()
{

}

void AlgorithmImageGraphicsScene::slotPenChanged(const QPen &pen)
{

}

void AlgorithmImageGraphicsScene::slotBrushChanged(const QBrush &brush)
{

}

void AlgorithmImageGraphicsScene::slotFontChanged(const QFont &font)
{

}

bool AlgorithmImageGraphicsScene::event(QEvent *event)
{
    QGraphicsScene::event(event);
    if(event->isAccepted())
    {

    }
    return true;
}

void AlgorithmImageGraphicsScene::wheelEvent(QGraphicsSceneWheelEvent *ev)
{
    if(selectItem != Q_NULLPTR)
    {


    }
}

void AlgorithmImageGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}

void AlgorithmImageGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    QGraphicsItem *item = itemAt(mouseEvent->scenePos(), QTransform());
    if (item != Q_NULLPTR && item->type() == 1000)
    {

    }


}

bool AlgorithmImageGraphicsScene::paintPolygon(QEvent *event)
{

    return true;
}
