#include "ressource_humaine.h"
#include "ui_ressource_humaine.h"
#include "employe.h"
#include "departement.h"
#include <QMessageBox>
//#include <QDebug>
ressource_humaine::ressource_humaine(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ressource_humaine)
{
    ui->setupUi(this);
    //ui->tab_employe->setModel(tmpemploye.afficher());
}

ressource_humaine::~ressource_humaine()
{
    delete ui;
}

void ressource_humaine::on_pushButton_clicked()
{
    int id=ui->lineEdit->text().toUInt();
    QString nom=ui->lineEdit_2->text();
    QString prenom=ui->lineEdit_3->text();
    int salaire= ui->lineEdit_4->text().toUInt();
    QString formation=ui->lineEdit_5->text();
    int telephone= ui->lineEdit_6->text().toUInt();
    employe e (nom,prenom,formation,id,salaire,telephone);

    bool test=e.ajouter();

    if(test)
    {
         //ui->tab_employe->setModel(tmpemploye.afficher());
          //refresh

     QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("suppression effectuée\n" "click cancel to exit."),QMessageBox::Cancel);
        //fenetre
    }

        else{

        QMessageBox::information(nullptr, QObject::tr("not ok"),QObject::tr("suppression non effectuée\n" "click cancel to exit."),QMessageBox::Cancel);

}
     }



/*void ressource_humaine::on_pushButton_2_clicked()
{

}*/
