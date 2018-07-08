#ifndef COUNT_H
#define COUNT_H

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
class count;
}

class count : public QDialog
{
    Q_OBJECT

public:
    explicit count(QWidget *parent = nullptr);
    void setmode();
    int readFile();
    int doquery(int index,QString cnt );
    void display(int row,QStringList subs);
    ~count();

private slots:
    void on_pushButton_clicked();

private:
    Ui::count *ui;
    QList<QString> stu_list;

    QStandardItemModel *model;
};

#endif // COUNT_H
