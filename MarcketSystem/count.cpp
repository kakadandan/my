#include "count.h"
#include "ui_count.h"
#include"addthings.h"
#include"edit.h"
#include<QTextStream>
#include<QDebug>
#include<QMessageBox>
#include<QStringList>
count::count(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::count)
{
    ui->setupUi(this);
    this->model=new QStandardItemModel;
    //设置表头
   setmode();
}

count::~count()
{
    delete ui;
}

void count::on_pushButton_clicked()
{
    model->clear();
    readFile();
    setmode();
    int index=this->ui->comboBox->currentIndex();//0；无 ，1：按价格类别，2：按照库存量名称 3.按照生产厂家
    QString cnt=this->ui->lineEdit->text();
    int number=doquery(index,cnt);
    qDebug()<<"测试下number"<<number;
     QMessageBox msgBox;
     msgBox.setText(" 找到相关信息");
     msgBox.setText((QString)number);
     msgBox.setText("条 ");
     msgBox.addButton("确定 ",QMessageBox::AcceptRole);
     msgBox.addButton("取消 ",QMessageBox::RejectRole);
}

int count::readFile(){
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

int count::doquery(int index,QString cnt){
    int i=0;
    int row=0;
    int flag=0;
    int number=0;
    for(i=0;i<stu_list.length();i++){
        QString line=stu_list.at(i);
        QStringList subs=line.split(" ");
        if(stu_list.at(i).isEmpty()){
            qDebug()<<"空了一行 ";
            continue;
        }
        switch(index){
        case 0:
        case 1:if(cnt==subs.at(1)||cnt==" "){
                qDebug()<<line;
                display(row++,subs);
                number++;
                flag=1;
            }
            break;
        case 2:if(cnt==subs.at(3)){
                qDebug()<<line;
                display(row++,subs);
                number++;
                flag=1;

            }break;
        case 3:if(cnt==subs.at(4)){
                qDebug()<<line;
                display(row++,subs);
                number++;
                flag=1;
            }break;
        }
    }
    return number;
    if(!flag){
        QMessageBox::critical(this,"严重错误","未找到该记录 ");
    }
}
void count::display(int row,QStringList subs){
   int i=0;
   for(i=0;i<subs.length();i++){
       this->model->setItem(row,i,new QStandardItem(subs.at(i)));
   }
}
void count::setmode(){

    //设置表头
    this->model->setHorizontalHeaderItem(0,new QStandardItem("name"));
    this->model->setHorizontalHeaderItem(1,new QStandardItem("price"));
    this->model->setHorizontalHeaderItem(2,new QStandardItem("brand"));
    this->model->setHorizontalHeaderItem(3,new QStandardItem("inventory"));
    this->model->setHorizontalHeaderItem(4,new QStandardItem("manufacter"));
    this->model->setHorizontalHeaderItem(5,new QStandardItem("class"));
    this->ui->tableView->setModel(model);
}
