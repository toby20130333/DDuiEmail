#include "receive.h"
#include "ui_receive.h"

receive::receive(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::receive)
{
    ui->setupUi(this);
    this->setWindowTitle("收件箱");
    this->setStyleSheet("#receive{border-image: url(:/receiv_background.jpg);}");

    count =0;

    QFileSystemModel filename;
    ui->treeView->setRootIndex(filename.setRootPath(":/"));
    ui->treeView->setModel(&filename);

}

receive::~receive()
{
    delete ui;
}

void receive::on_btn_enter_clicked()//用户名密码为空提示
{

}

void receive::on_btn_start_receive_clicked()//收件
{
    char szMailName[500] = {0};
    char szPath[300] = {0};
    for(int i=0; i <10 ; i ++)
    {
        sprintf(szMailName, "%s\%d.eml", szPath ,i); //
        qDebug() << "邮件名称"<< szMailName;
        //QFile file("test.eml");
        ui->textBrowser->append(szMailName);
        QFile file(szMailName);
        file.open(QIODevice::WriteOnly);
        file.close();
    }
}

void receive::on_pushButton_clicked()
{

}

void receive::on_btn_change_clicked()//更改背景
{
    count ++;
    switch (count) {
    case 1:
        this->setStyleSheet("#receive{border-image: url(:/send_background.jpg);}");
        break;
    case 2:
        this->setStyleSheet("#receive{border-image: url(:/background1.jpg);}");
        break;
    case 3:
        this->setStyleSheet("#receive{border-image: url(:/background2.jpg);}");
        count =0;
        break;
    default:
        break;
    }
}

void receive::on_btn_address_clicked()//加入通讯录
{
    ui->textBrowser_address->append(ui->lineEdit_address->text());
}

void receive::on_btn_address_delete_clicked()//删除通讯录
{
    ui->textBrowser_address->clear();
}
