#ifndef ABONNE_H
#define ABONNE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class abonne
{
private:
  QString code,nom,prenom,email,texte_mail;
  long telephone;

public:
  abonne();
  abonne(QString,QString);
  abonne(QString,QString,QString,QString,long);
  QString get_nom();
  QString get_prenom();
  QString get_code();
  QString get_mail();
  QString get_textemail();
  long get_telephone();

  void set_nom(QString n);
  void set_prenom(QString p);
  void set_code(QString c);
  void set_mail(QString m);
  void set_telephone(long t);
  void set_textemail(QString m);


  bool ajouter();
  QSqlQueryModel * afficher();
  bool supprimer(QString);
  bool modifier();
  bool envoyer_mail();

};

#endif // ABONNE_H
