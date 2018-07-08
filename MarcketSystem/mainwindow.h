#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionothers_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
