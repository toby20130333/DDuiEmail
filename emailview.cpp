#include "emailview.h"
#include "ui_emailview.h"

EMailView::EMailView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EMailView)
{
    ui->setupUi(this);
    setWindowTitle(tr("多多指教版本邮件客户端"));
    canmove = false;
    ESettings::getInstance()->initYsSettings();
    mSenderView = new frmMain;
    mSenderView->setEmailInfo(ESettings::getInstance()->getUserName(),ESettings::getInstance()->getPassWord(),ESettings::getInstance()->getSender(),ESettings::getInstance()->getRecVdert());
    mRecvView = new EPop3View;
    mRecvView->setUserNameAndrPwd(ESettings::getInstance()->getUserName(),ESettings::getInstance()->getPassWord());

    mEInfoView = new EMailInfo;
    connect(mRecvView,SIGNAL(signalEmailDataChanged(EMailDetails)),mEInfoView,SLOT(addItem(EMailDetails)));
    ui->tabWidget->addTab(mSenderView,tr("发送邮件"));
    ui->tabWidget->addTab(mRecvView,tr("接收邮件"));
    ui->tabWidget->addTab(mEInfoView,tr("邮件详情"));

    QPushButton *btn = new QPushButton("关闭");
    btn->setObjectName("closebtn");
    btn->setFixedWidth(30);
    ui->tabWidget->setCornerWidget(btn,Qt::TopRightCorner);
    connect(btn,&QPushButton::clicked,this,[](){
        ESettings::getInstance()->setYsSettings();
        qApp->quit();
    });
}

EMailView::~EMailView()
{
    delete ui;
}
void EMailView::mouseReleaseEvent(QMouseEvent *e)
{
    canmove = false;
    QWidget::mouseReleaseEvent(e);
}

void EMailView::mousePressEvent(QMouseEvent *e)
{
    QRect rect(110,0,this->width()-20,30);
    if(rect.contains(e->pos())){
        canmove = true;
        oldPos = e->pos();
    }
    QWidget::mousePressEvent(e);
}

void EMailView::mouseMoveEvent(QMouseEvent *e)
{
    if(canmove)
    {
        // qDebug() << "nowPos:" << e->globalPos();
        this->move(e->globalPos() - oldPos);
    }
    QWidget::mouseMoveEvent(e);
}

void EMailView::mouseDoubleClickEvent(QMouseEvent *)
{
    if(this->isMaximized()){
        this->showNormal();
    }else{
        this->showMaximized();
    }
}
void EMailView::paintEvent(QPaintEvent *event)
{
    if(this->isMaximized()){
        ui->gridLayout->setContentsMargins(0,0,0,0);
    }else{
        ui->gridLayout->setContentsMargins(1,1,1,1);
    }
//    DropShadowWidget::paintEvent(event);
//    int height =35;
//    QPainter painter(this);
//    painter.setPen(Qt::NoPen);
    //    painter.setBrush(QColor("#4F9DE0"));
    //    painter.drawPixmap(QRect(SHADOW_WIDTH, SHADOW_WIDTH, this->width()-2*SHADOW_WIDTH, this->height()-2*SHADOW_WIDTH), QPixmap("E:/MyPersional/qt-email/send_background.jpg"));
    //    painter.drawRect(QRect(SHADOW_WIDTH, height, this->width()-2*SHADOW_WIDTH, this->height()-height-SHADOW_WIDTH));
}
