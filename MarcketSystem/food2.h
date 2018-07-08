#ifndef FOOD2_H
#define FOOD2_H

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
class food2;
}

class food2 : public QDialog
{
    Q_OBJECT

public:
    explicit food2(QWidget *parent = nullptr);
    ~food2();
    QStringList subs;
    void writefile();
    void writetime(QString cnt);
    QString settime();
    int l;
    QString m;
    QList<QString> stu_list;
private slots:
    void on_pushButton_clicked();

private:
    Ui::food2 *ui;
};

#endif // FOOD2_H
