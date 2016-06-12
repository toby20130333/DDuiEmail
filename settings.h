#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>
#include <QDebug>
#include "bdsimplecrypt.h"

#define YS_SETTINGS "esettings.ini"

class ESettings : public QObject
{
    Q_OBJECT
public:
     static ESettings *getInstance();
    void initYsSettings();
    void setYsSettings();


    void setUserName(const QString& name);
    void setPassWord(const QString& pwd);
    void setPort(int port);
    void setHost(const QString& host);
    void setSslUsed(bool used);

    void setSender(const QString& sender);
    void setRecVdert(const QString& revcder);
    void setFont(const QString& font);


    QString getUserName();
    QString getPassWord();
    int getPort();
    QString getHost();
    bool getSslUsed();

    QString getSender();
    QString getRecVdert();
    QString getFont();

signals:

public slots:
private:
    explicit ESettings(QObject *parent = 0);

    QString username;
    QString password;
    int port;
    QString host;
    bool sslused;
    QString sender;
    QString revder;
    QString font;
};
#endif // SETTINGS_H
