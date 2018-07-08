#include "cosmetic2.h"
#include "ui_cosmetic2.h"
#include<QTextStream>
#include<QDebug>
#include<QMessageBox>
#include<QStringList>
#include<QTime>
#include<QDateTime>
cosmetic2::cosmetic2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cosmetic2)
{
    ui->setupUi(this);
    readfile();
    QString line=stu_list.at(l);
    qDebug()<<line;
    QStringList subs=line.split(" ");
    qDebug()<<subs.length();
    this->ui->name->setText(subs.at(0));
    this->ui->price->setText(subs.at(1));
}

cosmetic2::~cosmetic2()
{
    delete ui;
}

void cosmetic2::on_pushButton_clicked()
{
    QString line=stu_list.at(l);
    QStringList subs=line.split(" ");
    QString name=subs.at(0);
    QString price=subs.at(1);
    QString brand=subs.at(2);
    QString inventory=subs.at(3);
    int number=this->ui->number->text().toInt();
    QString number1=this->ui->number->text();
    int manufactor=subs.at(4).toInt();
    qDebug()<<"转化之前的 "<<manufactor;
    QString class1=subs.at(5);
    manufactor=manufactor-number;
    QString man=QString::number(manufactor);
    qDebug()<<"库存量 "<<man;
    float total=number*price.toFloat();
    QString str=QString("%1").arg(total);
    QMessageBox msgBox;
     msgBox.setText(" 请确认信息 ");
     msgBox.setText(" 总共的钱数为 ");
     msgBox.setInformativeText(str);
     QString time=settime();
     QString cnt1=time+" buy "+name+" number "+number1+"manufactor last"+man+'\n';
     writetime(cnt1);
     msgBox.addButton("确定",QMessageBox::AcceptRole);
     msgBox.addButton("取消",QMessageBox::RejectRole);
    QString cnt=name+" "+price+" "+brand+" "+inventory+" "+man+" "+class1+'\n';
    stu_list[l]=cnt;
    int ret = msgBox.exec();
    switch (ret) {
       case QMessageBox::AcceptRole:
    {
        QFile file3("stu.txt");
        file3.open(QIODevice::Truncate|QIODevice::WriteOnly);
        file3.close();
                if(!file3.open(QIODevice::Append | QIODevice::Text)){
                    QMessageBox::critical(this,"错误 ","文件打开失败 ","确定");
                    return;
                }
                QTextStream out(&file3);
                for(int i=0;i<stu_list.length();i++){
                    out<<stu_list.at(i)<<'\n';
                }
                file3.close();
                this->close();
                clearslots();
    }
           // Save was clicked
           break;
       case QMessageBox::RejectRole:
        this->close();
           // Cancel was clicked
           break;
       default:
           // should never be reached
           break;
     }
}

void cosmetic2::on_pushButton_2_clicked()
{
    this->close();
}
void cosmetic2::readfile()
{
    QFile file4("new.txt");//总计
    if(!file4.open(QIODevice::ReadOnly | QIODevice::Text)){
    }
    QTextStream in(&file4);
    while(!in.atEnd()){
         l=in.readLine().toInt();
         qDebug()<<" number"<<l;
    }
    file4.close();

    QFile file("stu.txt");//打开文件
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug()<<"error!";
    }
    QTextStream in2(&file);
    while(!in2.atEnd()){
        QString m=in2.readLine();
         stu_list.append(m);
    }
    file.close();
}
void cosmetic2::writetime(QString cnt){
    QFile file("time.txt");
     if(!file.open(QIODevice::Append|QIODevice::Text)){
         QMessageBox::critical(this,"错误 ","文件打开失败","确定");
         return;
     }
     QTextStream out(&file);
     out<<cnt;
     file.close();
}
QString cosmetic2::settime(){
    QDateTime dt;
   QString s= dt.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<"time"<<s;
    return s;
}
void cosmetic2::clearslots(){
    this->ui->name->clear();
    this->ui->number->clear();
    this->ui->price->clear();
}
