#include "query.h"
#include "ui_query.h"
#include"addthings.h"
#include"edit.h"
#include<QTextStream>
#include<QDebug>
#include<QMessageBox>
#include<QStringList>
#include"count.h"
query::query(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::query)
{
    ui->setupUi(this);
    this->model=new QStandardItemModel;
    //设置表头
    setmode();


}

query::~query()
{
    delete ui;
}

void query::on_pushButton_2_clicked()
{
    addthings a;
    a.exec();
}

void query::on_pushButton_5_clicked()
{
    this->close();
}
void query::display(int row,QStringList subs){
   int i=0;
   for(i=0;i<subs.length();i++){
       this->model->setItem(row,i,new QStandardItem(subs.at(i)));
   }
}


void query::on_pushButton_clicked()
{
    readFile();
    model->clear();
    int index=this->ui->querychoose->currentIndex();//0；无 ，1：按商品类别，2：按照商品名称 3.按照生产厂家
    QString cnt=this->ui->methodtext->text();
    setmode();
    doquery(index,cnt);
}

int query::readFile(){
    QFile file4("stu.txt");//总计
    stu_list.clear();
    if(!file4.open(QIODevice::ReadOnly | QIODevice::Text)){
        return  -1;
    }
    QTextStream in(&file4);
    while(!in.atEnd()){
        QString line=in.readLine();
        stu_list.append(line);
    }
    file4.close();
    return 0;
}
void query::doquery(int index,QString cnt){
    int i=0;
    int row=0;
    int flag=0;
    for(i=0;i<stu_list.length();i++){
        if(stu_list.at(i).isEmpty()){
            qDebug()<<"空了一行 ";
            continue;
        }
        QString line=stu_list.at(i);
        QStringList subs=line.split(" ");

        switch(index){
        case 0:
        case 1:if(cnt==subs.at(5)||cnt==" "){
                qDebug()<<line;
                display(row++,subs);
                flag=1;
            }
            break;
        case 2:if(cnt==subs.at(0)){
                qDebug()<<line;
                display(row++,subs);
                flag=1;

            }break;
        case 3:if(cnt==subs.at(3)){
                qDebug()<<line;
                display(row++,subs);
                flag=1;
            }break;
        }
    }
    if(!flag){
        QMessageBox::critical(this,"严重错误","未找到该记录 ");
    }
}

void query::on_tableView_clicked(const QModelIndex &index)
{
    QString row=this->ui->tableView->currentIndex().data().toString();
    int colo=this->ui->tableView->currentIndex().column();
    qDebug()<<row;
    int i;
    int flag=0;
    int numberi;

    for(i=0;i<stu_list.length();i++){
        QString line=stu_list.at(i);
        QStringList subs=line.split(" ");
            if(row==subs.at(colo)){
                numberi=i;
                flag=1;   
        }

    }
    QFile file1("new.txt");
        if(!file1.open(QIODevice::Truncate|QIODevice::WriteOnly)){
            QMessageBox::critical(this,"错误 ","文件打开失败","确定");
            return;
        }
        QTextStream out(&file1);
        out<<numberi;
        file1.close();
        qDebug()<<"flag"<<flag;
    qDebug()<<numberi;
}


void query::on_pushButton_4_clicked()
{
     edit e;
     model->clear();
     setmode();
     e.exec();

}

void query::on_pushButton_3_clicked()
{
    model->clear();
    setmode();
    int l;
    QFile file4("new.txt");//总计
    if(!file4.open(QIODevice::ReadOnly | QIODevice::Text)){
    }
    QTextStream in(&file4);
    while(!in.atEnd()){
        l=in.readLine().toInt();
         qDebug()<<" number"<<l;
    }
    file4.close();
    QString line1=stu_list.at(l);
    QStringList subs1=line1.split(" ");
    QString name=subs1.at(0);
    QString price=subs1.at(1);
    QString brand=subs1.at(2);
    QString inventory=subs1.at(3);
    QString manufacter=subs1.at(4);
    QString class1=subs1.at(5);
    QMessageBox msgBox;
     msgBox.setText(" 确认删除 ");
     msgBox.setInformativeText(name+'\n'+price+'\n'+brand+'\n'+inventory+'\n'+manufacter+'\n'+class1+'\n');
     msgBox.addButton("确定",QMessageBox::AcceptRole);
     msgBox.addButton("取消",QMessageBox::RejectRole);
      stu_list[l].clear();
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
void query::setmode(){
    this->model->setHorizontalHeaderItem(0,new QStandardItem("name"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("price"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("brand"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("inventory"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("manufacter"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("class"));
    this->ui->tableView->setModel(model);
}
