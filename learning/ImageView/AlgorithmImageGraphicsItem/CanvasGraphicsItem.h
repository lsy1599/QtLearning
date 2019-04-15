#ifndef CANVASGRAPHICSITEM_H
#define CANVASGRAPHICSITEM_H
#include <QObject>
#include <QPainterPath>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>


class CanvasGraphicsItem: public QGraphicsItem
{
public:
    CanvasGraphicsItem();

    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;


private:
    int x;
    int y;


};

#endif // CANVASGRAPHICSITEM_H
/*
 *
 *  void setFlags() 设置操作属性 例如 可选择，可移动
 *  void setOpacity() 设置透明度
 *  void setGraphicsEffect() 设置图形效果
 *  void setSelected() 设置图形别选中
 *  void setData() 用户自定义数据
 *
 *  void setX()
 *  void setY()
 *  void setZValue() //控制图形叠放次序
 *  void setPos() 图形在父项的位置
 *  void scenePos() 返回场景中的坐标系
 *  void setRotaion()  旋转角度
 *  void setScale()  缩放
 *
 *  mapFromItem()
 *  mapFromParent()
 *  mapFromScene()
 *  mapToItem()
 *  mapToParent()
 *  mapToScene()
 *
 *
 *
 *
 *
 */
