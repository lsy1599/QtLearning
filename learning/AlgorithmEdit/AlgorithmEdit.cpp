#include "AlgorithmEdit.h"
#include <QBoxLayout>
#include <QToolBar>
#include <QActionGroup>
#include <QGroupBox>
#include <GraphicsItem/RectItem.h>

#include <QDebug>
namespace ZAlgorithm {

AlgorithmEdit::AlgorithmEdit(QWidget *parent)
    : QWidget(parent)
{
    InitToolBar();

    setMinimumSize(800, 600);
    QGroupBox *LeftGroup = new QGroupBox(this);
    LeftGroup->setFixedWidth(150);

    Scene = new GraphicsScene();
    View  = new GraphicsView(Scene);


#if 0
    RectItem* rectItem = new RectItem();
    rectItem->setRect(20,20,60,60);
    Scene->addItem(rectItem);
    Scene->addText("hello");
#endif



    QHBoxLayout *viewLayout = new QHBoxLayout(this);
    viewLayout->addWidget(LeftGroup);
    viewLayout->addWidget(ToolBar);
    viewLayout->addWidget(View);
}

AlgorithmEdit::~AlgorithmEdit()
{

}

void AlgorithmEdit::InitToolBar()
{
    QActionGroup *shapeGroup = new QActionGroup(this);
    QAction  *act;
    ToolBar = new QToolBar();
    ToolBar->setOrientation(Qt::Vertical);
    //ToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    act = ToolBar->addAction(QIcon(":/Algorithm/ico/loadPicture_64px.ico"), QString("Pixmap"));
    act->setToolTip(QStringLiteral("加载图片"));
    shapeGroup->addAction(act);


    act = ToolBar->addAction(QIcon(":/Algorithm/ico/cursor.ico"), QString("Cursor"));
    act->setToolTip(QStringLiteral("移动"));
    act->setCheckable(true);
    shapeGroup->addAction(act);

    act = ToolBar->addAction(QIcon(":/Algorithm/ico/rect.ico"), QString("Rect"));
    act->setToolTip(QStringLiteral("绘制矩形"));
    act->setCheckable(true);
    shapeGroup->addAction(act);

    setAcceptDrops(true);//设置接收拖拽事件

    connect(shapeGroup, SIGNAL(triggered(QAction*)), this, SLOT(setShape(QAction*)) );

}

void AlgorithmEdit::setShape(QAction *act)
{
    if(act)
    {
        if(act->text() == "Rect") {
            Scene->setShape(GraphicsScene::RECT);
        } else if (act->text() == "Cursor") {
            Scene->setShape(GraphicsScene::CURSOR);
        } else if (act->text() == "Pixmap") {
            Scene->setShape(GraphicsScene::PIXMAP);
        }

    }

}


}
