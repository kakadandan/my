#include "manager1.h"
#include "ui_manager1.h"
#include"query.h"
#include"manager2.h"
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
manager1::manager1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manager1)
{
    ui->setupUi(this);
}

manager1::~manager1()
{
    delete ui;
}

void manager1::on_stn_cancle_clicked()
{
    this->close();
}


void manager1::on_stn_ok_clicked()
{
    QString name=this->ui->name->text();
    QString code=this->ui->code->text();
    if(name=="name"&&code=="code"){
        manager2 m;
        m.exec();
        clearnumber();
    }
    else{
       QMessageBox::critical(this,"错误.","用户名或错误，请重新输入","确定");
       clearnumber();
    }
}
void manager1::clearnumber(){
    this->ui->code->clear();
    this->ui->name->clear();
}
