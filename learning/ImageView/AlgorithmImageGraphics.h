#ifndef ALGORITHMIMAGEGRAPHICS_H
#define ALGORITHMIMAGEGRAPHICS_H

#include <QWidget>
#include <QAction>
#include <QToolBar>
#include "AlgorithmImageGraphicsScene.h"
#include "AlgorithmImageGraphicsView.h"

class AlgorithmImageGraphics : public QWidget
{
    Q_OBJECT
public:
    explicit AlgorithmImageGraphics(QWidget *parent = nullptr);

    void initToolBar();
signals:

public slots:
    void setShape(QAction *act);

private:
    AlgorithmImageGraphicsView*  GraphicsView;
    AlgorithmImageGraphicsScene* GraphicsScene;
    QToolBar *ToolBar = Q_NULLPTR;

};

#endif // ALGORITHMIMAGEGRAPHICS_H
