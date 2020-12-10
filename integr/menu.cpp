#include "menu.h"
#include "ui_menu.h"
#include "gestion_clients.h"
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

void menu::on_pushButton_gestion_des_finances_clicked()
{
    gestion_des_finances f;
    f.setModal(true);
    f.exec();
}
