#ifndef MANAGER1_H
#define MANAGER1_H

#include <QDialog>

namespace Ui {
class manager1;
}

class manager1 : public QDialog
{
    Q_OBJECT

public:
    explicit manager1(QWidget *parent = nullptr);
    ~manager1();
    void clearnumber();

private slots:
    void on_stn_cancle_clicked();

    void on_stn_ok_clicked();

private:
    Ui::manager1 *ui;
};

#endif // MANAGER1_H
