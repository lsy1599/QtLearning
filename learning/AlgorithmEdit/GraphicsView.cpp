#include "GraphicsView.h"
#include <QDebug>
#include <QWheelEvent>

namespace ZAlgorithm {

GraphicsView::GraphicsView(QGraphicsScene *scene)
    :QGraphicsView(scene)
{

    scene->setSceneRect(0,0, width(),height());
    setRenderHint(QPainter::Antialiasing);//指定Render标签，抗锯齿
    setCacheMode(QGraphicsView::CacheBackground);//缓存模式
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);//场景重绘更新方式
  //  setDragMode(QGraphicsView::ScrollHandDrag);//拖动模式，鼠标可拖动
}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    scene()->setSceneRect(0,0, width(),height());
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    QGraphicsView::wheelEvent(event);
    if (event->isAccepted())
    {
        return;
    }
    qreal unit = 0.02;
    QMatrix mat = matrix();
    if (event->delta() > 0)
    {
        mat.scale(1 + unit, 1 + unit);
    }
    else
    {
        mat.scale(1 - unit, 1 - unit);
    }
    setMatrix(mat);
}


}

