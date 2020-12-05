#ifndef FILM_H
#define FILM_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTime>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class film
{
    private:
    QString nom;
    QString director;
    int annee;
    int ratio;
public:
    film();
    film (QString,QString,int,int);

    QString getNom();
    QString getdirector();
    int getannee();
    int getratio();

    void setNom(QString);
    void setdirector(QString);
    void setannee(int);
    void setratio(int);



    bool ajouter();
    bool supprimer(Ui::MainWindow *ui);
    bool modifier(Ui::MainWindow *ui);
     QSqlQueryModel * afficher();
     QSqlQueryModel * tri();

};


#endif // FILM_H
