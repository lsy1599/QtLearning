#include "GraphicsView.h"
#include <QDebug>
#include <QWheelEvent>

namespace ZAlgorithm {

GraphicsView::GraphicsView(QGraphicsScene *scene)
    :QGraphicsView(scene)
{
    m_tile = QPixmap(64, 64);
    m_tile.fill(Qt::white);
    QPainter pt(&m_tile);
    QColor color(230, 230, 230);
    pt.fillRect(0, 0, 32, 32, color);
    pt.fillRect(32, 32, 32, 32, color);
    pt.end();

    scene->setSceneRect(0,0, width(),height());
    //setAlignment(Qt::AlignCenter);
    setRenderHint(QPainter::Antialiasing);//指定Render标签，抗锯齿
    setCacheMode(QGraphicsView::CacheBackground);//缓存模式
    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);//场景重绘更新方式
    //setDragMode(QGraphicsView::ScrollHandDrag);//拖动模式，鼠标可拖动

   // mapToScene(viewport()->rect());
    scene->setBackgroundBrush(QPixmap(m_tile));
}

GraphicsView::~GraphicsView()
{

}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
      scene()->setSceneRect(0,0, event->size().width(),event->size().height());
   // scene()->setSceneRect(this->rect());
   // mapToScene(viewport()->rect());

}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    QGraphicsView::wheelEvent(event);
    return;
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

