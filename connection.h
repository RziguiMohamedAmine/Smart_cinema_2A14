#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
QSqlDatabase db=QSqlDatabase::addDatabase("QODBC");
class connection
{QSqlDatabase db;
public :
  connection();
  bool createconnection();
  void closeconnection();

};

#endif // CONNECTION_H
