#include "frmmain.h"
#include <QApplication>
#include <QTextCodec>
#include <QDesktopWidget>
#include "emailview.h"
#include "customviewitem.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //设置UTF-8编码（万国码），用在网页上可以同一页面显示中文简体繁体及其它语言（如英文，日文，韩文）。
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

    QFile file("demo.qss");
    if(file.open(QIODevice::ReadOnly)){
        qApp->setStyleSheet(file.readAll());
        file.close();
    }else{
        QFile file(":/demo.qss");
        if(file.open(QIODevice::ReadOnly)){
            qApp->setStyleSheet(file.readAll());
        }
        file.close();
    }
    // myemail w;
    EMailView w;
    w.setWindowFlags(Qt::FramelessWindowHint);

//    CustomViewItem item;
//    item.show();
    //设置窗体居中
    int deskWidth=qApp->desktop()->availableGeometry().width();
    int deskHeigth=qApp->desktop()->availableGeometry().height();
    int frmX=w.width();
    int frmY=w.height();
    QPoint movePoint(deskWidth/2-frmX/2,deskHeigth/2-frmY/2);
    w.move(movePoint);
    w.show();

    return a.exec();
}
