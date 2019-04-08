#include "UIConfig.h"

UIConfig::UIConfig(QObject *parent) : QObject(parent)
{
    settings = new QSettings("UIConfig.ini", QSettings::IniFormat);
}

UIConfig::~UIConfig()
{
    delete settings;
}

void UIConfig::setValue(const QString &key, const QVariant &value)
{
    settings->setValue(key, value);
}

QVariant UIConfig::value(const QString &key, const QVariant &defaultValue) const
{
    return settings->value(key, defaultValue);
}
