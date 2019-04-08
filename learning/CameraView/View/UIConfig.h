#ifndef UICONFIG_H
#define UICONFIG_H

#include <QSettings>
#include <QObject>

class UIConfig : public QObject
{
    Q_OBJECT
public:
    explicit UIConfig(QObject *parent = nullptr);
    ~UIConfig();

    void setValue(const QString &key, const QVariant &value);
    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;

signals:

public slots:

private:
    QSettings *settings = nullptr;

};

#endif // UICONFIG_H
