#include "emailinfo.h"
#include "ui_emailinfo.h"
#include "customviewitem.h"

EMailInfo::EMailInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EMailInfo)
{
    ui->setupUi(this);
    connect(ui->listView,SIGNAL(clicked(QModelIndex)),this,SLOT(clicked(QModelIndex)));
}

EMailInfo::~EMailInfo()
{
    delete ui;
}

void EMailInfo::addItem(const EMailDetails &info)
{
    ui->listView->setInfo(info);
}

void EMailInfo::clicked(QModelIndex index)
{
//    qDebug()<<Q_FUNC_INFO<<index;
//    emit signalDataChanged(ui->listView->getIndexData(index));
    updateInfo(ui->listView->getIndexData(index));
}

void EMailInfo::updateInfo(const EMailDetails &info)
{
    ui->fromLb->setText(info.fromer);
    ui->emailTitle->setText(info.subject);
    ui->dateLb->setText(info.datetime.toString("yyyy/MM/dd hh:mm:ss"));
    ui->contentsText->clear();
    ui->contentsText->appendHtml(info.htmlTxt);
}
