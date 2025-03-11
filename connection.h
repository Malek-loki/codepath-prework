#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>

class Connection
{
    QSqlDatabase db;
public:
    Connection();
    bool createconnect();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // CONNECTION_H
