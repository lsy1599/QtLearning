#include <QBoxLayout>
#include <QGroupBox>
#include <QToolBar>
#include <QActionGroup>
#include <QDropEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QDebug>

#include "AlgorithmImageGraphics.h"
#include "GraphicsItem/CanvasGraphicsItem.h"

AlgorithmImageGraphics::AlgorithmImageGraphics(QWidget *parent) : QWidget(parent)
{

    //初始化工具栏
    initToolBar();

    setMinimumSize(800,600);

    QGroupBox *LeftGroup = new QGroupBox(this);
    LeftGroup->setFixedWidth(150);

    GraphicsScene = new AlgorithmImageGraphicsScene(0, 0, 600,500); //构建场景大小
    GraphicsScene->setItemIndexMethod(QGraphicsScene::NoIndex); //线性索引



    GraphicsView  = new AlgorithmImageGraphicsView(GraphicsScene); //关联显示场景


   // CanvasGraphicsItem *pItem = new CanvasGraphicsItem;
   // GraphicsScene->addItem(pItem);
    GraphicsScene->addText("hello liuqingyang");
    GraphicsScene->addRect(QRect(30,40,20,20));


    QHBoxLayout *viewLayout = new QHBoxLayout(this);
    viewLayout->addWidget(LeftGroup);
    viewLayout->addWidget(ToolBar);
    viewLayout->addWidget(GraphicsView);
    GraphicsView->installEventFilter(this);//注册监视对象
}

void AlgorithmImageGraphics::initToolBar()
{
    QActionGroup *shapeGroup = new QActionGroup(this);
    QAction  *act;
    ToolBar = new QToolBar();
    ToolBar->setOrientation(Qt::Vertical);

    act = ToolBar->addAction(QIcon(":/root/Algorithm/Toolbar/images/cursor.ico"), QString("Rect"));
    act->setToolTip(QStringLiteral("移动"));
    act->setCheckable(true);
    shapeGroup->addAction(act);

    act = ToolBar->addAction(QIcon(":/root/Algorithm/Toolbar/images/rect.ico"), QString("Rect"));
    act->setToolTip(QStringLiteral("绘制矩形"));
    act->setCheckable(true);
    shapeGroup->addAction(act);

    setAcceptDrops(true);//设置接收拖拽事件


    connect(shapeGroup, SIGNAL(triggered(QAction*)), this, SLOT(setShape(QAction*)) );

}

bool AlgorithmImageGraphics::eventFilter(QObject *watched, QEvent *event)
{
    qDebug()<<"1";
    if (watched == GraphicsView)
    {
        if (event->type() == QEvent::Drop)
        {
            QDropEvent* drag = (QDropEvent*)event;
            const QMimeData* mimeData = drag->mimeData();
            if (mimeData->hasUrls())
            {
                QList<QUrl> urlList = mimeData->urls();
                if(urlList.size() > 1)
                {
                    return true;
                }else{
                    QString path = urlList.at(0).toLocalFile();
                    if(GraphicsScene->getShape() == AlgorithmImageGraphicsScene::PIXMAP)
                        GraphicsScene->addPixmapItem(path, drag->posF());
                    else{ openPixmap(path);}
                }
            }
            return true;
        }else if (event->type() == QEvent::DragEnter) {
            QDragEnterEvent* drag = (QDragEnterEvent*)event;
            drag->acceptProposedAction();
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);

}

void AlgorithmImageGraphics::setShape(QAction *act)
{
    if(act)
    {
        qDebug()<<act->text();
        if(act->text() == "Rect") {
            GraphicsScene->setShape(AlgorithmImageGraphicsScene::RECT);
        } else if (act->text() == "Cursor") {
            GraphicsScene->setShape(AlgorithmImageGraphicsScene::CURSOR);
        }

    }

}

void AlgorithmImageGraphics::openPixmap(const QString &path)
{

}
