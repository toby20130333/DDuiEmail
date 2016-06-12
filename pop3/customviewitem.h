#ifndef CUSTOMVIEWITEM_H
#define CUSTOMVIEWITEM_H

#include <QFrame>
#include <QPainter>
#include <QPaintEvent>
#include <QIcon>
#include <QDebug>

#include "common.h"
namespace Ui {
class CustomViewItem;
}

class CustomViewItem : public QFrame
{
    Q_OBJECT

public:
    explicit CustomViewItem(QWidget *parent = 0);
    ~CustomViewItem();

    void setSortNumber(const QString &number);
    void setHeaderImage(const QString & icon);
    void setInfo(const EMailDetails& details);
protected:
    void paintEvent(QPaintEvent *);
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
private:
    Ui::CustomViewItem *ui;
};

#endif // CUSTOMVIEWITEM_H
