#include "cutom1.h"
#include "ui_cutom1.h"
cutom1::cutom1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cutom1)
{
    ui->setupUi(this);
}

cutom1::~cutom1()
{
    delete ui;
}

void cutom1::on_pushButton_clicked()
{
    f.exec();
}


void cutom1::on_pushButton_3_clicked()
{
    cosmetic1 g;
    g.exec();
}

void cutom1::on_pushButton_4_clicked()
{
    drink1 d;
    d.exec();
}

void cutom1::on_pushButton_2_clicked()
{
    good1 g;
    g.exec();
}
