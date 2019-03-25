

设置QLabel显示图片过大时生产滚动条
```
  QLabel *lbl = new QLabel(this);
  QImage img("path");
  lbl->setPixmap(QPixmap::fromImage(img));
  QScrollArea* area = new QScrollArea(this);
  area->setWidget(lbl);
  area->setBackgroundRole(QPaletter::Dark);
  area->setGenmetry(0, 0, img.width(), img.height()-生产滚动条

```
