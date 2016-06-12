#include "customviewitem.h"
#include "ui_customviewitem.h"

CustomViewItem::CustomViewItem(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CustomViewItem)
{
    ui->setupUi(this);
    ui->contents->setReadOnly(true);
    setStyleSheet("#contents {\
                  color:black;\
            border:1px outset;\
    border-color: gray;\
    background-color:transparent;\
    font-size:12px;\
    selection-background-color: darkgray;\
}");
}
void CustomViewItem::setSortNumber(const QString &number)
{
    ui->label->setText("Header Image "+number);
}

void CustomViewItem::setHeaderImage(const QString &icon)
{
    ui->label->setPixmap(QPixmap(icon));
}

void CustomViewItem::setInfo(const EMailDetails &details)
{
    ui->fromLb->setText(details.fromer);
    ui->dateLb->setText(details.datetime.toString("yyyy/MM/dd hh:mm"));
    ui->subjectLb->setText(details.subject);
    ui->contents->clear();
    qDebug()<<Q_FUNC_INFO<<details.htmlTxt;
    ui->contents->appendHtml(details.htmlTxt);
    if(details.hasAttament){
        ui->contents->appendHtml("<font color='red'>Has Attament:</font>"+details.attaname);
    }
}
CustomViewItem::~CustomViewItem()
{
    delete ui;
}
void CustomViewItem::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setPen(QPen(Qt::gray));
    p.drawRect(this->rect());
}

void CustomViewItem::mouseReleaseEvent(QMouseEvent *e)
{
    return QFrame::mouseReleaseEvent(e);
}

void CustomViewItem::mousePressEvent(QMouseEvent *e)
{
    return QFrame::mousePressEvent(e);
}

void CustomViewItem::mouseMoveEvent(QMouseEvent *e)
{
    return QFrame::mouseMoveEvent(e);
}
