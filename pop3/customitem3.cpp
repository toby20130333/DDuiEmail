#include "customitem3.h"
#include "ui_customitem3.h"

CustomItem3::CustomItem3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CustomItem3)
{
    ui->setupUi(this);
    ui->plainTextEdit->setReadOnly(true);
}

CustomItem3::~CustomItem3()
{
    delete ui;
}

void CustomItem3::setSortNumber(const QString &number)
{
    ui->label->setText("Header Image "+number);
}
void CustomItem3::paintEvent(QPaintEvent *)
 {
     QStyleOption opt;
     opt.init(this);
     QPainter p(this);
     style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
     p.drawRect(this->rect());
 }
