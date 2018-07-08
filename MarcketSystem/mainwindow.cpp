#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"cutom1.h"
#include"manager1.h"
#include"addthings.h"
#include<QPixmap>
#include<QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton1_clicked()
{
    cutom1 c;
    c.exec();
}

void MainWindow::on_pushButton_2_clicked()
{
    manager1 m;
    m.exec();
}


void MainWindow::on_pushButton_3_clicked()
{
    this->close();
}

void MainWindow::on_actionothers_triggered()
{
    addthings s;
    s.exec();
}

