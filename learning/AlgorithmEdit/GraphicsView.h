#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>

namespace ZAlgorithm {

class GraphicsView : public QGraphicsView
{
public:
    GraphicsView(QGraphicsScene *scene = Q_NULLPTR);
    ~GraphicsView();

protected:
    void resizeEvent(QResizeEvent *event);
    void wheelEvent(QWheelEvent *event);
};

}
#endif // GRAPHICSVIEW_H
