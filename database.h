#ifndef DATABASE_H
#define DATABASE_H

#include <pqxx/pqxx>

class Database {
public:
    pqxx::connection* conn;

    Database();
    ~Database();
};

#endif