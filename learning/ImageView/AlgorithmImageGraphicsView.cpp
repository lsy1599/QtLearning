#include "AlgorithmImageGraphicsView.h"
#include <QDebug>
#include <QPainter>
#include <QImage>


AlgorithmImageGraphicsView::AlgorithmImageGraphicsView(QGraphicsScene *scene)
    : QGraphicsView(scene)
{

    m_tile = QPixmap(64, 64);
    m_tile.fill(Qt::white);
    QPainter pt(&m_tile);
    QColor color(230, 230, 230);
    pt.fillRect(0, 0, 32, 32, color);
    pt.fillRect(32, 32, 32, 32, color);
    pt.end();


}


AlgorithmImageGraphicsView::~AlgorithmImageGraphicsView()
{

}

void AlgorithmImageGraphicsView::wheelEvent(QWheelEvent *e)
{

}

void AlgorithmImageGraphicsView::dragEnterEvent(QDragEnterEvent *e)
{

}

void AlgorithmImageGraphicsView::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    //绘制背景
    painter.begin(this);
    painter.drawTiledPixmap(rect(), m_tile);
    painter.end();
}
