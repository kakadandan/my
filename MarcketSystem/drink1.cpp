#include "drink1.h"
#include "ui_drink1.h"
#include<QTextStream>
#include<QDebug>
#include<QMessageBox>
#include<QStringList>
#include"drink2.h"
drink1::drink1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::drink1)
{
    ui->setupUi(this);
    this->model=new QStandardItemModel;
    setmode();
}

drink1::~drink1()
{
    delete ui;
}

void drink1::on_pushButton_clicked()
{
    readFile();
    model->clear();
    QString cnt=this->ui->search->text();
    setmode();
    doquery(cnt);
}

void drink1::on_pushButton_3_clicked()
{
    drink2 d;
    model->clear();
    setmode();
    d.exec();
}

void drink1::on_tableView_clicked(const QModelIndex &index)
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
    if(flag==0){
        qDebug()<<"错误,number ";
    }
    savefile(numberi);
}
void drink1::display(int row,QStringList subs){
   int i=0;
   for(i=0;i<subs.length();i++){
       this->model->setItem(row,i,new QStandardItem(subs.at(i)));
   }
}
int drink1::readFile(){
    QFile file4("stu.txt");//总计
    // name
     //price
     // brand
     // inventory
      //manufactor
      //class
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

void drink1::doquery(QString cnt){
    int i=0;
    int row=0;
    int flag=0;
    for(i=0;i<stu_list.length();i++){
        QString line=stu_list.at(i);
        QStringList subs=line.split(" ");
        if(cnt==subs.at(0)&&subs.at(5)=="drink")
        {
                qDebug()<<line;
                display(row++,subs);
                flag=1;
         }
        }
    if(!flag){
        QMessageBox::critical(this,"严重错误","未找到该记录 ");
    }
}
void drink1::setmode(){

    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("name"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("price"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("brand"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("inventory"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("manufacter"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("class"));
    this->ui->tableView->setModel(model);
}

void drink1::savefile(int number){
    QFile file1("new.txt");
        if(!file1.open(QIODevice::Truncate|QIODevice::WriteOnly)){
            QMessageBox::critical(this,"错误 ","文件打开失败","确定");
            return;
        }
        QTextStream out(&file1);
        out<<number;
        file1.close();
    qDebug()<<number;
}

void drink1::on_pushButton_2_clicked()
{
    readFile();
    model->clear();
    setmode();
    show();
}
void drink1::show(){
    int i=0;
    int j=0;
    for(i=0;i<stu_list.length();i++){
        if(stu_list.at(i).isEmpty()){
            qDebug()<<"空了一行2 ";
            continue;
        }
        QString line=stu_list.at(i);
        QStringList subs=line.split(" ");
        if(subs.at(5)=="drink"){
                qDebug()<<line;
                display(j++,subs);
         }
}
}
