#include "dialog.h"
#include "ui_dialog.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QString>
#include<QDebug>
#include<QMessageBox>
#include<QListWidget>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    aa.connnect_arduino();
     QObject::connect(aa.getserial(), SIGNAL(readyRead()),this,SLOT(readserial()));

}



Dialog::~Dialog()
{
   aa.close_arduino();
    delete ui;
}

void Dialog::readserial()
{
    aa.read_from_arduino();
  ui->listWidget->addItem(aa.getbuffer());
}













