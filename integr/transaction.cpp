#include "transaction.h"
#include <QMessageBox>

Transaction::Transaction()
{
    id="";
    objet="";
    somme=0;
    etat=0;
}


Transaction::Transaction(QString id, QString objet, float somme,int etat)
{
   this->id=id;
   this->objet=objet;
   this->somme=somme;
   this->etat=etat;
}

bool Transaction::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO transaction(id,objet,somme,etat)VALUES(:id,:objet,:somme,:etat)");
    query.bindValue(":id",id);
    query.bindValue(":objet",objet);
    query.bindValue(":somme",somme);
    query.bindValue(":etat",etat);

    return query.exec();
}

QSqlQueryModel * Transaction::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model ->setQuery("select * from transaction");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("objet"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("somme"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));
    //setData(&model,model.,QObject::tr("somme"));
    return model;
}


bool Transaction::supprimer(Ui::gestion_des_finances *ui)
{
    QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();

    QSqlQuery query;
    query.prepare("select * FROM transaction WHERE ID ='"+ref+"'");
    query.exec();
    int total=0;
    while(query.next()){
        total++;
    }
    if(total==1){
        QSqlQuery q;
        q.prepare("DELETE FROM transaction WHERE ID ='"+ref+"'");
        return q.exec();
    }
    else{
        return false;
    }
}

bool Transaction::modifier(Ui::gestion_des_finances *ui,Ui::popupmodif *xi)
{

   QString ref=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString();
   QString id=ref;
   QString nobjet=xi->modifobjet->text();
   float nsomme=xi->modifsomme->text().toFloat()*1000;
   QString xsomme=QString::number(nsomme);
   //QMessageBox msgbox;
   //msgbox.setText(id+'\n'+nobjet+'\n'+xnsomme);
   //msgbox.exec();
   QSqlQuery query;
   query.prepare("update transaction set id='"+id+"',objet='"+nobjet+"',somme='"+xsomme+"' where id='"+ref+"'");

   return  query.exec();
}

void Transaction::revenus_net()
{
    int depenses_tot=0,revenus_tot=0,revenus_net=0;
    //Revenus
    QSqlQuery query;
    query.prepare("select somme from transaction where etat=1");
    query.exec();
    while(query.next()){
        revenus_tot+=query.value(0).toInt();
    }
    query.prepare("select somme from transaction where etat=0");
    query.exec();
    while(query.next()){
        depenses_tot+=query.value(0).toInt();
    }
    revenus_net=revenus_tot-depenses_tot;
    QMessageBox msgbox;
    QString xrevenus_net=QString::number(revenus_net);
    msgbox.setText("Revenus Net: "+xrevenus_net);
    msgbox.exec();
    //Dépenses
}

QSqlQueryModel * Transaction::classer()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model ->setQuery("select * from transaction order by etat,somme DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("objet"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("somme"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));
    return model;
}


