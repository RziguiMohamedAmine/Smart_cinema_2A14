#include "produit.h"
#include <QMediaPlayer>
produit::produit(QString code,QString nom,int quantite,float prix)
{
    this->code=code;
    this->nom=nom;
    this->quantite=quantite;
    this->prix=prix;


}
bool produit::ajouter()
{
    QSqlQuery query;
    QString res =QString::number(prix);
    QString nvq =QString::number(quantite);

    query.prepare("insert into produits(code,nom,quantite,prix)" "values ( :code, :nom, :quantite,:prix)");
    query.bindValue(":code",code);
    query.bindValue(":nom",nom);
    query.bindValue(":quantite",nvq);
    query.bindValue(":prix",res);
    return query.exec();

}
QSqlQueryModel * produit::loadData()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select code from produits");
    query.exec();
    model->setQuery(query);
    return model;
}
QSqlQueryModel * produit::afficher(QString info)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from produits where code='"+info+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
           model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
           model->setHeaderData(2,Qt::Horizontal,QObject::tr("quantite"));
           model->setHeaderData(3,Qt::Horizontal,QObject::tr("prix"));
    return model;
}


bool produit::supprimer(QString info)
{

    QSqlQuery query;
    query.prepare("Delete from produits where code='"+info+"'");
    return query.exec();
}
bool produit::Update()
{
    QSqlQuery query;

    QString squantite=QString::number(quantite);
    QString sprix=QString::number(prix);

    query.prepare("update produits set code='"+code+"',nom='"+nom+"',quantite='"+squantite+"',prix='"+sprix+"' where nom='"+nom+"'");
    query.bindValue(":code",code);
        query.bindValue(":nom",nom);
        query.bindValue(":quantite",squantite);
        query.bindValue(":prix",sprix);
        //exec() envoie la requete pour l'executer
          return query.exec();
      }


 QSqlQuery produit::affiche_edit(QString info)
{
    QSqlQuery query;
        query.prepare("select * from produits where code='"+info+"'");
query.exec();
return query;



}


 QSqlQueryModel * produit::search(QString info)
 {
     QSqlQueryModel *model=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("select code from produits where code='"+info+"'");
     query.exec();
     model->setQuery(query);
     return model;
 }
 QSqlQueryModel * produit :: sort()
 {
     QSqlQuery query ;
     QSqlQueryModel * model=new QSqlQueryModel();

     query.prepare("select * from produits order by PRIX desc");
     query.exec();

     model->setQuery(query);

     return model;
 }
