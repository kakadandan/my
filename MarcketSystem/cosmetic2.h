#ifndef COSMETIC2_H
#define COSMETIC2_H

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
class cosmetic2;
}

class cosmetic2 : public QDialog
{
    Q_OBJECT

public:
    explicit cosmetic2(QWidget *parent = nullptr);
    ~cosmetic2();
    void readfile();
    void writetime(QString cnt);
    QString settime();
    QStringList subs;
    int l;
    QString m;
    QList<QString> stu_list;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();
    void clearslots();

private:
    Ui::cosmetic2 *ui;
};

#endif // COSMETIC2_H
