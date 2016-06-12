#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "mailpop3.h"
#include <QMainWindow>
#include <QPair>
#include <QSettings>
#include "common.h"

class QxtMailMessage;
class EPop3View : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT
public:
    EPop3View(QWidget* parent=0);
    ~EPop3View();

    void setUserNameAndrPwd(const QString& name,const QString& pwd);
signals:
    void signalEmailDataChanged(const EMailDetails& data);
private slots:
    void connectToHost();
    void getListEmails(int list);
    void newCmd();
    void saveSettings();
    void handleQuit(int code);
    void handleStat(int code);
    void handleList(int code);
    void handleRetr(int code);
    void handleDele(int code);
    void handleRset(int code);
    void connected();
    void disconnected();
    void handleSslError(const QByteArray& msg);
    void handleAuthError(const QByteArray& msg);
    void progress(int percent);

    void on_pushButton_clicked();

private:
    enum Encryption {
        UseSSL,
        UseStartTLS,
        Clear
    };
    QSettings* settings;
    QxtPop3 *pop;
    QxtMailMessage* msg;
    void output(const QString& text,bool useCss=true) {
        if(useCss){
            QString txt = text;
            txt = txt.prepend("<font color='white'>");
            txt = txt.append("</font>");
            plainTextEdit->appendHtml(txt);
        }else{
            QString txt = text;
            txt = txt.prepend("<font color='red'>");
            txt = txt.append("</font>");
            plainTextEdit->appendHtml(txt);
        }
    }
    void printError();
    void help();
};

#endif // MAINWINDOW_H
