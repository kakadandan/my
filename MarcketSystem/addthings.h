#ifndef ADDTHINGS_H
#define ADDTHINGS_H
#include<time.h>
#include<QTime>
#include<QDateTime>
#include <QDialog>

namespace Ui {
class addthings;
}

class addthings : public QDialog
{
    Q_OBJECT

public:
    explicit addthings(QWidget *parent = nullptr);
    ~addthings();

private slots:
    void on_stn_yes_clicked();

    void on_stn_no_clicked();
    void clearUserTnterface();
    void writefileof(QString cnt);
    void writetime(QString cnt);
    QString settime();

private:
    Ui::addthings *ui;
};

#endif // ADDTHINGS_H
