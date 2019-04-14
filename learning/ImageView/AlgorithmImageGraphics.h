#ifndef ALGORITHMIMAGEGRAPHICS_H
#define ALGORITHMIMAGEGRAPHICS_H

#include <QWidget>
#include "AlgorithmImageGraphicsScene.h"
#include "AlgorithmImageGraphicsView.h"

class AlgorithmImageGraphics : public QWidget
{
    Q_OBJECT
public:
    explicit AlgorithmImageGraphics(QWidget *parent = nullptr);

signals:

public slots:

private:
    AlgorithmImageGraphicsView*  GraphicsView;
    AlgorithmImageGraphicsScene* GraphicsScene;

};

#endif // ALGORITHMIMAGEGRAPHICS_H
