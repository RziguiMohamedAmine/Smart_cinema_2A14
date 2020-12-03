#ifndef FOURNISSEUR_H
#define  FOURNISSEUR_H
#include <QSqlQuery>
#include <QSqlQueryModel>
class fournisseur
{
    QString prenom,nom,code,email;
    int numero;



public:
    fournisseur(){}
    fournisseur(QString,QString,QString,int,QString);
    //getters
    QString getnom(){return nom;}
    QString getprenom(){return prenom;}
    QString getcode(){return code;}
    QString geemail(){return email;}

    int getnumero(){return numero;}
    //setters
    void setnom(QString n){nom=n;}
    void setprenom(QString p){prenom=p;}
    void setemail(QString e){email=e;}

void setcode(QString c){code=c;}
void setnumero(int n){numero=n;}
bool ajouter_fournisseur();
QSqlQueryModel * afficher_fournisseur(QString);
bool supprimer_fournisseur(QString);
QSqlQueryModel * loadData_fournisseur();
bool Update_f();
QSqlQuery affiche_edit_f(QString);

};

#endif // PRODUIT_H
