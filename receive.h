#ifndef RECEIVE_H
#define RECEIVE_H

#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include <QDebug>
#include "common.h"
#include <QFileSystemModel>
#include <QTreeView>

namespace Ui {
class receive;
}

class receive : public QDialog
{
    Q_OBJECT

public:
    explicit receive(QWidget *parent = 0);
    ~receive();

private slots:
    void on_btn_enter_clicked();

    void on_btn_start_receive_clicked();

    void on_pushButton_clicked();

    void on_btn_change_clicked();

    void on_btn_address_clicked();

    void on_btn_address_delete_clicked();

private:
    Ui::receive *ui;

    int count;
};

#endif // RECEIVE_H
