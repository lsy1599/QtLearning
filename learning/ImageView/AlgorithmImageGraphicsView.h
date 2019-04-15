#ifndef ALGORITHMIMAGEGRAPHICSVIEW_H
#define ALGORITHMIMAGEGRAPHICSVIEW_H

#include <QWidget>
#include <QPixmap>
#include <QGraphicsView>
class AlgorithmImageGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    AlgorithmImageGraphicsView(QGraphicsScene *scene = Q_NULLPTR);
    ~AlgorithmImageGraphicsView() Q_DECL_OVERRIDE;


protected:
    //重写滚轮事件
    void wheelEvent(QWheelEvent* e) Q_DECL_OVERRIDE;
    //拖拽处理函数
    void dragEnterEvent(QDragEnterEvent* e) Q_DECL_OVERRIDE;
    //拖拽释放处理函数
    //void dropEvent(QDropEvent *event) Q_DECL_OVERRIDE;

//    void paintEvent(QPaintEvent* e) Q_DECL_OVERRIDE;

private:
    QPixmap m_tile;
};

/*
 * //外观设置
 *  setAlignment() 设置场景中对齐方式
 *  setBackgroundBrush() 设置背景画刷
 *  setForegroundBrush() 设置场景前景画刷
 *  setRenderHints()  设置视图的绘图选项
 *
 * //交互
 *  set setInteractive()  是否允许场景交互，键盘.鼠标
 *  QRect rubberBandRect() 返回选择矩形框
 *  void  setRubberBandSelectionMode() 选择模式
 *  QGraphicsItem* itemAt() 获取视图坐标系中某个位置处的图形项
 *  QList<QGraphicsItem*> items() 获取场景中的所有，或者某个选择区域的图形项列表
 *
 * //
 *  QPoint mapFromScene() 将场景坐标转换成视图坐标
 *  QPointF mapToScene()  将视图坐标转换成场景坐标
 *
 */




#endif // ALGORITHMIMAGEGRAPHICSVIEW_H
