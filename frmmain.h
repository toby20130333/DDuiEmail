#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QWidget>
//#include <QString>
#include <QChar>
#include "receive.h"
#include "common.h"
#include <QTextEdit>
#include "mainwindow.h"

#include "settings.h"

namespace Ui {
class frmMain;
}

class frmMain : public QWidget
{
    Q_OBJECT

public:
    explicit frmMain(QWidget *parent = 0);
    ~frmMain();

    void setEmailInfo(const QString& name,const QString& name1,const QString& name2,const QString& name3);
private slots:
    void on_btnSelect_clicked();

    void on_btnSend_clicked();

    void on_cboxServer_currentIndexChanged(int index);

//    void on_btn_receive_clicked();

    void on_btn_canle_clicked();

    void on_btn_save_clicked();

    void on_fontComboBox_currentTextChanged(const QString &arg1);

    
private:
    Ui::frmMain *ui;
    bool Check();

};

#endif // FRMMAIN_H
