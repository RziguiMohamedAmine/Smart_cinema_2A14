#ifndef ABONNE_H
#define ABONNE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class abonne
{
private:
  QString code,nom,prenom,email;
  long telephone;

public:
  abonne();
  abonne(QString,QString,QString,QString,long);

  QString get_nom();
  QString get_prenom();
  QString get_code();
  QString get_mail();
  long get_telephone();

  void set_nom(QString n);
  void set_prenom(QString p);
  void set_code(QString c);
  void set_mail(QString m);
  void set_telephone(long t);


  bool ajouter();
  QSqlQueryModel * afficher();
  bool supprimer(QString);
  bool modifier();

};

#endif // ABONNE_H
