#include "WidgetLogForm.h"
#include "ui_WidgetLogForm.h"

WidgetLogForm::WidgetLogForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetLogForm)
{
    ui->setupUi(this);
}

WidgetLogForm::~WidgetLogForm()
{
    delete ui;
}
