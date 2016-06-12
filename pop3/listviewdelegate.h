#ifndef LISTVIEWDELEGATE_H
#define LISTVIEWDELEGATE_H

#include <QStyledItemDelegate>
#include <QPainter>
#include <QApplication>

class ListviewDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    ListviewDelegate();
    virtual ~ListviewDelegate();

    enum datarole {
        headerTextRole = Qt::UserRole + 100,
        subHeaderTextrole = Qt::UserRole+101,
        IconRole = Qt::UserRole+102,
        DateTimeRole,
        ContentsRole,
        HasAttamentRole
    };
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index ) const;

};

#endif // LISTVIEWDELEGATE_H
