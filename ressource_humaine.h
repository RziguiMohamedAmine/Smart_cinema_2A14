#ifndef RESSOURCE_HUMAINE_H
#define RESSOURCE_HUMAINE_H

#include <QDialog>
#include"employe.h"
#include "departement.h"
namespace Ui {
class ressource_humaine;
}

class ressource_humaine : public QDialog
{
    Q_OBJECT

public:
    explicit ressource_humaine(QWidget *parent = nullptr);
    ~ressource_humaine();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ressource_humaine *ui;
    employe tmpemploye;
};

#endif // RESSOURCE_HUMAINE_H
