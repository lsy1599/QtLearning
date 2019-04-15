#include "AlgorithmImageGraphics.h"
#include <QBoxLayout>
#include <QGroupBox>
#include <AlgorithmImageGraphicsItem/RectGraphicsItem.h>

AlgorithmImageGraphics::AlgorithmImageGraphics(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(800,600);

    QGroupBox *LeftGroup = new QGroupBox(this);
    LeftGroup->setFixedWidth(150);

    GraphicsScene = new AlgorithmImageGraphicsScene(0, 0, 600,500);
    GraphicsView  = new AlgorithmImageGraphicsView(GraphicsScene);

    RectGraphicsItem *pItem = new RectGraphicsItem;
    pItem->setRect(20,20,60,60);
    GraphicsScene->addItem(pItem);



    QHBoxLayout *viewLayout = new QHBoxLayout(this);
    viewLayout->addWidget(LeftGroup);
    viewLayout->addWidget(GraphicsView);
}
