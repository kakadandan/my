#ifndef DRINK2_H
#define DRINK2_H

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
class drink2;
}

class drink2 : public QDialog
{
    Q_OBJECT

public:
    explicit drink2(QWidget *parent = nullptr);
    ~drink2();

    QStringList subs;
    void writefile();
    void writetime(QString cnt);
    QString settime();
    int l;
    QString m;
    QList<QString> stu_list;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::drink2 *ui;
};

#endif // DRINK2_H
