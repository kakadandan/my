#ifndef CUTOM1_H
#define CUTOM1_H

#include <QDialog>
#include "food1.h"
#include"good1.h"
#include"cosmetic1.h"
#include"drink1.h"
namespace Ui {
class cutom1;
}

class cutom1 : public QDialog
{
    Q_OBJECT

public:
    explicit cutom1(QWidget *parent = nullptr);
    ~cutom1();
    food1 f;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::cutom1 *ui;
};

#endif // CUTOM1_H
