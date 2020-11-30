#include "gestion_clients.h"
#include "ui_gestion_clients.h"
#include "connexion.h"
#include "login.h"
#include "abonne.h"
#include "abonnement.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QPixmap>
#include <QFileDialog>

gestion_clients::gestion_clients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_clients)
{
    ui->setupUi(this);
    connexion c;
    bool test=c.createconnect();
    if(test)
    {
        ui->label_gcon->setText("connected...");
    }



   // s=new QSound(":/sound/1.mp3");
    //s->play();


    affichertable_abonnement();
    //ui->tableView->setModel(aa.afficher());
    ui->comboBox_4->setModel(aa.afficher());
    //ui->tableView_2->setModel(ab.afficher_ab());
    ui->comboBox->setModel(ab.afficher_ab());
    affichertable_abonne();


    ui->lineEdit_telephone->setValidator(new QIntValidator(0, 9999999, this));
    ui->lineEdit_id->setValidator(new QIntValidator(0, 99999, this));


}

gestion_clients::~gestion_clients()
{
    delete ui;
}

void gestion_clients::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void gestion_clients::on_tabWidget_2_tabCloseRequested(int index)
{
    ui->tabWidget_2->removeTab(index);
}

void gestion_clients::on_tabWidget_3_tabCloseRequested(int index)
{
    ui->tabWidget_3->removeTab(index);
}


void gestion_clients::on_pushButton_ajouter_clicked()
{
  long telephone = ui->lineEdit_telephone->text().toLong();
  QString nom = ui->lineEdit_nom->text();
  QString prenom = ui->lineEdit_prenom->text();
  QString code = ui->lineEdit_code->text();
  QString mail = ui->lineEdit_mail->text();
  //QString texte=ui->lineEdit_4->text();

  abonne e(code,nom,prenom,mail,telephone);
  bool test=e.ajouter();
  if(test)
  {
     // ui->tableView->setModel(aa.afficher());
      affichertable_abonne();
      ui->comboBox_4->setModel(aa.afficher());

      QMessageBox::information(nullptr,QObject::tr("Ajouter un abonné"),
                               QObject::tr("abonné Ajouté !!\n""Click Cancel to exit."),QMessageBox::Cancel);

  }
  else
       QMessageBox::critical(nullptr,QObject::tr("Ajouter un abonné"),
                                QObject::tr("Erreur !!\n""Click Cancel to exit."),QMessageBox::Cancel);

}














void gestion_clients::on_comboBox_4_currentIndexChanged()
{
    QString codee=ui->comboBox_4->currentText();

    QSqlQuery qry;
    qry.prepare("select * from abonne where code='"+codee+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_8->setText(qry.value(0).toString());
            ui->lineEdit_6->setText(qry.value(1).toString());
            ui->lineEdit_7->setText(qry.value(2).toString());
            ui->lineEdit_9->setText(qry.value(3).toString());
            ui->lineEdit_10->setText(qry.value(4).toString());
        }
    }
}

void gestion_clients::on_pushButton_supprimer_clicked()
{

    bool test=aa.supprimer(selected);
    if(test)
    {
        //ui->tableView->setModel(aa.afficher());
        affichertable_abonne();
        ui->comboBox_4->setModel(aa.afficher());

        QMessageBox::information(nullptr,QObject::tr("supprimer un abonné"),
                        QObject::tr("abonné supprimer !!\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
         QMessageBox::critical(nullptr,QObject::tr("supprimer un abonné"),
                                  QObject::tr("Erreur !!\n""Click Cancel to exit."),QMessageBox::Cancel);

}




void gestion_clients::on_pushButton_clicked()
{
    long telephone = ui->lineEdit_9->text().toLong();
    QString nom = ui->lineEdit_6->text();
    QString prenom = ui->lineEdit_7->text();
    QString code = ui->lineEdit_8->text();
    QString mail = ui->lineEdit_10->text();

    abonne e(code,nom,prenom,mail,telephone);
    bool test=e.modifier();
    if(test)
    {
       // ui->tableView->setModel(aa.afficher());
        affichertable_abonne();
        ui->comboBox_4->setModel(aa.afficher());

        QMessageBox::information(nullptr,QObject::tr("modifier un abonné"),
                                 QObject::tr("abonné modifié !!\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("modifier un abonné"),
                                 QObject::tr("Erreur !!\n""Click Cancel to exit."),QMessageBox::Cancel);

}







void gestion_clients::on_pushButton_ajout_ab_clicked()
{
    QString id = ui->lineEdit_id->text();
    int tarif = ui->lineEdit_tarif->text().toInt();
    QString date_debut = ui->lineEdit_date_debut->text();
    QString date_fin = ui->lineEdit_date_fin->text();
    QString type = ui->lineEdit_type->text();

    abonnement a(id,tarif,date_debut,date_fin,type);
    bool test=a.ajouter_ab();
    if(test)
    {
       // ui->tableView_2->setModel(ab.afficher_ab());
        affichertable_abonnement();
        ui->comboBox->setModel(ab.afficher_ab());

        QMessageBox::information(nullptr,QObject::tr("Ajouter un abonnement"),
                                 QObject::tr("abonnement Ajouté !!\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
         QMessageBox::critical(nullptr,QObject::tr("Ajouter un abonnement"),
                                  QObject::tr("Erreur !!\n""Click Cancel to exit."),QMessageBox::Cancel);

}







void gestion_clients::on_comboBox_currentIndexChanged()
{
    QString idabb=ui->comboBox->currentText();
    QSqlQuery query;

    query.prepare("select * from abonnement where idab='"+idabb+"'");
    if(query.exec())
    {
        while (query.next())
        {
            ui->lineEdit_11->setText(query.value(0).toString());
            ui->lineEdit_12->setText(query.value(1).toString());
            ui->lineEdit_13->setText(query.value(2).toString());
            ui->lineEdit_14->setText(query.value(3).toString());
            ui->lineEdit_15->setText(query.value(4 ).toString());
        }
    }


}



//commit git


void gestion_clients::on_pushButton_supprimer_ab_clicked()
{

    bool test=ab.supprimer_ab(selected2);
    if(test)
    {
        //ui->tableView_2->setModel(ab.afficher_ab());
        affichertable_abonnement();
        ui->comboBox->setModel(ab.afficher_ab());

        QMessageBox::information(nullptr,QObject::tr("supprimer un abonné"),
                        QObject::tr("abonné supprimer !!\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
         QMessageBox::critical(nullptr,QObject::tr("supprimer un abonné"),
                                  QObject::tr("Erreur !!\n""Click Cancel to exit."),QMessageBox::Cancel);

}










void gestion_clients::on_pushButton_modif_ab_clicked()
{
    QString id=ui->lineEdit_11->text();
    int tarif=ui->lineEdit_12->text().toInt();
    QString date_deb=ui->lineEdit_13->text();
    QString date_fin=ui->lineEdit_14->text();
    QString type=ui->lineEdit_15->text();

    abonnement a(id,tarif,date_deb,date_fin,type);
    bool test=a.modifier_ab();
    if(test)
    {
        //ui->tableView_2->setModel(ab.afficher_ab());
        affichertable_abonnement();
        ui->comboBox->setModel(ab.afficher_ab());
        QMessageBox::information(nullptr,QObject::tr("modifier un abonnement"),
                                 QObject::tr("abonnement modifié !!\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("modifier un abonnement"),
                                 QObject::tr("Erreur !!\n""Click Cancel to exit."),QMessageBox::Cancel);

}



void gestion_clients::affichertable_abonne()
{
        filtre_abonne = new QSortFilterProxyModel();

        filtre_abonne->setSourceModel(aa.afficher());

        filtre_abonne->setFilterCaseSensitivity(Qt::CaseInsensitive);

        filtre_abonne->setFilterKeyColumn(-1);

        ui->tableView->setModel(filtre_abonne);


}




void gestion_clients::affichertable_abonnement()
{
    filtre_abonnement = new QSortFilterProxyModel();

    filtre_abonnement->setSourceModel(ab.afficher_ab());

    filtre_abonnement->setFilterCaseSensitivity(Qt::CaseInsensitive);

    filtre_abonnement->setFilterKeyColumn(-1);

    ui->tableView_2->setModel(filtre_abonnement);

}













void gestion_clients::on_tableView_clicked(const QModelIndex &index)
{
    selected=ui->tableView->model()->data(index).toString();
}


void gestion_clients::on_tableView_2_clicked(const QModelIndex &index)
{
    selected2=ui->tableView_2->model()->data(index).toString();
}

void gestion_clients::on_lineEdit_textChanged(const QString &arg1)
{
    filtre_abonnement->setFilterFixedString(arg1);
}

void gestion_clients::on_lineEdit_rech_textChanged(const QString &arg1)
{
    filtre_abonne->setFilterFixedString(arg1);
}







void gestion_clients::on_pushButton_2_clicked()
{
    /*QPrinter printer2;

    QPrintDialog dialog(&printer2,this);
    dialog.setWindowTitle("imprimer abonnement");
    if(ui->textEdit->textCursor().hasSelection())
    dialog.addEnabledOption(QAbstractPrintDialog::PrintSelection);
    if(dialog.exec() != QDialog::Accepted)
    {
        return;
    }*/

    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tableView_2->model()->rowCount();
                     const int columnCount = ui->tableView_2->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#e7ff3c link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des abonnements </H1></br></br><table border=1 cellspacing=0 cellpadding=5>\n";

                     // headers
                     out << "<thead><tr bgcolor=#c5b2ec> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView_2->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView_2->isColumnHidden(column)) {
                   QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty())
                 { fileName.append(".pdf");

                 }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);

}








void gestion_clients::on_pushButton_3_clicked()
{

    QString mail=ui->lineEdit_3->text();
    QString text = this->ui->textEdit_2->toPlainText();
    abonne e(mail,text);

    bool test=e.envoyer_mail();
    if(test)
    {
       // ui->tableView->setModel(aa.afficher());
        affichertable_abonne();
        ui->comboBox_4->setModel(aa.afficher());

        QMessageBox::information(nullptr,QObject::tr("envoyer un mail"),
                                 QObject::tr("mail envoyé !!\n""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("envoyer un mail"),
                                 QObject::tr("Erreur !!\n""Click Cancel to exit."),QMessageBox::Cancel);

}











