#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTime>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class salle
{
    private:
    QString num;
    int nbr;
    QString nbrp;
public:
    salle();
    salle (QString,int,QString);

    QString getNum();
    int getnbr();
    QString getnbrp();

    void setnum(QString);
    void setnbr(int);
    void setnbrp(QString);



    bool ajouter();
    bool supprimer(Ui::MainWindow *ui);
    bool modifier(Ui::MainWindow *ui);
     QSqlQueryModel * afficher();
     QSqlQueryModel * tri1();

};


#endif // FILM_H
