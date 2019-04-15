#include <QBoxLayout>
#include <QGroupBox>
#include <QToolBar>
#include <QActionGroup>

#include "AlgorithmImageGraphics.h"
#include "AlgorithmImageGraphicsItem/CanvasGraphicsItem.h"

AlgorithmImageGraphics::AlgorithmImageGraphics(QWidget *parent) : QWidget(parent)
{

    //初始化工具栏
    initToolBar();

    setMinimumSize(800,600);

    QGroupBox *LeftGroup = new QGroupBox(this);
    LeftGroup->setFixedWidth(150);

    GraphicsScene = new AlgorithmImageGraphicsScene(0, 0, 600,500);
    GraphicsView  = new AlgorithmImageGraphicsView(GraphicsScene);

    CanvasGraphicsItem *pItem = new CanvasGraphicsItem;
    GraphicsScene->addItem(pItem);


    QHBoxLayout *viewLayout = new QHBoxLayout(this);
    viewLayout->addWidget(LeftGroup);
    viewLayout->addWidget(ToolBar);
    viewLayout->addWidget(GraphicsView);



}

void AlgorithmImageGraphics::initToolBar()
{
    QActionGroup *shapeGroup = new QActionGroup(this);
    QAction  *act;
    ToolBar = new QToolBar();
    ToolBar->setOrientation(Qt::Vertical);

    act = ToolBar->addAction(QIcon(":/root/Algorithm/Toolbar/images/cursor.ico"), QString("Rect"));
    act->setToolTip(QStringLiteral("绘制矩形"));
    act->setCheckable(true);
    shapeGroup->addAction(act);

    act = ToolBar->addAction(QIcon(":/root/Algorithm/Toolbar/images/rect.ico"), QString("Rect"));
    act->setToolTip(QStringLiteral("绘制矩形"));
    act->setCheckable(true);
    shapeGroup->addAction(act);


    connect(shapeGroup, SIGNAL(triggered(QAction*)), this, SLOT(setShape(QAction*)) );

}

void AlgorithmImageGraphics::setShape(QAction *act)
{
    if(act)
    {
        if(act->text() == "Rect")
        {
            GraphicsScene->setShape(AlgorithmImageGraphicsScene::RECT);
        }


    }

}
