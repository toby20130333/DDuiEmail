#ifndef CUSTOMITEM3_H
#define CUSTOMITEM3_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class CustomItem3;
}

class CustomItem3 : public QWidget
{
    Q_OBJECT

public:
    explicit CustomItem3(QWidget *parent = 0);
    ~CustomItem3();
    void setSortNumber(const QString& number);
protected:
    void paintEvent(QPaintEvent *);
private:
    Ui::CustomItem3 *ui;
};

#endif // CUSTOMITEM3_H
