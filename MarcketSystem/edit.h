#ifndef EDIT_H
#define EDIT_H

#include <QDialog>
#include"query.h"
namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr);
    ~edit();
     Ui::edit *ui;
     QStringList subs;
     int l;
     QString m;
private slots:

     void on_pushButton_clicked();

private:
    QList<QString> stu_list;
};

#endif // EDIT_H
