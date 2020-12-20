#include "gestion_des_finances.h"
#include "transaction.h"
#include <QMessageBox>
#include "popupmodif.h"
#include "ui_gestion_des_finances.h"
#include "ui_popupmodif.h"



popupmodif::popupmodif(QWidget *parent) :
    QDialog(parent),
    xi(new Ui::popupmodif)
{
    xi->setupUi(this);
}

popupmodif::~popupmodif()
{
    delete xi;
}

void popupmodif::on_pushButton_ok_clicked()
{
    //QString nobjet=xi->modifobjet->text();
    //float nsomme=xi->modifsomme->text().toFloat()*1000;
    /*QMessageBox msgbox;
    msgbox.setText(nsomme);
    msgbox.exec();*/
    //QString tsomme=nsomme
    //QMessageBox::information(nullptr,QObject::tr("OK"),QObject::tr('"nsomme="'+nsomme+""),QMessageBox::Cancel);
    //QMessageBox::critical(nullptr,QObject::tr("Not OK"),QObject::tr("Erreur lors de la modification.,\n""Click Cancel to exit."),QMessageBox::Cancel);

    close();
}

