#include "settings.h"
static ESettings *sExterNewHeader = NULL;

ESettings::ESettings(QObject *parent) : QObject(parent)
{

}
ESettings *ESettings::getInstance()
{
    if(sExterNewHeader == NULL) {
        sExterNewHeader = new ESettings;
    }
    return sExterNewHeader;
}

void ESettings::initYsSettings()
{
    QSettings     m_ysSettings(YS_SETTINGS,
                               QSettings::IniFormat);
    m_ysSettings.setIniCodec("UTF-8");
    QStringList groupLst = m_ysSettings.childGroups();
    if(groupLst.isEmpty())return;
    for(int i=0;i<groupLst.count();i++){
        m_ysSettings.beginGroup(groupLst.at(i));
        if(groupLst.at(i) == "info"){
            username = m_ysSettings.value("username","example").toString();
            QByteArray pwdByte = m_ysSettings.value("password","123456").toByteArray();
            SimpleCrypt m_Crypt(Q_UINT64_C(0x0c2ad4a4acb9f023));
            QByteArray str = m_Crypt.decryptToByteArray(pwdByte);
            password = QString(str);
            host = m_ysSettings.value("stmphost","smtp.163.com").toString();
            port = m_ysSettings.value("stmpport","25").toInt();
            sslused = m_ysSettings.value("stmpssl",true).toBool();
        }else if(groupLst.at(i) == "contents"){
            sender = m_ysSettings.value("sender","18763181176@163.com").toString();
            revder = m_ysSettings.value("recder","18763181176@163.com").toString();
            font = m_ysSettings.value("font","微软雅黑").toString();
        }
        m_ysSettings.endGroup();
    }
//    qDebug()<<" read inin file to memory: "<<username<<"\n"<<this->password;
}
void ESettings::setYsSettings()
{
    qDebug()<<"setYsSettings size: "<<endl;
    QSettings     m_ysSettings(YS_SETTINGS,
                               QSettings::IniFormat);
    m_ysSettings.setIniCodec("UTF-8");
    m_ysSettings.beginGroup("info");
    m_ysSettings.setValue("username",username);
    SimpleCrypt m_Crypt(Q_UINT64_C(0x0c2ad4a4acb9f023));
    QByteArray pwdArr = m_Crypt.encryptToByteArray(password.toUtf8());
    m_ysSettings.setValue("password",pwdArr);
    m_ysSettings.setValue("stmphost",host);
    m_ysSettings.setValue("stmpport",port);
    m_ysSettings.setValue("stmpssl",sslused);
    m_ysSettings.endGroup();

    qDebug()<<"setYsSettings size:is style  ";
    m_ysSettings.beginGroup("contents");
    m_ysSettings.setValue("sender",sender);
    m_ysSettings.setValue("recder",revder);
    m_ysSettings.setValue("font",font);
    m_ysSettings.endGroup();
}

void ESettings::setUserName(const QString &name)
{
    username = name;
}

void ESettings::setPassWord(const QString &pwd)
{
    password = pwd;
}

void ESettings::setPort(int port)
{
    this->port = port;
}

void ESettings::setHost(const QString &host)
{
    this->host = host;
}

void ESettings::setSslUsed(bool used)
{
    sslused = used;
}

void ESettings::setSender(const QString &sender)
{
    this->sender = sender;
}

void ESettings::setRecVdert(const QString &revcder)
{
    this->revder = revcder;
}

void ESettings::setFont(const QString &font)
{
    this->font = font;
}

QString ESettings::getUserName()
{
    return username;
}

QString ESettings::getPassWord()
{
    return password;
}

int ESettings::getPort()
{
    return port;
}

QString ESettings::getHost()
{
    return host;
}

bool ESettings::getSslUsed()
{
    return sslused;
}

QString ESettings::getSender()
{
    return sender;
}

QString ESettings::getRecVdert()
{
    return revder;
}

QString ESettings::getFont()
{
    return font;
}
