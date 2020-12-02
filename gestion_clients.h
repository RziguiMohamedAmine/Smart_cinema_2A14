#ifndef GESTION_CLIENTS_H
#define GESTION_CLIENTS_H

#include <QDialog>
#include "abonne.h"
#include "abonnement.h"
#include<QSortFilterProxyModel>
#include<QTextTableFormat>
#include<QStandardItemModel>
#include<QPrinter>
#include<QPrintDialog>
#include<QSound>
#include<QMediaPlayer>
#include <QSoundEffect>
#include<QPropertyAnimation>


namespace Ui {
class gestion_clients;
}

class gestion_clients : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_clients(QWidget *parent = nullptr);
    QString selected;
    QString selected2;
    QSortFilterProxyModel *filtre_abonne,*filtre_abonnement;
    void affichertable_abonne();
    void affichertable_abonnement();
    ~gestion_clients();

private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_tabWidget_2_tabCloseRequested(int index);

    void on_tabWidget_3_tabCloseRequested(int index);

    void on_pushButton_ajouter_clicked();




    void on_comboBox_4_currentIndexChanged();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_ajout_ab_clicked();

    void on_comboBox_currentIndexChanged();

    void on_pushButton_supprimer_ab_clicked();

    void on_pushButton_modif_ab_clicked();

    void on_tableView_clicked(const QModelIndex &index);


    void on_tableView_2_clicked(const QModelIndex &index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::gestion_clients *ui;
    abonne aa;
    abonnement ab;
    QSound *s;
};

#endif // GESTION_CLIENTS_H
