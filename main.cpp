#include "menu.h"
#include <QMessageBox>
#include <QApplication>
#include "connection.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu w;
    w.show();
    connection c;
    bool test=c.createconnect();
    if(test)
    {

      QMessageBox::information(nullptr,QObject::tr("database is open"),
                               QObject::tr("connection successful.\n""click cancel to exit."),QMessageBox::Close);


}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                                 QObject::tr("connection failed.\n""click cancel to exit."),QMessageBox::Cancel);

    }
     return a.exec();
}
