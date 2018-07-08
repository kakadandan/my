#include "manager2.h"
#include "ui_manager2.h"
#include"query.h"
#include"count.h"
#include<QProcess>
manager2::manager2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager2)
{
    ui->setupUi(this);
}

manager2::~manager2()
{
    delete ui;
}

void manager2::on_pushButton_clicked()
{
    query q;
    q.exec();
}

void manager2::on_pushButton_4_clicked()
{
    this->close();
}

void manager2::on_pushButton_2_clicked()
{
    count c;
    c.exec();
}

void manager2::on_pushButton_3_clicked()
{
    QFile file("time.txt");//打开文件
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"error!";
    }
    QTextStream in2(&file);
    while(!in2.atEnd()){
        QString m=in2.readLine();
         stu.append(m);
    }
    for(int i=0;i<stu.length();i++){
        qDebug()<<"日志信息 "<<i;
        qDebug()<<stu.at(i);

    }
    file.close();
}
