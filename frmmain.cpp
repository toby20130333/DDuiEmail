#include "frmmain.h"
#include "ui_frmmain.h"
#include <QFileDialog>
#include <QMessageBox>
#include "sendemailapi/smtpmime.h"

frmMain::frmMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::frmMain)
{
    ui->setupUi(this);
    this->setStyleSheet("#frmMain{border-image: url(:/send_background.jpg);}");

}

frmMain::~frmMain()
{
    delete ui;
}

void frmMain::setEmailInfo(const QString &name, const QString &name1, const QString &name2, const QString &name3)
{
    ui->txtSender->setText(name);
    ui->txtSenderPwd->setText(name1);
    ui->txtSenderAddr->setText(name2);
    ui->txtReceiverAddr->setText(name3);
}

void frmMain::on_btnSelect_clicked()//附件浏览
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec()){
        ui->txtAtta->clear();
        QStringList files=dialog.selectedFiles();
        foreach (QString file, files) {
            ui->txtAtta->setText(ui->txtAtta->text()+file+";");
        }
    }
}

bool frmMain::Check()
{
    if (ui->txtSender->text()==""){
        QMessageBox::critical(this,"错误","用户名不能为空!");
        ui->txtSender->setFocus();
        return false;
    }
    if (ui->txtSenderPwd->text()==""){
        QMessageBox::critical(this,"错误","用户密码不能为空!");
        ui->txtSenderPwd->setFocus();
        return false;
    }
    if (ui->txtSenderAddr->text()==""){
        QMessageBox::critical(this,"错误","发件人不能为空!");
        ui->txtSenderAddr->setFocus();
        return false;
    }
    if (ui->txtReceiverAddr->text()==""){
        QMessageBox::critical(this,"错误","收件人不能为空!");
        ui->txtReceiverAddr->setFocus();
        return false;
    }
    if (ui->txtTitle->text()==""){
        QMessageBox::critical(this,"错误","邮件标题不能为空!");
        ui->txtTitle->setFocus();
        return false;
    }
    Data::admin = ui->txtSender->text();
    Data::code = ui->txtSenderPwd->text();
    return true;
}

void frmMain::on_btnSend_clicked()
{
    if (!Check()){return;}

    //实例化发送邮件对象
    SmtpClient smtp(ui->cboxServer->currentText(),
                    ui->cboxPort->currentText().toInt(),
                    ui->ckSSL->isChecked()?SmtpClient::SslConnection:SmtpClient::TcpConnection);
    smtp.setUser(ui->txtSender->text());
    smtp.setPassword(ui->txtSenderPwd->text());
    connect(&smtp,&SmtpClient::smtpError,this,[](SmtpClient::SmtpError error){
        qDebug()<<Q_FUNC_INFO<<error;
    });

    //构建邮件主题,包含发件人收件人附件等.
    MimeMessage message;
    message.setSender(new EmailAddress(ui->txtSenderAddr->text()));

    //逐个添加收件人
    QStringList receiver = ui->txtReceiverAddr->text().split(';');
    for (int i = 0; i < receiver.size(); i++){
        qDebug()<<Q_FUNC_INFO<<receiver.at(i);
        message.addRecipient(new EmailAddress(receiver.at(i)));
    }
    //构建邮件标题
    message.setSubject(ui->txtTitle->text());

    //构建邮件正文
    MimeHtml text;
    //text.setHtml(ui->txtContent->toHtml());
    text.setHtml(ui->txtContent->toHtml());

    //    //如果直接发送简单文本,使用以下方法
    //    MimeText text;
    //    text.setText("测试简单文本发送!");

    message.addPart(&text);

    //构建附件
    QString atta=ui->txtAtta->text();
    if (atta!=""){
        QStringList attas=atta.split(";");
        foreach (QString tempAtta, attas) {
            QFile *file=new QFile(tempAtta);
            if (file->exists()){
                message.addPart(new MimeAttachment(file));
            }
        }
    }

    if (!smtp.connectToHost()){
        QMessageBox::critical(this,"错误","服务器连接失败!");
        return;
    }
    if (!smtp.login()){
        QMessageBox::critical(this,"错误","用户登录失败!");
        return;
    }
    if (!smtp.sendMail(message)){
        QMessageBox::critical(this,"错误","邮件发送失败!");
        return;
    }else{
        QMessageBox::information(this,"消息","邮件发送成功!");
        ESettings::getInstance()->setPassWord(ui->txtSenderPwd->text());
        ESettings::getInstance()->setYsSettings();
    }
    smtp.quit();
}

void frmMain::on_cboxServer_currentIndexChanged(int index)//服务器
{
    if (index==2){
        ui->cboxPort->setCurrentIndex(1);
        ui->ckSSL->setChecked(true);
    }else{
        ui->cboxPort->setCurrentIndex(0);
        ui->ckSSL->setChecked(false);
    }
}

//void frmMain::on_btn_receive_clicked()//接收邮件
//{
//    EPop3View *receive_interface = new EPop3View();
//    receive_interface->setUserNameAndrPwd(eSettings.getUserName(),eSettings.getPassWord());
//    receive_interface->show();
//}

void frmMain::on_btn_canle_clicked()//取消
{
    ui->txtContent->clear();
}

void frmMain::on_btn_save_clicked()//保存草稿
{
    QFile file("out.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    return;

    QTextStream out(&file);
    //out <<ui->txtContent->toHtml();
    out <<ui->txtContent->toPlainText();
    QMessageBox::information(this,"恭喜","草稿已保存成功!");
}

void frmMain::on_fontComboBox_currentTextChanged(const QString &arg1)//设置字体
{
    ui->txtContent->setFont(arg1);
    ESettings::getInstance()->setFont(arg1);
}

