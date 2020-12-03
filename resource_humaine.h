#ifndef RESOURCE_HUMAINE_H
#define RESOURCE_HUMAINE_H
#include "employe1.h"
#include <QDialog>
#include "departement1.h"
#include<QPropertyAnimation>
namespace Ui {
class resource_humaine;
}

class resource_humaine : public QDialog
{
    Q_OBJECT

public:
    explicit resource_humaine(QWidget *parent = nullptr);
    ~resource_humaine();

private slots:
    void on_pushButton_clicked();

   // void on_pushButton_2_clicked();

    //void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();







    void on_pushButton_8_clicked();







    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

  //  void on_pushButton_16_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::resource_humaine *ui;
    employe1 tmpempl;
    employe1 etmp;
    employe1 em;
    departement1 tmpdep;
    departement1 dtmp;
    departement1 de;
    QPropertyAnimation* animation;

};

#endif // RESOURCE_HUMAINE_H
