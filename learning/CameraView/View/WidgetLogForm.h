#ifndef WIDGETLOGFORM_H
#define WIDGETLOGFORM_H

#include <QWidget>

namespace Ui {
class WidgetLogForm;
}

class WidgetLogForm : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetLogForm(QWidget *parent = nullptr);
    ~WidgetLogForm();

private:
    Ui::WidgetLogForm *ui;
};

#endif // WIDGETLOGFORM_H
