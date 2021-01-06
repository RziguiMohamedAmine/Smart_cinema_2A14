#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "produit.h"
#include <QMessageBox>
#include <QPixmap>
#include <QMediaPlayer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_code->setPlaceholderText("  Enter code");
     ui->lineEdit_nom->setPlaceholderText("  Enter nom");
     ui->lineEdit_quantite->setPlaceholderText("  Enter quantite");
      ui->lineEdit_prix->setPlaceholderText("  Enter prix");
      ui->lineEdit_code_2->setPlaceholderText("  Enter code");
       ui->lineEdit_nom_f->setPlaceholderText("  Enter nom");
       ui->lineEdit_prenom->setPlaceholderText("  Enter prenom");
        ui->lineEdit_numero->setPlaceholderText("  Enter numero");
        ui->lineEdit_mail_f->setPlaceholderText("  Enter email");


         ui->lineEdit_modif_quantite->setPlaceholderText("  Enter new quantite");
          ui->lineEdit_modif_prix->setPlaceholderText("  Enter new prix");
           ui->lineEdit_modif_code->setPlaceholderText("  Enter new code");
            ui->lineEdit_modif_nom->setPlaceholderText("  Enter new nom");
            ui->lineEdit_mofif_prenom->setPlaceholderText("  Enter new prenom");
            ui->lineEdit_mofif_code->setPlaceholderText("  Enter new code");
            ui->lineEdit_mofif_mumero->setPlaceholderText("  Enter new numero");
            ui->lineEdit_mofif_email_f->setPlaceholderText("  Enter new email");

            ui->subject_edit->setPlaceholderText("  Subject ");
               ui->plainTextEdit->setPlaceholderText("  text ");
animation = new QPropertyAnimation(ui->swittch_pButton,"geometry");
animation->setDuration(10000);
animation->setEndValue(QRect(50,50,100,100));
animation->start();

clicksound =new QMediaPlayer();
clicksound->setMedia(QUrl("Desktop/COMCell_Iphone son de touche 2 (ID 2038)_LS.wav"));


        ui->listView_2->setContextMenuPolicy(Qt::CustomContextMenu);

        connect(ui->listView_2, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu_f(QPoint)));

    ui->listView->setContextMenuPolicy(Qt::CustomContextMenu);

    connect(ui->listView, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));


}

MainWindow::~MainWindow()
{
    delete ui;


}


void MainWindow::on_ajouter_f_button_clicked()
{
    int numero=ui->lineEdit_numero->text().toInt();

        QString code=ui->lineEdit_code_2->text();
        QString nom=ui->lineEdit_nom_f->text();
          QString prenom=ui->lineEdit_prenom->text();
          QString email=ui->lineEdit_mail_f->text();

        fournisseur f(nom,prenom,code,numero,email);
        bool test= f.ajouter_fournisseur();
        if(test)
        {
            clicksound->play();
             QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué !\n""Click cancel to exit ."),QMessageBox::Cancel);

        }
        else
             QMessageBox::information(nullptr,QObject::tr("NOT OK"),QObject::tr("Ajout N'EST PAS effectué !\n""Click cancel to exit ."),QMessageBox::Cancel);

}


void MainWindow::showContextMenu(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("View", this, SLOT(viewProduit()));
    myMenu.addAction("Edit",  this, SLOT(editProduit()));
    myMenu.addAction("Delete", this, SLOT(deleteProduit()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}

void MainWindow::loadData()
{
    produit p;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=p.loadData();
    ui->listView->setModel(model);
}

void MainWindow::on_loadButton_clicked()
{
    clicksound->play();
    loadData();
}

void MainWindow::editProduit()
{
    QModelIndex index = ui->listView->currentIndex();

       QString info = index.data(Qt::DisplayRole).toString();

       QSqlQuery view;

       produit p;

       view = p.affiche_edit(info);



       while(view.next())

       {

             ui->lineEdit_modif_code->setText(view.value(0).toString());

             ui->lineEdit_modif_nom->setText(view.value(1).toString());

             ui->lineEdit_modif_quantite->setText(view.value(2).toString());
              ui->lineEdit_modif_prix->setText(view.value(3).toString());
       }
                ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::viewProduit()
{
    produit p;
    QModelIndex index = ui->listView->currentIndex();
        QString info = index.data(Qt::DisplayRole).toString();
    ui->tableView->setModel(p.afficher(info));
    ui->stackedWidget->setCurrentIndex(7);


}

void MainWindow::deleteProduit()
{
    QModelIndex index = ui->listView->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();

    produit p;
            bool test=p.supprimer(info);

            if(test)
            {
                 loadData();
                 QMessageBox::information(this, tr("produit Deleted"),tr("OK"), QMessageBox::Ok);
            }
}





void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}



void MainWindow::on_ajouter_button_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}



void MainWindow::on_retour_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_ajouter_button_5_clicked()
{
      ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_gestion_produits_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}





void MainWindow::showContextMenu_f(const QPoint &pos)
{
    // Handle global position
    QPoint globalPos = ui->listView_2->mapToGlobal(pos);

    // Create menu and insert some actions
    QMenu myMenu;
    myMenu.addAction("View_f", this, SLOT(viewfournisseur()));
    myMenu.addAction("Edit_f",  this, SLOT(editfournisseur()));
    myMenu.addAction("Delete_f", this, SLOT(deletefournisseur()));

    // Show context menu at handling position
    myMenu.exec(globalPos);
}

void MainWindow::on_ajouter_button2_clicked()
{
    int quantite=ui->lineEdit_code->text().toInt();
     float prix=ui->lineEdit_prix->text().toFloat();

        QString code=ui->lineEdit_code->text();
        QString nom=ui->lineEdit_nom->text();

        produit p(code,nom,quantite,prix);
        bool test= p.ajouter();
        if(test)
        {
            clicksound->play();
             QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr("Ajout effectué !\n""Click cancel to exit ."),QMessageBox::Cancel);
             clicksound->play();

        }
        else
             QMessageBox::information(nullptr,QObject::tr("NOT OK"),QObject::tr("Ajout N'EST PAS effectué !\n""Click cancel to exit ."),QMessageBox::Cancel);
}


void MainWindow::loadData_f()
{
    fournisseur f;
    QSqlQueryModel *model=new QSqlQueryModel();
    model=f.loadData_fournisseur();
    ui->listView_2->setModel(model);
}
void MainWindow::on_loadButton_f_clicked()
{
     loadData_f();
}

void MainWindow::viewfournisseur()
{
    fournisseur f;
    QModelIndex index = ui->listView_2->currentIndex();
        QString info = index.data(Qt::DisplayRole).toString();
    ui->tableView_2->setModel(f.afficher_fournisseur(info));
    ui->stackedWidget->setCurrentIndex(4);


}

void MainWindow::deletefournisseur()
{
    QModelIndex index = ui->listView_2->currentIndex();
    QString info = index.data(Qt::DisplayRole).toString();

    fournisseur f;
            bool test=f.supprimer_fournisseur(info);

            if(test)
            {
                 loadData_f();
                 QMessageBox::information(this, tr("fournisseur Deleted"),tr("OK"), QMessageBox::Ok);
            }
}





void MainWindow::on_retour_f_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_ajouter_fournisseur_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_voir_liste_fournisseur_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_retour_menu_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_ajouter_button_7_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_retour_menu_f_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_save_button_clicked()
{
    bool test=true;

       int quantite;

       float prix;

       QString nom;
       QString code;
       if(test)
       {


           quantite = ui->lineEdit_modif_quantite->text().toInt();

                  prix = ui->lineEdit_modif_prix->text().toFloat();

                  code= ui->lineEdit_modif_code->text();

                  nom = ui->lineEdit_modif_nom->text();
                  qDebug() << nom;
                  qDebug() << code;

                  produit p(code,nom,quantite,prix);
                  bool test2 = p.Update();

                         if(test2)

                         {

                             QMessageBox :: information(nullptr, QObject :: tr("Update Employee"),

                                                        QObject::tr("Employee Updated"),QMessageBox::Cancel);



                         }

                         else

                         {

                             QMessageBox :: warning(nullptr, QObject :: tr("Update Employee"),

                                                        QObject::tr("Error,Employee Not Updated :("),QMessageBox::Cancel);



                         }


       }


}

void MainWindow::on_retour_button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_search_edit_textChanged(const QString &arg1)
{
    produit p;
        QString info =arg1;
        ui->listView->setModel(p.search(info));
}

void MainWindow::on_sort_button_clicked()
{
    produit p;
      //  QSqlQueryModel *model=new QSqlQueryModel();
       // model=p.sort();
        ui->listView->setModel( p.sort());
}








void MainWindow::on_save_f_button_clicked()
{
    bool test=true;

       int numero;



       QString nom;
         QString prenom;
         QString email;

       QString code;
       if(test)
       {


           nom = ui->lineEdit_mofif_nom->text();

                  prenom = ui->lineEdit_mofif_prenom->text();

                  code= ui->lineEdit_mofif_code->text();

                  numero= ui->lineEdit_mofif_mumero->text().toInt();
                  email= ui->lineEdit_mofif_email_f->text();

                  qDebug() << nom;
                  qDebug() << code;
                   qDebug() << email;

                  fournisseur f(nom,prenom,code,numero,email);
                  bool test2 = f.Update_f();

                         if(test2)

                         {

                             QMessageBox :: information(nullptr, QObject :: tr("Update FOURNISSEUR1"),

                                                        QObject::tr("FOURNISSEUR Updated"),QMessageBox::Cancel);



                         }

                         else

                         {

                             QMessageBox :: warning(nullptr, QObject :: tr("Update FOURNISSEUR"),

                                                        QObject::tr("Error,FOURNISSEUR NOT  Updated  :("),QMessageBox::Cancel);



                         }


       }
}

 void MainWindow::editfournisseur()
 {


     QModelIndex index = ui->listView_2->currentIndex();

        QString info = index.data(Qt::DisplayRole).toString();

        QSqlQuery view;

        fournisseur f;

        view = f.affiche_edit_f(info);



        while(view.next())

        {

              ui->lineEdit_mofif_nom->setText(view.value(0).toString());

              ui->lineEdit_mofif_prenom->setText(view.value(1).toString());

              ui->lineEdit_mofif_code->setText(view.value(2).toString());
               ui->lineEdit_mofif_mumero->setText(view.value(3).toString());
               ui->lineEdit_mofif_email_f->setText(view.value(4).toString());

        }
                 ui->stackedWidget->setCurrentIndex(10);



 }


void MainWindow::on_pushButton_3_clicked()
{
    smtp = new Smtp("cinemasmart73@gmail.com" , "191jmt1153", "smtp.gmail.com",465);
       connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

      QString msg=ui->plainTextEdit->toPlainText();


       smtp->sendMail("cinemasmart73@gmail.com","nidhal.zoukeri@esprit.tn",ui->subject_edit->text(),msg);
       bool test2=true;
       if(test2)

       {

           QMessageBox :: information(nullptr, QObject :: tr("Send e-Mail"),

                                      QObject::tr("e-Mail sent "),QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_retour_mail_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_sort_button_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(11);
}




void MainWindow::on_swittch_pButton_clicked()
{
      ui->stackedWidget->setCurrentIndex(5);
}



void MainWindow::on_swittch_fButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_retour_button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_mail_button_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}













