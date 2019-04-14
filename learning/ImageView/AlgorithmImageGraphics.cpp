#include "AlgorithmImageGraphics.h"
#include <QBoxLayout>
#include <QGroupBox>

AlgorithmImageGraphics::AlgorithmImageGraphics(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(800,600);

    QGroupBox *LeftGroup = new QGroupBox(this);
    LeftGroup->setFixedWidth(150);


    GraphicsScene = new AlgorithmImageGraphicsScene(0, 0, 600,500);
    GraphicsView  = new AlgorithmImageGraphicsView(GraphicsScene);


    QHBoxLayout *viewLayout = new QHBoxLayout(this);
    viewLayout->addWidget(LeftGroup);
    viewLayout->addWidget(GraphicsView);
}
