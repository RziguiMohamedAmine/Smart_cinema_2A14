#ifndef DEPARTEMENT1_H
#define DEPARTEMENT1_H



#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class departement1
{
public:
    departement1();


    departement1(QString,int);

    QString get_TYPE();
    int get_NB_EMPLOYE();


    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(QString);


private:
    QString TYPE;
    int NB_EMPLOYE;

};














#endif // DEPARTEMENT1_H
