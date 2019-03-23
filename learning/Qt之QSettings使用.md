
```
  QSettings *settings = new QSettings (filename,QSettings::IniFormat);
  settings->beginGroup("SerialPort");
  settings->value("port",0).toInt();
  settings->setValue("port", 0);
  delete settings;    //删除指针，防止内存泄露

```
