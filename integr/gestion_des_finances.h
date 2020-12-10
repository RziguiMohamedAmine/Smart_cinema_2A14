#ifndef GESTION_DES_FINANCES_H
#define GESTION_DES_FINANCES_H

#include <QDialog>
#include "transaction.h"
#include "categorie.h"
#include "popupmodif.h"
namespace Ui {
class gestion_des_finances;
}

class gestion_des_finances : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_des_finances(QWidget *parent = nullptr);
    ~gestion_des_finances();


private slots:
    void on_pushButton_ajouter_clicked();
    void on_bt_supprimer_clicked();
    void on_bt_modifier_clicked();



    void on_checkBox_stateChanged(int arg1);

    void on_ajouter_categorie_clicked();

    void on_supprimer_cat_clicked();

    void on_modifier_cat_clicked();

    void on_revenus_net_clicked();

    void on_pushButton_2_clicked();

    void on_Tri_clicked();

    void on_volume_par_cat_clicked();

private:
    Ui::gestion_des_finances *ui;
    popupmodif *dialog;
    Transaction trtmp;
    Categorie cattmp;
};

#endif // GESTION_DES_FINANCES_H
