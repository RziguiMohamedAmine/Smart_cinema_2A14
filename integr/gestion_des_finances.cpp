#include "gestion_des_finances.h"
#include "ui_gestion_des_finances.h"
#include "transaction.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QDialog>
#include <QCheckBox>
#include "popupmodif.h"
#include "ui_popupmodif.h"

gestion_des_finances::gestion_des_finances(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_des_finances)
{
    ui->setupUi(this);
}

gestion_des_finances::~gestion_des_finances()
{
    delete ui;
}


void gestion_des_finances::on_pushButton_ajouter_clicked()
{
    int etat=0;
    QString id=ui->lineEdit_id->text();
    QString objet=ui->lineEdit_objet->text();
    float somme=ui->lineEdit_somme->text().toFloat()*1000;
    if(ui->checkBox->isChecked()){etat=1;};
    Transaction T(id,objet,somme,etat);
    bool test=T.ajouter();

    if(test)
    {
        ui->tableView->setModel(trtmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effcetué.\n""Click Cancel to exit."),QMessageBox::Cancel);

}



void gestion_des_finances::on_bt_supprimer_clicked()
{
        QMessageBox::StandardButton reply;
        reply= QMessageBox::question(this, "Suppression", "êtes-vous sûr?",QMessageBox::Yes|QMessageBox::No);
        if(reply==QMessageBox::Yes)
                 {
                    if(trtmp.supprimer(ui))
                      {
                          QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectuée\n""Click Cancel to exit."),QMessageBox::Cancel);
                          ui->tableView->setModel(trtmp.afficher());

                      }
                      else{
                          QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Erreur lors de la suppression.\n""Click Cancel to exit."),QMessageBox::Cancel);
                      }
                }
        else{QMessageBox::information(nullptr,QObject::tr("Annulation"),QObject::tr("Suppression Annulée.\n""Click Cancel to exit."),QMessageBox::Cancel);}
}


void gestion_des_finances::on_bt_modifier_clicked()
{
   popupmodif m;
   m.setModal(true);
   m.exec();
   //QString nobjet=m.nobjet;
   //float nsomme=m.nsomme;
   if(trtmp.modifier(ui,m.xi))
     {
         QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée\n""Click Cancel to exit."),QMessageBox::Cancel);
         ui->tableView->setModel(trtmp.afficher());

     }
     else{
         QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Erreur lors de la modification.,\n""Click Cancel to exit."),QMessageBox::Cancel);
     }

   //popupmodif = new dialog(this)
   //popupmodif->show();
   //'"+nsomme+"'/'"+nobjet+"'
}



void gestion_des_finances::on_ajouter_categorie_clicked()
{
    QString id=ui->lineEdit_idcat->text();
    QString nom=ui->lineEdit_nom_cat->text();
    int type=ui->lineEdit_typecat->text().toInt();
    Categorie C(id,nom,type);
    bool test=C.ajouter();

    if(test)
    {
        ui->tableView_2->setModel(cattmp.afficher());
        QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Ajout non effcetué.\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void gestion_des_finances::on_checkBox_stateChanged(int arg1)
{

}

void gestion_des_finances::on_supprimer_cat_clicked()
{
    QMessageBox::StandardButton reply;
    reply= QMessageBox::question(this, "Suppression", "êtes-vous sûr?",QMessageBox::Yes|QMessageBox::No);
    if(reply==QMessageBox::Yes)
             {
                if(cattmp.supprimer(ui))
                  {
                      QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Suppression effectuée\n""Click Cancel to exit."),QMessageBox::Cancel);
                      ui->tableView_2->setModel(cattmp.afficher());

                  }
                  else{
                      QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Erreur lors de la suppression.\n""Click Cancel to exit."),QMessageBox::Cancel);
                  }
            }
    else{QMessageBox::information(nullptr,QObject::tr("Annulation"),QObject::tr("Suppression Annulée.\n""Click Cancel to exit."),QMessageBox::Cancel);}
}

void gestion_des_finances::on_modifier_cat_clicked()
{
    if(cattmp.modifier(ui))
      {
          QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Modification effectuée\n""Click Cancel to exit."),QMessageBox::Cancel);
          ui->tableView_2->setModel(cattmp.afficher());

      }
      else{
          QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Erreur lors de la modification.,\n""Click Cancel to exit."),QMessageBox::Cancel);
      }
}

void gestion_des_finances::on_revenus_net_clicked()
{
    trtmp.revenus_net();
}

void gestion_des_finances::on_pushButton_2_clicked()
{
    trtmp.classer();
    ui->tableView->setModel(trtmp.classer());
}

void gestion_des_finances::on_Tri_clicked()
{
    cattmp.classer();
    ui->tableView_2->setModel(cattmp.classer());
}

void gestion_des_finances::on_volume_par_cat_clicked()
{
    //ui->tableView_2->setModel(cattmp.afficher());
    cattmp.volume_par_cat(ui);
}
