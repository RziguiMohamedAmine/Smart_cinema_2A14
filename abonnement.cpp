#include "abonnement.h"
#include <QDebug>


abonnement::abonnement()
{
    idab="";
    tarif=0;
    date_deb="";
    date_fin="";
    type_ab="";

}


abonnement::abonnement(QString n,int tr,QString dd,QString df,QString ty)
{
    this->idab=n;
    this->tarif=tr;
    this->date_deb=dd;
    this->date_fin=df;
    this->type_ab=ty;
}



void abonnement::set_id(QString n)
{
    idab=n;
}


void abonnement::set_tarif(int p)
{
    tarif=p;
}

void abonnement::set_date_debut(QString c)
{
    date_deb=c;
}

void abonnement::set_date_fin(QString m)
{
    date_fin=m;
}

void abonnement::set_type(QString t)
{
    type_ab=t;
}


QString abonnement::get_id()
{
    return idab;
}
int abonnement::get_tarif()
{
    return tarif;
}
QString abonnement::get_date_deb()
{
    return date_deb;
}
QString abonnement::get_date_fin()
{
    return date_fin;
}
QString abonnement::get_type()
{
    return type_ab;
}



bool abonnement::ajouter_ab()
{
    QSqlQuery qry ;
    QString res2= QString::number(tarif);
    qry.prepare("insert into abonnement (idab,tarif,date_debut,date_fin,type_ab)""values(:idab,:tarif,:date_debut,:date_fin,:type_ab)") ;

    qry.bindValue(":idab",idab);
    qry.bindValue(":tarif",res2);
    qry.bindValue(":date_debut",date_deb);
    qry.bindValue(":date_fin",date_fin);
    qry.bindValue(":type_ab",type_ab);

    return qry.exec();
}


bool abonnement::modifier_ab()
{
    QSqlQuery qry;
    QString res = QString::number(tarif);
    qry.prepare("UPDATE abonnement set idab = :idd,tarif = :tarif,date_debut = :date_debut,date_fin = :date_fin,type_ab = :type where idab= :idd");

    qry.bindValue(":idd",idab);
    qry.bindValue(":tarif",res);
    qry.bindValue(":date_debut",date_deb);
    qry.bindValue(":date_fin",date_fin);
    qry.bindValue(":type",type_ab);

    return qry.exec();
}










QSqlQueryModel * abonnement::afficher_ab()
{

    QSqlQueryModel * model2=new QSqlQueryModel();

    model2->setQuery("select * from abonnement");

    model2->setHeaderData(0,Qt::Horizontal,QObject::tr("idab"));
    model2->setHeaderData(1,Qt::Horizontal,QObject::tr("tarif"));
    model2->setHeaderData(2,Qt::Horizontal,QObject::tr("date_debut"));
    model2->setHeaderData(3,Qt::Horizontal,QObject::tr("date_fin"));
    model2->setHeaderData(4,Qt::Horizontal,QObject::tr("type_ab"));

    return model2;
}




bool abonnement::supprimer_ab(QString selec)
{
    QSqlQuery qry;
   // QString res = QString::number(selec);
    qry.prepare("delete from abonnement where idab = :idd");
    qry.bindValue(":idd",selec);
    return qry.exec();
}




