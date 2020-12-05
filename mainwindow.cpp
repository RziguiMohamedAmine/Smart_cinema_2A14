#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <film.h>
#include <salle.h>
#include "mainwindow.h"

#include "ui_mainwindow.h"

#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

#include <QMessageBox>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QPrintDialog>
#include <QMovie>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_pushButton_clicked()
{QString n=ui->nom->text();
    QString d=ui->director->text();
    int a=ui->annee->text().toInt();
    int r=ui->rate->text().toInt();
    film f(n,d,a,r);
     bool test=f.ajouter();
     if (test)
     {
         QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue\n"
                                                                         "click cancel to exit."),QMessageBox::Cancel);
     }
     else

         QMessageBox:: critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue\n"
                                                                         "click cancel to exit."),QMessageBox::Cancel);

}




void MainWindow::on_view_activated(const QModelIndex &index)
{

        ui->l1->setText( ui->view->model()->data(ui->view->model()->index(ui->view->selectionModel()->currentIndex().row(),0)).toString() );
        ui->l2->setText( ui->view->model()->data(ui->view->model()->index(ui->view->selectionModel()->currentIndex().row(),1)).toString() );
        ui->l3->setText( ui->view->model()->data(ui->view->model()->index(ui->view->selectionModel()->currentIndex().row(),2)).toString() );
        ui->l4->setText( ui->view->model()->data(ui->view->model()->index(ui->view->selectionModel()->currentIndex().row(),2)).toString() );

}

void MainWindow::on_modifier_clicked()
{


      film e;

                if(e.modifier(ui))
                {
                    QMessageBox ::information(this,"","film modifiee")  ;
        ui->view->setModel(e.afficher());


                }
                else{QMessageBox ::information(this,"","film erreur")  ;}

}

void MainWindow::on_supprimer_clicked()
{
    film f;

    if(f.supprimer(ui))
    { QMessageBox ::information(this,"","film supprimer")  ;
        ui->view->setModel(f.afficher());


                }
                else{QMessageBox ::information(this,"","film erreur")  ;

    }
}



void MainWindow::on_pushButton_3_clicked()
{

        //imprimer

        QPrinter printer;

        printer.setPrinterName("desiered printer name");

      QPrintDialog dialog(&printer,this);

        if(dialog.exec()== QDialog::Rejected)

            return;


}

void MainWindow::on_pushButton_2_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->view->model()->rowCount();
                    const int columnCount = ui->view->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->view->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->view->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->view->isColumnHidden(column)) {
                                QString data = ui->view->model()->data(ui->view->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table> </center>\n"
                        "</body>\n"
                        "</html>\n";

              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

               QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setPaperSize(QPrinter::A4);
              printer.setOutputFileName(fileName);

               QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);

}


void MainWindow::on_tri_clicked()
{
    film f;
    ui->view->setModel(f.tri());
}

void MainWindow::on_tri_2_clicked()
{
    salle f;
    ui->view_2->setModel(f.tri1());

}



void MainWindow::on_pushButton2_clicked()
{
    QString n=ui->num->text();

        int a=ui->nbr->text().toInt();
        QString r=ui->nbrp->text();
        salle s(n,a,r);
         bool test=s.ajouter();
         if (test)
         {
             QMessageBox:: information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectue\n"
                                                                             "click cancel to exit."),QMessageBox::Cancel);
         }
         else

             QMessageBox:: critical(nullptr,QObject::tr("not ok"),QObject::tr("ajout non effectue\n"
                                                                             "click cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_modifier_2_clicked()
{

    salle e;

              if(e.modifier(ui))
              {
                  QMessageBox ::information(this,"","salle modifiee")  ;
      ui->view_2->setModel(e.afficher());


              }
              else{QMessageBox ::information(this,"","salle erreur")  ;}

}

void MainWindow::on_supprimer_2_clicked()
{
    salle s;

    if(s.supprimer(ui))
    { QMessageBox ::information(this,"","salle supprimer")  ;
        ui->view_2->setModel(s.afficher());


                }
                else{QMessageBox ::information(this,"","film erreur")  ;

}
}

void MainWindow::on_pushButton_4_clicked()
{
    QString strStream;
                    QTextStream out(&strStream);

                    const int rowCount = ui->view_2->model()->rowCount();
                    const int columnCount = ui->view_2->model()->columnCount();

                    out <<  "<html>\n"
                        "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                        <<  QString("<title>%1</title>\n").arg("strTitle")
                        <<  "</head>\n"
                        "<body bgcolor=#ffffff link=#5000A0>\n"

                       //     "<align='right'> " << datefich << "</align>"
                        "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                    // headers
                    out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                    for (int column = 0; column < columnCount; column++)
                        if (!ui->view_2->isColumnHidden(column))
                            out << QString("<th>%1</th>").arg(ui->view_2->model()->headerData(column, Qt::Horizontal).toString());
                    out << "</tr></thead>\n";

                    // data table
                    for (int row = 0; row < rowCount; row++) {
                        out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                        for (int column = 0; column < columnCount; column++) {
                            if (!ui->view_2->isColumnHidden(column)) {
                                QString data = ui->view_2->model()->data(ui->view_2->model()->index(row, column)).toString().simplified();
                                out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                            }
                        }
                        out << "</tr>\n";
                    }
                    out <<  "</table> </center>\n"
                        "</body>\n"
                        "</html>\n";

              QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

               QPrinter printer (QPrinter::PrinterResolution);
                printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setPaperSize(QPrinter::A4);
              printer.setOutputFileName(fileName);

               QTextDocument doc;
                doc.setHtml(strStream);
                doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                doc.print(&printer);
}

void MainWindow::on_pushButton_5_clicked()
{
    //imprimer

    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;

}

