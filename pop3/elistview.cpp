#include "elistview.h"

EListView::EListView(QWidget *parent) :
    QListView(parent)
{
    model = new QStandardItemModel();
    this->setEditTriggers(NoEditTriggers);
    listdelegate = new ListviewDelegate();
    setItemDelegate(listdelegate);
    setModel(model);
}
void EListView::setInfo(const EMailDetails &details)
{
    QStandardItem *item = new QStandardItem();
    QIcon icon(":/header.png");
    item->setData(details.fromer,ListviewDelegate::headerTextRole);
    item->setData(details.subject,ListviewDelegate::subHeaderTextrole);
    item->setData(icon,ListviewDelegate::IconRole);
    item->setData(details.datetime,ListviewDelegate::DateTimeRole);
    item->setData(details.htmlTxt,ListviewDelegate::ContentsRole);
    item->setData(details.hasAttament,ListviewDelegate::HasAttamentRole);
    model->appendRow(item);
}

EMailDetails EListView::getIndexData(QModelIndex index)
{
    if(index.isValid()){
        EMailDetails info;
        info.fromer =  model->data(index,ListviewDelegate::headerTextRole).toString();
        info.subject =  model->data(index,ListviewDelegate::subHeaderTextrole).toString();
        info.datetime =  model->data(index,ListviewDelegate::DateTimeRole).toDateTime();
        info.htmlTxt =  model->data(index,ListviewDelegate::ContentsRole).toString();
        info.hasAttament =  model->data(index,ListviewDelegate::HasAttamentRole).toBool();
        return info;
    }
}
