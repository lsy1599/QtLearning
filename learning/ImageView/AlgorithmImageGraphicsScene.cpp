#include "AlgorithmImageGraphicsScene.h"

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

void AlgorithmImageGraphicsScene::SetShape(AlgorithmImageGraphicsScene::SHAPE shape)
{
    meShape = shape;
}
