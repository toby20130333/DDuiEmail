#ifndef EMAILVIEW_H
#define EMAILVIEW_H

#include <QWidget>
#include "frmmain.h"
#include "mainwindow.h"
#include "emailinfo.h"
#include "drop_shadow_widget.h"

#define SHADOW_WIDTH            3

namespace Ui {
class EMailView;
}

class EMailView : public QWidget
{
    Q_OBJECT

public:
    explicit EMailView(QWidget *parent = 0);
    ~EMailView();
protected:
    void mouseReleaseEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseDoubleClickEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *event);
private:
    Ui::EMailView *ui;
    frmMain *mSenderView;
    EPop3View *mRecvView;
    EMailInfo *mEInfoView;
    bool    canmove;
    QPoint  oldPos;
};

#endif // EMAILVIEW_H
