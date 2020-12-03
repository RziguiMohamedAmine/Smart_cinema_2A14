#include "connection.h"
#include "QSqlDatabase"
//test connection git
connection::connection()
{

}
bool connection::createconnection()
{

    bool test=false;
     db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Projet_appl");
    db.setUserName("system");
    db.setPassword("1234");
    if(db.open())
     test=true;
    return test;

}
bool connection::closeconnection()
{
    db.close();

}
