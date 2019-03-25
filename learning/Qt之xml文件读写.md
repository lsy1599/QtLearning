


xml文件读取
```
<?xml version="1.0" encoding="UTF-8"?>
<test>
    <TestUnit name="开始时间">
    </TestUnit>
    <TestUnit name="串口测试">
    </TestUnit>
    <TestUnit name="RTC测试">
    </TestUnit>
</test>

```

```
#include <QDomDocument>
void Widget::readerXml()
{
    QDomDocument doc;
    QFile file(configfile);
    if( !file.open(QIODevice::ReadOnly))
        return;

    int iErrCount;
    int iErrLine;
    QString strError;

    if( !doc.setContent(&file, false, &strError, &iErrLine, &iErrCount))
    {

        file.close();
        return;
    }

    QDomElement root = doc.documentElement();//获取根节点

    QDomNode n = root.firstChild();//获取第一个子节点
    while( !n.isNull())
    {

        QDomElement e = n.toElement();//获取子节点的element
        if( !e.isNull())
        {
            if( e.nodeName() == "TestUnit") //获取子节点名称
            {
                if(!e.hasAttribute("name")) //判断是否窜在name属性值
                {
                    n = n.nextSibling();
                    continue;
                }


                QDomNodeList nlist = e.childNodes();
                for( int a = 0; a < nlist.count(); a++)
                {
                    QDomNode node = nlist.at(a);
                    if(node.isElement())
                    {
                        qDebug()<<node.toElement().nodeName()<< node.toElement().text();

                      }
                  }
               m_AllUnit.append(unitBase);


            }
        }

        n = n.nextSibling();
    }
}
```
