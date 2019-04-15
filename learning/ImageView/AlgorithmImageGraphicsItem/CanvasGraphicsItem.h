#ifndef CANVASGRAPHICSITEM_H
#define CANVASGRAPHICSITEM_H

#include <QObject>

class CanvasGraphicsItem : public QObject
{
    Q_OBJECT
public:
    explicit CanvasGraphicsItem(QObject *parent = nullptr);

signals:

public slots:
};

#endif // CANVASGRAPHICSITEM_H