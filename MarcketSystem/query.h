#ifndef QUERY_H
#define QUERY_H

#include <QDialog>
#include<QTextStream>
#include<QDebug>
#include<QMessageBox>
#include<QStringList>
#include"QList"
#include"QFile"
#include <QString>
#include<QStandardItem>
#include<QStandardItemModel>

namespace Ui {
class query;
}

class query : public QDialog
{
    Q_OBJECT

public:
    explicit query(QWidget *parent = nullptr);
    ~query();
    int readFile();
    void doquery(int index,QString cnt);
    void display(int row,QStringList subs);
    void setmode();
    Ui::query *ui;
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:

    QList<QString> stu_list;

    QStandardItemModel *model;
};

#endif // QUERY_H
