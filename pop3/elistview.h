#ifndef ELISTVIEW_H
#define ELISTVIEW_H

#include <QWidget>
#include <QListView>
#include <QStandardItemModel>
#include <QHBoxLayout>
#include "listviewdelegate.h"
#include "common.h"

class EListView : public QListView
{
    Q_OBJECT
public:
    explicit EListView(QWidget *parent = 0);
    void setInfo(const EMailDetails &details);

    EMailDetails getIndexData(QModelIndex index);
signals:

public slots:
private:
    QStandardItemModel *model;
    ListviewDelegate *listdelegate;
};

#endif // ELISTVIEW_H
