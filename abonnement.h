#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class abonnement
{
private:
    QString idab,date_deb,date_fin,type_ab;
    int tarif;
public:
    abonnement();
    abonnement(QString,int,QString,QString,QString);

    QString get_id();
    int get_tarif();
    QString get_date_deb();
    QString get_date_fin();
    QString get_type();

    void set_id(QString n);
    void set_tarif(int p);
    void set_date_debut(QString c);
    void set_date_fin(QString m);
    void set_type(QString t);


    bool ajouter_ab();
    QSqlQueryModel * afficher_ab();
    bool supprimer_ab(QString);
    bool modifier_ab();
};

#endif // ABONNEMENT_H
