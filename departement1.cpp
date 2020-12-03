#include "departement1.h"

departement1::departement1()
{
    TYPE="";
    NB_EMPLOYE=0;


}


departement1::departement1 (QString type,int nb_employe)
{
    this->TYPE=type;
    this->NB_EMPLOYE=nb_employe;

}


QString departement1:: get_TYPE() {return TYPE;}
int departement1::get_NB_EMPLOYE() {return NB_EMPLOYE;}


bool departement1::ajouter()
{

    QSqlQuery query;

    QString am= QString::number(NB_EMPLOYE);
      query.prepare("INSERT INTO DEPARTEMENT (TYPE,NB_EMPLOYE)"
                       "VALUES (:TYPE,:NB_EMPLOYE)");
       query.bindValue(":TYPE",TYPE);
       query.bindValue(":NB_EMPLOYE",am);

       return query.exec();

  }

QSqlQueryModel * departement1::afficher()
{

       QSqlQueryModel * model=new QSqlQueryModel();

       model->setQuery("select *from DEPARTEMENT");
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("TYPE"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("NB_EMPLOYE"));
       return model;

}



bool departement1::supprimer(int nombre_employe)
{
    QSqlQuery query;
    QString res=QString::number(nombre_employe);
    query.prepare("delete from DEPARTEMENT where NB_EMPLOYE=:NB_EMPLOYE");
    query.bindValue(":NB_EMPLOYE",res);
    return query.exec();

}

 bool  departement1::modifier(QString){


         QSqlQuery query;
         QString res= QString::number(NB_EMPLOYE);
         query.prepare("Update DEPARTEMENT set TYPE=:TYPE,NB_EMPLOYE=:NB_EMPLOYE where TYPE=:TYPE");
        query.bindValue(":TYPE",TYPE);
        query.bindValue(":NB_EMPLOYE",res);


         return query.exec();

     }
