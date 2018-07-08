#ifndef MANAGER2_H
#define MANAGER2_H

#include <QDialog>

namespace Ui {
class manager2;
}

class manager2 : public QDialog
{
    Q_OBJECT

public:
    explicit manager2(QWidget *parent = nullptr);
    ~manager2();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::manager2 *ui;
    QList<QString>stu;
};

#endif // MANAGER2_H
