/*********************************************************************************
  *Copyright(C),2010-2011,www.chinaBigData.com
  *FileName(文件名):  ElidedLabel.h
  *Author  (作者):    ZheHuXu(jdxchina@outlook.com)
  *Version (版本):    2.0.0
  *CreateDate(创建日期):
  *FinishDate(完成日期):
  *Description(描述):
     1.自定义标签组件，用于弹窗标题部分

**********************************************************************************/

#ifndef ELIDEDLABEL_H
#define ELIDEDLABEL_H

#include <QFrame>
#include <QLabel>
#include <QRect>
#include <QResizeEvent>
#include <QString>
#include <QWidget>

class ElidedLabel : public QLabel
{
    Q_OBJECT

    //自定义属性
    Q_PROPERTY(QString text READ text WRITE setThisText)

public:
    explicit ElidedLabel(const QString &text, QWidget *parent = 0);

    ///
    /// \brief setThisText:设置自定义Label的text属性
    /// \param text
    ///
    void setThisText(const QString &text);

    ///
    /// \brief text:读取Label的text
    /// \return
    ///
    const QString & text() const { return mContent; }

protected:
    ///
    /// \brief paintEvent:绘图事件
    /// \param event
    ///
    void paintEvent(QPaintEvent *event);

private:
    bool mElided;
    QString mContent;
    int mFontSize;
};

#endif // TEXTWRAPPINGWIDGET_H
