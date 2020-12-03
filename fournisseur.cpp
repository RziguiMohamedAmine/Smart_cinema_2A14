#include "fournisseur.h"

fournisseur::fournisseur(QString nom,QString prenom,QString code,int numero,QString email)
{
    this->nom=nom;
    this->prenom=prenom;
    this->code=code;
    this->numero=numero;
    this->email=email;



}
bool fournisseur::ajouter_fournisseur()
{
    QSqlQuery query;
    QString res =QString::number(numero);


    query.prepare("insert into fournisseurs(nom,prenom,code,numero,email)" "values ( :nom, :prenom, :code,:numero, :email)");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

      query.bindValue(":code",code);
    query.bindValue(":numero",res);
    query.bindValue(":email",email);

     return query.exec();
}


QSqlQueryModel * fournisseur::loadData_fournisseur()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select code from fournisseurs");
    query.exec();
    model->setQuery(query);
    return model;
}
QSqlQueryModel * fournisseur::afficher_fournisseur(QString info)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from fournisseurs where code='"+info+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
           model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
           model->setHeaderData(2,Qt::Horizontal,QObject::tr("code"));
           model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero"));
           model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));

    return model;
}


bool fournisseur::supprimer_fournisseur(QString info)
{

    QSqlQuery query;
    query.prepare("Delete from fournisseurs where code='"+info+"'");
    return query.exec();
}
bool fournisseur::Update_f()
{
    QSqlQuery query;

    QString snumero=QString::number(numero);


    query.prepare("update fournisseurs set code='"+code+"',nom='"+nom+"',prenom='"+prenom+"',numero='"+snumero+"',email='"+email+"' where nom='"+nom+"'");
    query.bindValue(":code",code);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":numero",snumero);
        query.bindValue(":email",email);

        //exec() envoie la requete pour l'executer
          return query.exec();
      }

QSqlQuery fournisseur::affiche_edit_f(QString info)
{
   QSqlQuery query;
       query.prepare("select * from fournisseurs where code='"+info+"'");
query.exec();
return query;
}
