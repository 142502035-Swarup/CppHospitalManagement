#include "database.h"
#include <iostream>

Database::Database() {

    try {

        conn = new pqxx::connection(
            "dbname=hospital user=postgres password=postgres host=localhost port=5432"
        );

        if(conn->is_open())
            std::cout<<"Database Connected\n";

    }
    catch (const std::exception &e) {

        std::cerr<<e.what()<<std::endl;
    }
}

Database::~Database() {

    conn->close();
}