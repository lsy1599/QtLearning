


```
QAction *newFile = new QAction(QIcon("newproject.png"), tr("新建"), this);
newFile->setShortcut(tr("Ctrl+O"));
newFile->setStatusTip(tr("新建"));
connect(newFile, SIGNAL(triggered()), this, SLOT(newFile()));

//菜单栏天添加
QMenu *fileMenu = menuBar()->addMenu(tr("文件"));
fileMenu->addAction(newFile);

//工具栏
QToolBar *toolbars = addToolBar("File");
toolbars->addAction(newFile);

```
![图片](md/qaction.png)
