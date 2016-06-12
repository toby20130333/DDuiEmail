#include "elidedlabel.h"

#include <QPainter>
#include <QTextLayout>
#include <QDebug>

ElidedLabel::ElidedLabel(const QString &text, QWidget *parent)
    : QLabel(parent)
    , mElided(false)
    , mContent(text)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    this->setObjectName("ElidedLabel");
    setAlignment(Qt::AlignHCenter);
}

///
/// \brief ElidedLabel::setThisText:设置自定义Label的text属性
/// \param newText
///
void ElidedLabel::setThisText(const QString &newText)
{
    mContent = newText;
    mFontSize = this->fontMetrics().width(mContent);
    update();
}

///
/// \brief ElidedLabel::paintEvent:绘图事件
/// \param event
///
void ElidedLabel::paintEvent(QPaintEvent *event)
{
    QLabel::paintEvent(event);

    QPainter painter(this);
    QFontMetrics fontMetrics = painter.fontMetrics();

    bool didElide = false;
    int lineSpacing = fontMetrics.lineSpacing();
    int y = 0;

    QTextLayout textLayout(mContent, painter.font());
    textLayout.beginLayout();
    forever {
        QTextLine line = textLayout.createLine();

        if (!line.isValid())
            break;

        line.setLineWidth(width());
        int nextLineY = y + lineSpacing;

        if (height() >= nextLineY + lineSpacing) {
            line.draw(&painter, QPoint(0, y));
            y = nextLineY;
        } else {
            QString lastLine = mContent.mid(line.textStart());
            QString elidedLastLine = fontMetrics.elidedText(lastLine, Qt::ElideRight, width());
            if(mFontSize < width()){
                this->setText(elidedLastLine);
                break;
            }else{
                painter.drawText(QPoint(0, y + fontMetrics.ascent()), elidedLastLine);
                line = textLayout.createLine();
                didElide = line.isValid();
                break;
            }
        }
        textLayout.endLayout();
    }
}

