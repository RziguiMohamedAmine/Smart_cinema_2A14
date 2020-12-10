#include "connection.h"

connection::connection()
{

}



bool connection::createconnect()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet2A");
    db.setUserName("system");
    db.setPassword("Amine12*");

    if(db.open())
        test=true;

    return test;
}
























