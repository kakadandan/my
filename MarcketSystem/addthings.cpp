#include "addthings.h"
#include "ui_addthings.h"
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<QPushButton>
#include<QList>
#include<QAbstractButton>
#include<QCheckBox>
#include<QFile>
#include<QTextStream>
#include<QIODevice>
#include<QTime>
#include<QDateTime>
addthings::addthings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addthings)
{
    ui->setupUi(this);
}

addthings::~addthings()
{
    delete ui;
}

void addthings::on_stn_yes_clicked()
{
    QString name=this->ui->name->text();
    QString price=this->ui->price->text();
    QString brand=this->ui->brand->text();
    QString inventory=this->ui->inventory->text();
    QString manufacter=this->ui->manufacter->text();
    QString class1=this->ui->class_2->currentText();

    QMessageBox msgBox;
     msgBox.setText(" 请确认信息 ");
     msgBox.setInformativeText(name+'\n'+price+'\n'+brand+'\n'+inventory+'\n'+manufacter+'\n'+class1+'\n');
     msgBox.addButton("确定",QMessageBox::AcceptRole);
     msgBox.addButton("取消",QMessageBox::RejectRole);
    QString cnt=name+" "+price+" "+brand+" "+inventory+" "+manufacter+" "+class1+" "+"\n";
     int ret = msgBox.exec();
     switch (ret) {
        case QMessageBox::AcceptRole:{
         clearUserTnterface();
               writefileof(cnt);
               QString s= settime()+" add "+cnt;
               writetime(s);

     }break;
        case QMessageBox::RejectRole:
         this->close();
            break;
        default:
            // should never be reached
            break;
      }
}
void  addthings::clearUserTnterface(){
    this->ui->name->clear();
    this->ui->brand->clear();
    this->ui->inventory->clear();
    this->ui->manufacter->clear();
    this->ui->price->clear();
    this->ui->class_2->setCurrentIndex(0);
    this->ui->name->setFocus();
}
void addthings::writefileof(QString cnt){

       QFile file("stu.txt");
        if(!file.open(QIODevice::Append|QIODevice::Text)){
            QMessageBox::critical(this,"错误 ","文件打开失败","确定");
            return;
        }
        QTextStream out(&file);
        out<<cnt;
        file.close();
}


void addthings::on_stn_no_clicked()
{
    this->close();
}
void addthings::writetime(QString cnt){
    QFile file("time.txt");
     if(!file.open(QIODevice::Append|QIODevice::Text)){
         QMessageBox::critical(this,"错误 ","文件打开失败","确定");
         return;
     }
     QTextStream out(&file);
     out<<cnt;
     file.close();
}
QString addthings::settime(){
    QDateTime dt;
   QString s= dt.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    qDebug()<<"time"<<s;
    return s;
}
