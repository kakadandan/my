#ifndef FOOD1_H
#define FOOD1_H

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
class food1;
}

class food1 : public QDialog
{
    Q_OBJECT

public:
    explicit food1(QWidget *parent = nullptr);
    ~food1();
    int readFile();
    void doquery(QString cnt);
    void display(int row,QStringList subs);
    void setmode();
    void savefile(int numberi);
    void show();
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::food1 *ui;
    QList<QString> stu_list;

    QStandardItemModel *model;
};

#endif // FOOD1_H
