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

    void paintEvent(QPaintEvent* e) Q_DECL_OVERRIDE;

private:
    QPixmap m_tile;
};

#endif // ALGORITHMIMAGEGRAPHICSVIEW_H
