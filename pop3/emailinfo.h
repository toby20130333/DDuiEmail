#ifndef EMAILINFO_H
#define EMAILINFO_H

#include <QWidget>
#include <QListWidget>
#include <QDebug>
#include "common.h"

namespace Ui {
class EMailInfo;
}

class EMailInfo : public QWidget
{
    Q_OBJECT

public:
    explicit EMailInfo(QWidget *parent = 0);
    ~EMailInfo();
signals:
    void signalDataChanged(const EMailDetails& details);
public slots:
    void addItem(const EMailDetails& info);
    void clicked(QModelIndex);

    void updateInfo(const EMailDetails& info);
private:
    Ui::EMailInfo *ui;
};

#endif // EMAILINFO_H
