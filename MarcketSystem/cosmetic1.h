#ifndef COSMETIC1_H
#define COSMETIC1_H

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
class cosmetic1;
}

class cosmetic1 : public QDialog
{
    Q_OBJECT

public:
    explicit cosmetic1(QWidget *parent = nullptr);
    ~cosmetic1();
    int readFile();
    void doquery(QString cnt);
    void display(int row,QStringList subs);
    void setmode();
    void savefile(int numberi);

private slots:
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void show();

private:
    Ui::cosmetic1 *ui;
    QList<QString> stu_list;

    QStandardItemModel *model;
};

#endif // COSMETIC1_H
