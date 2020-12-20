#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "ui_gestion_des_finances.h"
#include "ui_popupmodif.h"

class Transaction
{
    QString id,objet;
    int somme,etat;


public:
    //construct
    Transaction();
    Transaction(QString,QString,float,int);
    //Getter
    QString getId(){return id;}
    QString getObjet(){return objet;}
    float getSomme(){return somme;}
    //Setter
    void setId(QString n){id=n;}
    void setObjet(QString o){objet=o;}
    void setSomme(float somme){this->somme=somme;}
    //CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(Ui::gestion_des_finances *ui);
    bool modifier(Ui::gestion_des_finances *ui,Ui::popupmodif *xi);
    void revenus_net();
    QSqlQueryModel * classer();
};

#endif // TRANSACTION_H
