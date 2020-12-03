#include "employe1.h"

employe1::employe1()
{
    NOM="";
    SALAIRE=0;
    PRENOM="";
    TELEPHONE=0;
    ID=0;
   FORMATION="";
   AGE=0;
}



employe1:: employe1 (QString nom,int salaire,QString prenom,int telephone,int id,QString formation,int age)
{
    this->NOM=nom;
    this->SALAIRE=salaire;
    this->PRENOM=prenom;
    this->TELEPHONE=telephone;
    this->ID=id;
    this->FORMATION=formation;
   this->AGE=age;

}

 QString employe1:: get_NOM() {return NOM;}
 int employe1::get_SALAIRE() {return SALAIRE;}
 QString employe1:: get_PRENOM() {return PRENOM;}
 int employe1:: get_TELEPHONE() {return TELEPHONE;}
 int employe1:: get_ID() {return ID;}
 QString employe1:: get_FORMATION() {return FORMATION;}
 int employe1:: get_AGE() {return AGE;}


bool employe1::ajouter()
{
    QSqlQuery query;

    QString am= QString::number(SALAIRE);
    QString ami= QString::number(TELEPHONE);
    QString amin= QString::number(ID);
    QString am1= QString::number(AGE);
       query.prepare("INSERT INTO EMPLOYE (NOM,SALAIRE,PRENOM,TELEPHONE,ID,FORMATION,AGE)"
                       "VALUES (:NOM,:SALAIRE,:PRENOM,:TELEPHONE,:ID,:FORMATION,:AGE)");
       query.bindValue(":NOM",NOM);
       query.bindValue(":SALAIRE",am);
       query.bindValue(":PRENOM",PRENOM);
        query.bindValue(":TELEPHONE",ami);
        query.bindValue(":ID",amin);
        query.bindValue(":FORMATION",FORMATION);
        query.bindValue(":AGE",am1);




       return query.exec();

}

   QSqlQueryModel * employe1::afficher()
 {
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select *from EMPLOYE");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("SALAIRE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("TELEPHONE"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("FORMATION"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("AGE"));


    return model;
   }



    bool employe1::supprimer(int identifiant)
    {
        QSqlQuery query;
        QString res=QString::number(identifiant);
        query.prepare("delete from EMPLOYE where ID=:ID");
        query.bindValue(":ID",res);
        return query.exec();

    }

    bool employe1 :: modifier (employe1 b)
    {
        QSqlQuery query;
        QString SALAIRE = QString :: number(b.get_SALAIRE());
        QString ID = QString :: number(b.get_ID());
        QString TELEPHONE = QString :: number(b.get_TELEPHONE());
        QString AGE = QString :: number(b.get_AGE());
        query.prepare("UPDATE EMPLOYE SET NOM=:NOM,SALAIRE=:SALAIRE,PRENOM=:PRENOM,TELEPHONE=:TELEPHONE,ID=:ID,FORMATION=:FORMATION,AGE=:AGE WHERE SALAIRE=:SALAIRE");
        query.bindValue(":nom",b.get_NOM());
        query.bindValue(":SALAIRE",b.get_SALAIRE());
        query.bindValue(":PRENOM",b.get_PRENOM());
        query.bindValue(":FORMATION",b.get_FORMATION());
        query.bindValue(":TELEPHONE",b.get_TELEPHONE());
        query.bindValue(":ID",b.get_ID());
        query.bindValue(":AGE",b.get_AGE());


        return query.exec();

    }



    QSqlQueryModel * employe1::afficherTriId(){
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYE ORDER BY ID");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("SALAIRE"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("TELEPHONE"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("FORMATION"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("AGE"));

        return model;
    }
    QSqlQueryModel * employe1::afficherTriSALAIRE(){
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYE ORDER BY SALAIRE");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("SALAIRE"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("TELEPHONE"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("FORMATION"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("AGE"));

        return model;

    }
     QSqlQueryModel * employe1::afficherTriAGE(){
         QSqlQueryModel * model = new QSqlQueryModel();
         model->setQuery("SELECT * FROM EMPLOYE ORDER BY AGE");
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("SALAIRE"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("TELEPHONE"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("FORMATION"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("AGE"));

         return model;

     }


     QSqlQueryModel * employe1::afficherRechId(int ID){
         QSqlQueryModel * model = new QSqlQueryModel();
         QString identifiant = QString::number(ID);
         model->setQuery("SELECT * FROM EMPLOYE WHERE ID = " + identifiant);
         model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOM"));
         model->setHeaderData(1,Qt::Horizontal,QObject::tr("SALAIRE"));
         model->setHeaderData(2,Qt::Horizontal,QObject::tr("PRENOM"));
         model->setHeaderData(3,Qt::Horizontal,QObject::tr("TELEPHONE"));
         model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID"));
         model->setHeaderData(5,Qt::Horizontal,QObject::tr("FORMATION"));
         model->setHeaderData(6,Qt::Horizontal,QObject::tr("AGE"));

         return model;
     }
