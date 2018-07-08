#ifndef GOOD1_H
#define GOOD1_H

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
class good1;
}

class good1 : public QDialog
{
    Q_OBJECT

public:
    explicit good1(QWidget *parent = nullptr);
    ~good1();
    int readFile();
    void doquery(QString cnt);
    void display(int row,QStringList subs);
    void setmode();
    void savefile(int numberi);
    void show();

private slots:
    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::good1 *ui;
    QList<QString> stu_list;

    QStandardItemModel *model;
};

#endif // GOOD1_H
