#ifndef EMPLOYE1_H
#define EMPLOYE1_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>




class employe1
{
public:
    employe1();

    employe1(QString,int,QString,int,int,QString,int);

    QString get_NOM();
    int get_SALAIRE();
    QString get_PRENOM();
    int get_TELEPHONE();
    int get_ID();
    QString get_FORMATION();
    int get_AGE();
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(employe1);
    QSqlQueryModel * afficherTriId();
    QSqlQueryModel * afficherTriSALAIRE();
    QSqlQueryModel * afficherTriAGE();
    QSqlQueryModel * tri_nom();
    QSqlQueryModel * afficherRechId(int);

private:

    QString NOM,PRENOM,FORMATION;
    int SALAIRE,TELEPHONE,ID,AGE;


};

#endif // EMPLOYE1_H
