

```
#include <QApplication>
#include <QSplitter>
#include <QTextEdit>
#include <QPixmap>
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplitter *splitterMain = new QSplitter(Qt::Horizontal);//创建水平分割窗口

    //添加控件到水平分割窗口左侧
    QTextEdit *textleft = new QTextEdit(QObject::tr("Left Widget"), splitterMain);
    textleft->setAlignment(Qt::AlignCenter);

    //创建垂直分割窗口控件，并且放到水平分割窗口的右边
    QSplitter *splitterRight = new QSplitter(Qt::Vertical, splitterMain);
    splitterRight->setOpaqueResize(false);//设置分割窗口拖动时是否实时显示分割条，true实时更新显示，false时拖拽时显示灰色，完成拖拽时在显示分割条

    //添加控件到垂直窗口 上边
    QTextEdit *textUp = new QTextEdit(QObject::tr("Top Widget"), splitterRight);
    textUp->setAlignment(Qt::AlignCenter);

    //添加控件到垂直窗口 下边
    QTextEdit *textBottom = new QTextEdit(QObject::tr("Botton Widget"), splitterRight);
    textBottom->setAlignment(Qt::AlignCenter);

    //整个窗口拖拽时,设置伸缩
    splitterMain->setStretchFactor(1,0); //设置 右上控件可伸缩
   // splitterMain->setStretchFactor(0,0); //第一个0表示插入控件的编号，第二个0设置 左边控件不可伸缩
    splitterMain->show();
    return a.exec();
}
```

![image](https://github.com/zestroly/QtLearning/blob/master/learning/Splitter.png?raw=true)
