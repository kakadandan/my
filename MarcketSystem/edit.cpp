#include "edit.h"
#include "ui_edit.h"
#include"QMessageBox"
edit::edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
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
    QString line=stu_list.at(l);
    qDebug()<<line;
    QStringList subs=line.split(" ");
    qDebug()<<subs.length();
    this->ui->name->setText(subs.at(0));
    this->ui->price->setText(subs.at(1));
    this->ui->brand->setText(subs.at(2));
    this->ui->inventory->setText(subs.at(3));
    this->ui->manufactor->setText(subs.at(4));
    this->ui->comboBox->setCurrentText(subs.at(5));
}

edit::~edit()
{
    delete ui;
}

void edit::on_pushButton_clicked()
{
    QString name=this->ui->name->text();
    QString price=this->ui->price->text();
    QString brand=this->ui->brand->text();
    QString inventory=this->ui->inventory->text();
    QString manufacter=this->ui->manufactor->text();
    QString class1=this->ui->comboBox->currentText();
    QMessageBox msgBox;
     msgBox.setText(" 请确认信息 ");
     msgBox.setInformativeText(name+'\n'+price+'\n'+brand+'\n'+inventory+'\n'+manufacter+'\n'+class1+'\n');
     msgBox.addButton("确定",QMessageBox::AcceptRole);
     msgBox.addButton("取消",QMessageBox::RejectRole);
    QString cnt=name+" "+price+" "+brand+" "+inventory+" "+manufacter+" "+class1;
    stu_list[l]=cnt;
    int ret = msgBox.exec();
    switch (ret) {
       case QMessageBox::AcceptRole:{
        QFile file3("stu.txt");
        file3.open(QIODevice::Truncate|QIODevice::WriteOnly);
        file3.close();
                if(!file3.open(QIODevice::Append | QIODevice::Text)){
                    QMessageBox::critical(this,"错误 ","文件打开失败 ","确定");
                    return;
                }
                QTextStream out(&file3);
                for(int i=0;i<stu_list.length();i++){
                    out<<stu_list.at(i)+'\n';
                }
                file3.close();

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
