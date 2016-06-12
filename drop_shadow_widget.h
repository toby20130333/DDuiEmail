/*********************************************************************************
  *Copyright(C),2014-2015,www.chinaBigData.com
  *FileName(文件名):  DropShadowWidget
  *Author  (作者):    TobyYi(tanboy@chinabigdata.com)
  *Version (版本):    2.0.0
  *CreateDate(创建日期):
  *FinishDate(完成日期):
  *Description(描述):
     1.用于主要说明此程序文件完成的主要功能
     2.与其他模块或函数的接口、输出值、取值范围、含义及参数间的控制、顺序、独立及依赖关系

  *Others(其他内容说明):
       others
  *Function List(函数列表):
     1.主要函数列表，每条记录应包含函数名及功能简要说明

     2.
  *History(历史修订记录):
     1.Date: 修改日期
       Author:修改者
       Modification:修改内容简介

     2.

**********************************************************************************/



#ifndef DROPSHADOWWIDGET_H
#define DROPSHADOWWIDGET_H

#include <QDialog>
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <qmath.h>

class DropShadowWidget : public QWidget
{
	Q_OBJECT

public:

	explicit DropShadowWidget(QWidget *parent = 0);
	~DropShadowWidget();

protected:

	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	virtual void paintEvent(QPaintEvent *event);

private:

	QPoint move_point; //移动的距离
    bool mouse_press;  //按下鼠标左键

};

#endif //DROPSHADOWWIDGET_H
