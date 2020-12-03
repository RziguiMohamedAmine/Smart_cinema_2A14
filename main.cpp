#include "mainwindow.h"

#include <QMessageBox>

#include <QApplication>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    connection c;

    bool test=c.createconnection();
    if(test)
    {
            w.show();
          QMessageBox::information(nullptr,QObject::tr("database is opned"),
          QObject::tr("connection successful.\n"),
               QMessageBox::Cancel);


    }
    else {
          QMessageBox::critical(nullptr,QObject::tr("database is not opned"), QObject::tr("connection not successful !.\n"),
                                QMessageBox::Cancel);
    }

    w.show();
    return a.exec();
}
