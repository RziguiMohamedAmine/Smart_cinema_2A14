#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>

class connection
{
private :
    QSqlDatabase db;
public:
    connection();
    bool createconnection();
    bool closeconnection();
};

#endif // CONNECTION_H
