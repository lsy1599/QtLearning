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
    };
    explicit AlgorithmImageGraphicsScene(qreal x, qreal y, qreal width, qreal height, QObject *parent = Q_NULLPTR);
    ~AlgorithmImageGraphicsScene();

    SHAPE getShape();
    void  setShape(SHAPE shape);

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

#endif // ALGORITHMIMAGEGRAPHICSSCENE_H
