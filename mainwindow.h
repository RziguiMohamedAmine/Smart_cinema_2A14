#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "smtp.h"
#include <QMainWindow>
#include <QDebug>
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QMediaPlayer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

     void on_ajouter_f_button_clicked();


    void showContextMenu(const QPoint&);
     void showContextMenu_f(const QPoint&);

    void viewProduit();
    void viewfournisseur();

    void deleteProduit();
     void deletefournisseur();
     void editProduit();
      void editfournisseur();
     void loadData();
      void loadData_f();

     void on_loadButton_clicked();


     void on_pushButton_clicked();


     void on_ajouter_button_4_clicked();


     void on_retour_button_clicked();
    void on_save_button_clicked();

     void on_ajouter_button_5_clicked();


     void on_gestion_produits_clicked();

      void on_save_f_button_clicked();
     void on_loadButton_f_clicked();

     void on_ajouter_button2_clicked();

     void on_retour_f_button_clicked();

     void on_ajouter_fournisseur_clicked();

     void on_voir_liste_fournisseur_clicked();

     void on_retour_menu_clicked();

     void on_ajouter_button_7_clicked();

     void on_retour_menu_f_clicked();


     void on_retour_button_2_clicked();

     void on_search_edit_textChanged(const QString &arg1);

     void on_sort_button_clicked();

     void mailSent(QString)
         {

         };

     void on_pushButton_3_clicked();

     void on_pushButton_retour_mail_clicked();

     void on_sort_button_2_clicked();




     void on_swittch_pButton_clicked();

     void on_swittch_fButton_clicked();

     void on_retour_button_3_clicked();

     void on_mail_button_clicked();

private:
    Ui::MainWindow *ui;
    Smtp * smtp;
    QPropertyAnimation * animation;
    QMediaPlayer *clicksound;


};
#endif // MAINWINDOW_H
