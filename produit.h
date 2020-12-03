#ifndef PRODUIT_H
#define PRODUIT_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMediaPlayer>

class produit
{
    QString code,nom;
    int quantite;
    float prix;




public:
    produit(){}
    produit(QString,QString,int,float);
    //getters
    QString getcode(){return code;}
    QString getnom(){return nom;}
    int getquantite(){return quantite;}
    float getprix(){return prix;}
    //setters
    void setcode(QString c){code=c;}
    void setnom(QString n){nom=n;}
void setquantite(float q){quantite=q;}
void setprix(int p){prix=p;}
bool ajouter();
QSqlQueryModel * afficher(QString);
bool supprimer(QString);
QSqlQueryModel * loadData();
bool Update();
QSqlQuery affiche_edit(QString);
QSqlQueryModel * search(QString info);
QSqlQueryModel * sort();



};

#endif // PRODUIT_H
