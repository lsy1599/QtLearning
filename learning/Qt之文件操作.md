

判断文件是否存在
```
  #include <QFileInfo>
  QFileInfo file("argv[1");
  if(file.exists() == false)
  {
      qDebug("%s is no find.", argv[1]);
      qDebug("Usage:%s file.json", argv[0]);
      return -1;
  }
```
