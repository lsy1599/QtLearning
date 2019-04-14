

```
QPainter类的成员角色有:
QPen         : 用于绘制几何图形的边缘,由颜色,宽度,线风格等参数组成
QBrush     : 用于填充几何图形的调色板,由颜色和填充风格组成
QFont       : 用于文本绘制
QPixmap  : 绘制图片,可以加速显示,带有屏幕截图,窗口截图等支持,适合小图片
QImage    : 绘制图片,可以直接读取图像文件进行像素访问,适合大图片
QBitmap  : QPixmap的一个子类，主要用于显示单色位图
QPicture  : 绘图装置，用于记录和重播Qpainter的绘图指令
```


QPainter基础图形绘制相关函数:

函数|内容
--|--
drawPoint()         |绘制点
drawPoints()        |绘制多个点
drawPath()          |路径
drawLines()         |绘制多条线
drawLine()          |绘制直线
drawPolyline()      |绘制折线
drawLineSegments()  |绘制折线
drawPath()          |路径
drawRect()          |绘制矩形
drawArc()           |绘制圆弧
drawEllipse()       |绘制椭圆
drawPie()           |绘制扇形
drawChord()         |绘制弦
drawPolygon()       |绘制多边形
drawRoundedRect()   |绘制圆角矩形
drawConvexPolygon() |绘制凸多边形
setClipRect()       |区域内的图像会被显示，其余部分不显示
setRenderHint()     |设置反走样，要么绘制出来的线条会出现锯齿,设置反走样，要么绘制出来的线条会出现锯齿
drawTiledPixmap()   |平铺图像
drawPicture()       |按QPainter指令绘制


QPainter painter(this);
painter.setPen(    QPen(QColor(11,67,127),3));
QRectF rect(40.0, 40.0, 100.0, 100.0);
painter.setRenderHint(QPainter:: Antialiasing, true);  //设置渲染,启动反锯齿
painter.drawArc(rect,30*16,150*16); //绘画角度为30°~(30+150°)
painter.drawPoint(40+50,40+50);     //绘制中心点


QPainter painter(this);
painter.setRenderHint(QPainter:: Antialiasing, true);  //设置渲染,启动反锯齿
painter.setPen( QPen(QColor(11,67,127),3));
painter.drawEllipse(40.0, 40.0, 100.0, 100.0);   //半径为50的圆



QPainter painter(this);
painter.setPen(QPen(QColor(11,67,127),3));
QRectF rect(40.0, 40.0, 100.0, 100.0);
painter.setRenderHint(QPainter:: Antialiasing, true);  //设置渲染,启动反锯齿
painter.drawPie(rect,30*16,150*16); //绘画角度为30°~(30+150°)


QPainter painter(this);
painter.setPen(QPen(QColor(11,67,127),3));
QRectF rect(40.0, 40.0, 100.0, 100.0);
painter.setRenderHint(QPainter:: Antialiasing, true);  //设置渲染,启动反锯齿
painter.drawChord(rect,30*16,150*16);       //绘画角度为30°~(30+150°)

Qpainter通过drawText来绘制文本
void MainWindow::paintEvent(QPaintEvent *)
{
QPainter painter(this);
QFont font;
font.setPixelSize(24); //设置字体像素大小为12
QString text="1234567"; //设置显示的文本
QFontMetrics metrics(font);
int w=metrics.width(text); //获取显示文本的宽度
int h=metrics.height(); //获取显示文本的高度
painter.setFont(font);
painter.setPen(Qt::blue);
painter.drawText(QRect(width()/2-w,height()/2-h,w,h),text);
painter.drawRect(QRect(width()/2-w,height()/2-h,w,h));
qDebug()<<"w:"<<w; //一个字符大小为12*24,所以宽度为12*7
qDebug()<<"h:"<<h; //高度为24
}


```
//绘制图像背景
m_tile = QPixmap(128, 128);
m_tile.fill(Qt::white);
QPainter pt(&m_tile);
QColor color(230, 230, 230);
pt.fillRect(0, 0, 64, 64, color);
pt.fillRect(64, 64, 64, 64, color);
pt.end(); //QPixmap 构造的时候会调用beign ，虚构的时候自动调用end，end表示绘制结束后 进行渲染
```


```
save() 和 restore() 可以以堆栈的形式嵌套式地保存和恢复，最后保存的先恢复
```


```

```
