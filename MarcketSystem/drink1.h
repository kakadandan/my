#ifndef DRINK1_H
#define DRINK1_H

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
class drink1;
}

class drink1 : public QDialog
{
    Q_OBJECT

public:
    explicit drink1(QWidget *parent = nullptr);
    ~drink1();
    int readFile();
    void doquery(QString cnt);
    void display(int row,QStringList subs);
    void setmode();
    void savefile(int number);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

private:
    Ui::drink1 *ui;
    QList<QString> stu_list;
    void show();
    QStandardItemModel *model;
};

#endif // DRINK1_H
