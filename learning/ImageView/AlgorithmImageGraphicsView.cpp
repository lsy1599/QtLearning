#include "AlgorithmImageGraphicsView.h"
#include <QDebug>
#include <QPainter>
#include <QImage>
#include <QWheelEvent>


AlgorithmImageGraphicsView::AlgorithmImageGraphicsView(QGraphicsScene *scene_)
    : QGraphicsView(scene_)
{

    m_tile = QPixmap(64, 64);
    m_tile.fill(Qt::white);
    QPainter pt(&m_tile);
    QColor color(230, 230, 230);
    pt.fillRect(0, 0, 32, 32, color);
    pt.fillRect(32, 32, 32, 32, color);
    pt.end();

    setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);//场景重绘更新方式
    setCacheMode(QGraphicsView::CacheBackground);//缓存模式
    setRenderHint(QPainter::Antialiasing);//指定Render标签，抗锯齿
    setDragMode(QGraphicsView::ScrollHandDrag);//拖动模式，鼠标可拖动
    scene()->setBackgroundBrush(QPixmap(":/root/Algorithm/Toolbar/images/backimage.jpg"));
}


AlgorithmImageGraphicsView::~AlgorithmImageGraphicsView()
{

}

void AlgorithmImageGraphicsView::wheelEvent(QWheelEvent *event)
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

void AlgorithmImageGraphicsView::dragEnterEvent(QDragEnterEvent *e)
{

}

#if 0
void AlgorithmImageGraphicsView::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    //绘制背景
    painter.begin(this);
    painter.drawTiledPixmap(rect(), m_tile);
    painter.end();
}
#endif
