#ifndef GOOD2_H
#define GOOD2_H

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
class good2;
}

class good2 : public QDialog
{
    Q_OBJECT

public:
    explicit good2(QWidget *parent = nullptr);
    ~good2();
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
    Ui::good2 *ui;
};

#endif // GOOD2_H
