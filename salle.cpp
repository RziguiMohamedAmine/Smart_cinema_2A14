#include "salle.h"
#include <QSqlQuery>
#include <QMessageBox>

            salle::salle()
{
    num="";

    nbr=0;
     nbrp="";

}

            salle::salle(QString num,int nbr,QString nbrp)
{

    this->num=num;
    this->nbr=nbr;
    this->nbrp=nbrp;
}


QString salle::getNum(){return num;}
int salle::getnbr(){return nbr;}
QString salle::getnbrp(){return nbrp;}


void salle::setnum(QString value){this->num=value;}
void salle::setnbr(int value){this->nbr=value;}
void salle::setnbrp(QString value){this->nbrp= value;}

            bool salle::ajouter()
{

QSqlQuery query;

query.prepare("INSERT INTO SALLE (NUM,NBR,NBRP) "
                    "VALUES (:num,:nbr, :nbrp)");

query.bindValue(":num",getNum());
query.bindValue(":nbr",getnbr());
query.bindValue(":nbrp",getnbrp());
return query.exec();

}

  QSqlQueryModel *salle::afficher()
 {
 QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("select * from salle");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("num"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nbr"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbrp"));
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
  bool salle::modifier(Ui::MainWindow *ui)
  {
      QMessageBox msgBox ;

     QString num = ui->l5->text();
     int nbr= ui->l6->text().toInt();
     QString nbrp= ui->l7->text();
     salle s(num,nbr,nbrp);
     QSqlQuery query;
     query.prepare ("update salle set num ='"+num+"',nbr ='"+nbr+"',nbrp ='"+nbrp+"'where num ='"+num+"'");
     return  (query.exec());

  }
  bool salle::supprimer(Ui::MainWindow *ui)
  {

      QMessageBox msgBox ;

     QString num = ui->l5->text();
     int nbr= ui->l6->text().toInt();
     QString nbrp= ui->l7->text();
     salle s(num,nbr,nbrp);
     QSqlQuery query;
     query.prepare ("DELETE FROM salle WHERE num ='"+num+"',nbr ='"+nbr+"',nbrp ='"+nbrp+"'where NUM ='"+num+"'");
     return  (query.exec());

  }
  QSqlQueryModel *salle::tri1()
  {
  QSqlQuery *q = new QSqlQuery();
  QSqlQueryModel *model = new QSqlQueryModel();
  q->prepare("SELECT * FROM SALLE ORDER BY NBR");
  q->exec();
  model->setQuery(*q);
  return model;
  }

