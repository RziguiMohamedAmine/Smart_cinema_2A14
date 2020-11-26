#include "connexion.h"

connexion::connexion()
{

}


bool connexion::createconnect()
{
    bool test=false;
    db=QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet2A");
    db.setUserName("system");
    db.setPassword("Amine12*");

    if(db.open())
        test=true;

    return test;
}


void connexion::closeconnect()
{
    db.close();
    db.removeDatabase(QSqlDatabase::defaultConnection);
}









