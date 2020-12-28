#include "menu.h"
#include "ui_menu.h"
#include "gestion_clients.h"
#include "ressource_humaine.h"
menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}


void menu::on_pushButton_gestion_des_abonnes_clicked()
{
    gestion_clients g;
    g.setModal(true);
    g.exec();
}

void menu::on_pushButton_gestion_employees_clicked()
{
    ressource_humaine r;
    r.setModal(true);
    r.exec();
}
