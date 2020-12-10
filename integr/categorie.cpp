#include "categorie.h"
#include <QInputDialog>
#include <QMessageBox>

Categorie::Categorie()
{
    id="";
    nom="";
    type=0;
}


Categorie::Categorie(QString id,QString nom,int type)
{
   this->id=id;
   this->nom=nom;
   this->type=type;

}

bool Categorie::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO categorie_tr(id,nom,type)VALUES(:id,:nom,:type)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    return query.exec();
}

QSqlQueryModel * Categorie::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model ->setQuery("select * from categorie");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("type"));
    return model;
}

bool Categorie::supprimer(Ui::gestion_des_finances *ui)
{
    QString ref=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),0)).toString();

    QSqlQuery query;
    query.prepare("select * FROM categorie_tr WHERE ID ='"+ref+"'");
    query.exec();
    int total=0;
    while(query.next()){
        total++;
    }
    if(total==1){
        QSqlQuery q;
        q.prepare("DELETE FROM categorie_tr WHERE ID ='"+ref+"'");
        return q.exec();
    }
    else{
        return false;
    }
}

bool Categorie::modifier(Ui::gestion_des_finances *ui)
{
    QString ref=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),0)).toString();
    QString id=ref;
    int ntype=QInputDialog::getInt(0, "Input dialog","Nouveau type:", QLineEdit::Normal);
    QString xtype=QString::number(ntype);
    QSqlQuery query;
    query.prepare("update categorie set id='"+id+"',type='"+xtype+"' where id='"+id+"'");
    return  query.exec();
}

QSqlQueryModel * Categorie::classer()
{
    QString x="";
    int i=0,l=0;
    QSqlQuery query;
    query.prepare("select nom from categorie_tr");
    query.exec();
    while(query.next()){
        x+=query.value(0).toString()+',';
    }
    l=x.length();
    x.remove(l-1,1);
    QMessageBox msgbox;
    msgbox.setText(x);
    msgbox.exec();
    QSqlQueryModel * model=new QSqlQueryModel();
    for (i=0;i<10;i++)
    {

    }
    //QString s=QInputDialog::getText(0, "Input dialog","Catégorie:", QLineEdit::Normal);
    model ->setQuery("select * from transaction order by objet,somme DESC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("objet"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("somme"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("etat"));
    return model;
}


void Categorie::volume_par_cat(Ui::gestion_des_finances *ui)
{
    QString x=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->selectionModel()->currentIndex().row(),2)).toString();
    QSqlQuery query;
    query.prepare("select somme from transaction where objet='"+x+"'");
    int v=0;
    query.exec();
    while(query.next()){
        v+=query.value(0).toInt();
    }
    QMessageBox msgbox;
    QString xv=QString::number(v);
    msgbox.setText("Volume de la Catégorie: "+xv);
    msgbox.exec();

}
