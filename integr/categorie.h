#ifndef CATEGORIE_H
#define CATEGORIE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "ui_gestion_des_finances.h"
#include "ui_popupmodif.h"

class Categorie
{
    QString id,nom;
    int type;


public:
    //construct
    Categorie();
    Categorie(QString,QString,int);
    //Getter
    QString getId(){return id;}
    QString getNom(){return nom;}
    float getType(){return type;}
    //Setter
    void setId(QString n){id=n;}
    void setNom(QString no){nom=no;}
    void setType(int type){this->type=type;}
    //CRUD
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(Ui::gestion_des_finances *ui);
    bool modifier(Ui::gestion_des_finances *ui);
    QSqlQueryModel * classer();
    void volume_par_cat(Ui::gestion_des_finances *ui);
};
#endif // CATEGORIE_H
