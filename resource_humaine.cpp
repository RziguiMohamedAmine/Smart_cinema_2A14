#include "resource_humaine.h"
#include "ui_resource_humaine.h"
#include "employe1.h"
#include "departement1.h"
#include <qmessagebox.h>
#include <QDebug>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include<QPropertyAnimation>


resource_humaine::resource_humaine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::resource_humaine)
{
    ui->setupUi(this);
    ui->tableView_3->setModel(tmpempl.afficher());
    ui->tableView_2->setModel(tmpdep.afficher());
    animation=new QPropertyAnimation(ui->label_17,"geometry");
    animation->setDuration(3000);
    animation->setStartValue(ui->label_22->geometry());
     animation->setEndValue((QRect(750,150,200,200)));
     animation->start();


}

resource_humaine::~resource_humaine()
{
    delete ui;
}





void resource_humaine::on_pushButton_clicked()
{

    QString NOM=ui->lineEdit_nom->text();
    int SALAIRE =ui->lineEdit_salaire->text().toInt();
    QString PRENOM =ui->lineEdit_prenom->text();
    int TELEPHONE =ui->lineEdit_tel->text().toInt();
     int ID=ui->lineEdit_id->text().toInt();
    QString FORMATION =ui->lineEdit__formation->text();
    int AGE=ui->lineEdit_modage->text().toInt();

    employe1 e (NOM,SALAIRE,PRENOM,TELEPHONE,ID,FORMATION,AGE);

if(ID < 999999 && SALAIRE > 0 && AGE < 60 ){
    bool test=e.ajouter();
    if(test){
       ui->tableView_3->setModel(tmpempl.afficher());
        qDebug() <<"Client ajouté";
        QMessageBox::information(nullptr, QObject::tr("Ajouter employe"),
                    QObject::tr("employe ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }else{
       qDebug() <<"Erreur d'ajout employe";
       QMessageBox::critical(nullptr, QObject::tr("Ajouter employe"),
                   QObject::tr("Erreur 2 !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}
    }else {
    QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                QObject::tr("Controle de Saisie!.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


}


void resource_humaine::on_pushButton_8_clicked()
{
    int ID=ui->lineEdit_suppid->text().toInt();
    bool test=etmp.supprimer(ID);

    if(test){
        ui->tableView_3->setModel(tmpempl.afficher());
       QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("suppression effectuée.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
   else{
       QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                   QObject::tr("suppression non effectuée.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


}
}









void resource_humaine::on_pushButton_6_clicked()
{

    QString TYPE=ui->lineEdit_ajoutype->text();
    int NB_EMPLOYE =ui->lineEdit_ajounbem->text().toInt();
    departement1 d (TYPE,NB_EMPLOYE);
    if( NB_EMPLOYE < 10 ){

    bool test=d.ajouter();
     if(test){
        ui->tableView_2->setModel(tmpdep.afficher());
         QMessageBox:: information(nullptr, QObject::tr("ajouter un departement"),
                     QObject::tr("departement ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }
     else

         QMessageBox:: critical(nullptr, QObject::tr("ajouter un departement"),
                     QObject::tr("departement non ajouté.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
    } else {
         QMessageBox::critical(nullptr, QObject::tr("Erreur !"),
                     QObject::tr("Controle de Saisie!.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }


}


void resource_humaine::on_pushButton_5_clicked()
{

    int NB_EMPLOYE=ui->lineEdit_supnb->text().toInt();
    bool test=dtmp.supprimer(NB_EMPLOYE);

    if(test){
         ui->tableView_2->setModel(tmpdep.afficher());
       QMessageBox::information(nullptr, QObject::tr("OK"),
                   QObject::tr("suppression effectuée.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
   else{
       QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                   QObject::tr("suppression non effectuée.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


}
}

void resource_humaine::on_pushButton_4_clicked()
{

    int NB_EMPLOYE=ui->lineEdit_modnb->text().toInt();
    QString TYPE=ui->lineEdit_modtype->text();

     departement1 de (TYPE,NB_EMPLOYE);


     bool test=de.modifier(TYPE);
     if(test){
        ui->tableView_2->setModel(tmpdep.afficher());
         QMessageBox:: information(nullptr, QObject::tr("modifier un departement"),
                     QObject::tr("departement modifier.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

   }

     else

         QMessageBox:: critical(nullptr, QObject::tr("modifier un departement"),
                     QObject::tr("departement non modifier.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}


void resource_humaine::on_pushButton_12_clicked()
{
    ui->tableView_3->setModel(tmpempl.afficherTriId());
}

void resource_humaine::on_pushButton_13_clicked()
{
     ui->tableView_3->setModel(tmpempl.afficherTriSALAIRE());
}

void resource_humaine::on_pushButton_14_clicked()
{
     ui->tableView_3->setModel(tmpempl.afficherTriAGE());
}

void resource_humaine::on_pushButton_15_clicked()
{
    int ID = ui->id->text().toInt();
    ui->tableView_3->setModel(tmpempl.afficherRechId(ID));
}

void resource_humaine::on_pushButton_7_clicked()
{
    int SALAIRE=ui->lineEdit_modsalaire->text().toInt();
    int TELEPHONE=ui->lineEdit_modtel_3->text().toInt();
    int ID=ui->lineEdit_modid_3->text().toInt();
    int AGE=ui->lineEdit_modage->text().toInt();
    QString NOM =ui->lineEdit_modnom_3->text();
    QString PRENOM =ui->lineEdit_prenom_2->text();
    QString FORMATION =ui->lineEdit__modformation_2->text();

    employe1 b (NOM,SALAIRE,PRENOM,TELEPHONE,ID,FORMATION,AGE);

    bool test = tmpempl.modifier(b);
    if(test){
        ui->tableView_3->setModel(tmpempl.afficher());
    }
}

void resource_humaine::on_pushButton_17_clicked()
{
    QPrinter printer;
                QPrintDialog *printDialog = new QPrintDialog(&printer, this);
                printDialog->setWindowTitle("Imprimer Document");
                printDialog->exec();
}
