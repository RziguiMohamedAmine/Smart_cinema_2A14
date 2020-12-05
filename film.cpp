#include "film.h"
#include <QSqlQuery>
#include <QMessageBox>

            film::film()
{
    nom="";
     director="";
    annee=0;
     ratio=0;

}

            film::film(QString nom,QString director,int annee,int ratio)
{

    this->nom=nom;
    this->director=director;
    this->annee=annee;
    this->ratio=ratio;
}


QString film::getNom(){return nom;}
QString film::getdirector(){return this->director;}
int film::getannee(){return annee;}
int film::getratio(){return ratio;}


void film::setNom(QString value){this->nom=value;}
void film::setdirector(QString value){this->director=value;}
void film::setannee(int value){this->annee=value;}
void film::setratio(int value){this->ratio= value;}

            bool film::ajouter()
{

QSqlQuery query;

query.prepare("INSERT INTO FILM (NOM, DIRECTOR, ANNEE,RATIO) "
                    "VALUES (:nom, :director, :annee, :ratio)");

query.bindValue(":nom",getNom());
query.bindValue(":director",getdirector());
query.bindValue(":annee",getannee());
query.bindValue(":ratio",getratio());
return query.exec();

}

  QSqlQueryModel *film::afficher()
 {
 QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from film");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("director "));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("annee"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("ratio"));
     return model;
     }
 /* bool film::modifier()
  {//modifier par nom.
  QSqlQuery query;

     query.prepare("UPDATE film SET DIRECTOR =:director , ANNEE= :annee , RATE= :rate WHERE NOM =:nom ");
     query.bindValue(":annee",getannee());
     query.bindValue(":director",getdirector());
     query.bindValue(":ratio", getratio());

     return query.exec();




}*/
  bool film::modifier(Ui::MainWindow *ui)
  {
      QMessageBox msgBox ;

     QString nom = ui->l1->text();
     QString director= ui->l2->text();
     int annee= ui->l3->text().toInt();
     int ratio= ui->l4->text().toInt();
     film f(nom,director,annee,ratio);
     QSqlQuery query;
     query.prepare ("update film set nom ='"+nom+"',director ='"+director+"',annee ='"+annee+"'where NOM ='"+nom+"'");
     return  (query.exec());

  }
  bool film::supprimer(Ui::MainWindow *ui)
  {

      QMessageBox msgBox ;

     QString nom = ui->l1->text();
     QString director= ui->l2->text();
     int annee= ui->l3->text().toInt();
     int ratio= ui->l4->text().toInt();
     film f(nom,director,annee,ratio);
     QSqlQuery query;
     query.prepare ("DELETE FROM film WHERE nom ='"+nom+"',director ='"+director+"',annee ='"+annee+"'where NOM ='"+nom+"'");
     return  (query.exec());

  }
  QSqlQueryModel *film::tri()
  {
  QSqlQuery *q = new QSqlQuery();
  QSqlQueryModel *model = new QSqlQueryModel();
  q->prepare("SELECT * FROM FILM ORDER BY NOM");
  q->exec();
  model->setQuery(*q);
  return model;
  }

