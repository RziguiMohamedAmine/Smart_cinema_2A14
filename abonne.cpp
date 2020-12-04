 #include "abonne.h"
#include <QDebug>


abonne::abonne()
{
    code="";
    nom="";
    prenom="";
    email="";
    telephone=0;

}

abonne::abonne(QString b,QString c)
{
    this->email=b;
    this->texte_mail=c;
}


abonne::abonne(QString c,QString n,QString p,QString m,long t)
{
    this->code=c;
    this->nom=n;
    this->prenom=p;
    this->email=m;
    this->telephone=t;
}





void abonne::set_code(QString c)
{
    code=c;
}




void abonne::set_nom(QString n)
{
    nom=n;
}


void abonne::set_prenom(QString p)
{
    prenom=p;
}


void abonne::set_mail(QString m)
{
    email=m;
}


void abonne::set_telephone(long t)
{
    telephone=t;
}

void abonne::set_textemail(QString m)
{
    texte_mail=m;
}


QString abonne::get_code()
{
    return code;
}

QString abonne::get_nom()
{
    return nom;
}

QString abonne::get_prenom()
{
    return prenom;
}

QString abonne::get_mail()
{
    return email;
}

long abonne::get_telephone()
{
    return telephone;
}


QString abonne::get_textemail()
{
    return texte_mail;
}


bool abonne::ajouter()
{
    QSqlQuery query ;
    QString res = QString::number(telephone);
    query.prepare("insert into abonne (code,nom,prenom,telephone,mail)""values(:code,:nom,:prenom,:telephone,:mail)") ;

    query.bindValue(":telephone",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",email);
    query.bindValue(":code",code);

    return query.exec();

}


bool abonne::modifier()
{
    QSqlQuery query;
    QString res = QString::number(telephone);
    query.prepare("UPDATE abonne set code = :code,nom = :nom,prenom = :prenom,telephone = :telephone,mail = :mail where code= :code");

    query.bindValue(":code",code);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":telephone",res);
    query.bindValue(":mail",email);


    return query.exec();
}




QSqlQueryModel * abonne::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from abonne"); 
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("mail"));

    return model;
}



bool abonne::supprimer(QString sel)
{
    QSqlQuery query;

    query.prepare("delete from abonne where code = :code");
    query.bindValue(":code",sel);
    return query.exec();
}


bool abonne::envoyer_mail()
{
    QSqlQuery query ;
    query.prepare("UPDATE abonne set texte_mail = :texte_mail where mail =:mail ") ;
    query.bindValue(":mail",email);
    query.bindValue(":texte_mail",texte_mail);
    return query.exec();

}






