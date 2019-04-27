#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qttreepropertybrowser.h"
#include "qtpropertymanager.h"
#include "qtpropertybrowser.h"
#include "qteditorfactory.h"
#include "qtvariantproperty.h"
#include "QAbstractItemDelegate"
#include <QHBoxLayout>
#include <QDockWidget>
#include <QUndoStack>
#include <QUndoView>
#include <QMdiSubWindow>
#include <QMdiArea>
#include <QListWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    QUndoStack *undoStack = new QUndoStack(this); //设置操作记录
    QUndoView* undoView = new QUndoView(undoStack); //
    undoView->setWindowTitle(tr("Command List"));

    //自定义窗口默认Qt::WA_QuitOnClose为true，如果主窗口关闭时还有自定义窗口打开，则程序还是不会退出，而是等到最后一个窗口关闭之后才退出。
    undoView->setAttribute(Qt::WA_QuitOnClose, false); //窗口关闭时触发 触发关闭


    QtTreePropertyBrowser* propertyeditor = new QtTreePropertyBrowser(this);
    QtVariantPropertyManager*  m_pVarManager =new QtVariantPropertyManager(propertyeditor);
    QtVariantProperty *item =m_pVarManager->addProperty(QVariant::Int, QStringLiteral("整形数据："));
    item->setValue(101);
    propertyeditor->addProperty(item);
    item =m_pVarManager->addProperty(QVariant::Bool, QStringLiteral("布尔型数据："));
    item->setValue(true);
    propertyeditor->addProperty(item);
    item =m_pVarManager->addProperty(QVariant::Double, QStringLiteral("浮点数据："));
    item->setValue(3.1415926);
    propertyeditor->addProperty(item);
    item =m_pVarManager->addProperty(QVariant::String, QStringLiteral("字符串数据："));
    propertyeditor->addProperty(item);
    item->setValue(QStringLiteral("尘中远"));

    QDockWidget *dock = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock);
    dock->setWidget(propertyeditor);

    QDockWidget *dock1 = new QDockWidget(this);
    addDockWidget(Qt::RightDockWidgetArea, dock1);
    dock1->setWidget(undoView);
    dock1->setFeatures(QDockWidget::NoDockWidgetFeatures);//设置不可拖动
    dock1->setFeatures(QDockWidget::AllDockWidgetFeatures);

    QMdiArea*  mdiArea = new QMdiArea;
    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    setCentralWidget(mdiArea); //设置midArea为this中心窗口，并且停保此处
    setWindowTitle(tr("Qt Drawing"));
    setUnifiedTitleAndToolBarOnMac(true); //在Mac os 去除标题栏和 工具栏的分割线


    QListWidget *listWidget = new QListWidget;
    listWidget->setViewMode(QListView::IconMode);
    listWidget->setDragDropMode(QAbstractItemView::NoDragDrop); //内部不可以拖拽
    listWidget->setStyleSheet(tr("QListView {background-color: mediumaquamarine;}"));

    dock = new QDockWidget(this);
    addDockWidget(Qt::LeftDockWidgetArea, dock);
    dock->setWidget(listWidget);


}

MainWindow::~MainWindow()
{
    delete ui;
}
