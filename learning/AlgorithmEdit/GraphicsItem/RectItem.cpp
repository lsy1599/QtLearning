#include "RectItem.h"

#include <QPen>
#include <QColor>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>


namespace ZAlgorithm {

RectItem::RectItem(QGraphicsItem *parent)
    :QGraphicsRectItem(parent)
{

    //画笔-边框色
    QPen p = pen();
    p.setWidth(2);
    p.setColor(Qt::red);

    setPen(p);
    //画刷-背景色
    setBrush(QColor(0, 0, 0, 0)); //最后一位是透明度

    //可选择、可移动
    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
}

void RectItem::startDraw(QGraphicsSceneMouseEvent *event)
{
    startPos = event->scenePos();
    setRect(QRectF(event->scenePos(), QSizeF(0,0)));
}

void RectItem::drawing(QGraphicsSceneMouseEvent *event)
{
    QRectF l(qMin(startPos.x(), event->scenePos().x()),
                              qMin(startPos.y(), event->scenePos().y()),
                              qAbs(startPos.x() - event->scenePos().x()),
                              qAbs(startPos.y() - event->scenePos().y()));
    setRect(l);
}

void RectItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (event->modifiers() == Qt::ShiftModifier) {
            qDebug() << "Custom item left clicked with shift key.";
            // 选中 item
            setSelected(true);
        } else if (event->modifiers() == Qt::AltModifier) {
            // 重置 item 大小
            double radius = boundingRect().width() / 2.0;
            QPointF topLeft = boundingRect().topLeft();
            m_centerPointF = QPointF(topLeft.x() + pos().x() + radius, topLeft.y() + pos().y() + radius);
            QPointF pos = event->scenePos();
            double dist = sqrt(pow(m_centerPointF.x()-pos.x(), 2) + pow(m_centerPointF.y()-pos.y(), 2));
            if (dist / radius > 0.8) {
                m_bResizing = true;
            } else {
                m_bResizing = false;
            }
        } else {
            QGraphicsItem::mousePressEvent(event);
            event->accept();
        }
    } else if (event->button() == Qt::RightButton) {
        event->ignore();
    }

}

void RectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->modifiers() == Qt::AltModifier) && m_bResizing) {
        QPointF pos = event->scenePos();
        double dist = sqrt(pow(m_centerPointF.x()-pos.x(), 2) + pow(m_centerPointF.y()-pos.y(), 2));
        setRect(m_centerPointF.x()-this->pos().x()-dist, m_centerPointF.y()-this->pos().y()-dist, dist*2, dist*2);
    } else if(event->modifiers() != Qt::AltModifier) {
        QGraphicsItem::mouseMoveEvent(event);
    }
}

void RectItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if ((event->modifiers() == Qt::AltModifier) && m_bResizing) {
        m_bResizing = false;
    } else {
        QGraphicsItem::mouseReleaseEvent(event);
    }
}

int RectItem::type() const
{
    return UserType+1;
}

}
