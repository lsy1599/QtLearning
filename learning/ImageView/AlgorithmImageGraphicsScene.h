#ifndef ALGORITHMIMAGEGRAPHICSSCENE_H
#define ALGORITHMIMAGEGRAPHICSSCENE_H

#include <QObject>
#include <QGraphicsScene>

class AlgorithmImageGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    enum SHAPE{
        CURSOR,
        RECT,
        DELETE,
        PIXMAP,
    };
    explicit AlgorithmImageGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = Q_NULLPTR);
    ~AlgorithmImageGraphicsScene();

    SHAPE getShape();
    void  setShape(SHAPE shape);

    void addPixmapItem(const QString &file, const QPointF &pos);

public slots:
    void stickItem();
    void zoomUpItem();
    void zoomDownItem();
    void rotationItem();
    void setItemText();
    void slotPenChanged(const QPen &pen);
    void slotBrushChanged(const QBrush &brush);
    void slotFontChanged(const QFont &font);

protected:
    bool event(QEvent *event);
    void wheelEvent(QGraphicsSceneWheelEvent *ev);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    bool paintPolygon(QEvent *event);

private:
    SHAPE meShape = CURSOR;
    QGraphicsItem* selectItem = Q_NULLPTR;
};
/*
 *  void setSceneRect() //设置场景大小
 *
 *  QGraphicsItemGroup* createItemGroup() //创建图形项组
 *  void destroyItemGroup() //销毁图形项组
 *
 *  QGraphicsItem* focusItem() //返回当前获取焦点的图形项
 *  void clearFocus() //去除选择焦点
 *  bool hasFocus() //判断是否有焦点图形项
 *
 *  void addItem() //添加图形项
 *  void removeItem(); //删除图形项
 *  void clear(); //清理所有图形项
 *  QGraphicsItem* mouseGrabberItem() //返回鼠标抓取的图形项
 *  QList<QgraphicsItem*> selectedItems() //返回选择图形项列表
 *  void  clearSelection() //清除所有选择
 *  QGraphicsItem* itemAt() //获取某个位置的顶层图形项
 *  QList<QGraphicsItem*> items() //返回某个区域的图形项列表
 *
 * QGraphicsEllpseItem*  addEllipse() //添加椭圆
 * QGraphicsLineItem*    addLine()  //添加一条直线
 * QGraphicsPathItem*    addPath() //添加绘图路径
 * QGraphicsPixmapItem*  addPixmap() //添加图片
 * QGraphicsPolygonItem* addPolygon() // 添加多边形
 * QGraphicsRectItem*    addRect() //添加矩形
 * QGraphicsSimpleTextItem* addSimpleText() //添加简单文字
 * QGraphicsTextItem* addText() //添加字符串
 * QGraphicsProxyWidget* addWidget() 添加界面组件
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */


#endif // ALGORITHMIMAGEGRAPHICSSCENE_H
