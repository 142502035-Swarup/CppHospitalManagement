#include "doctor.h"
#include <iostream>

using namespace std;

void Doctor::addDoctor(Database& db){

    int id;
    string name,specialization;

    cout<<"Doctor ID: ";
    cin>>id;

    cout<<"Name: ";
    cin>>name;

    cout<<"Specialization: ";
    cin>>specialization;

    pqxx::work W(*db.conn);

    string query =
    "INSERT INTO doctors VALUES("+
    to_string(id)+",'"+name+"','"+specialization+"')";

    W.exec(query);
    W.commit();

    cout<<"Doctor added\n";
}

void Doctor::viewDoctors(Database& db){

    pqxx::work W(*db.conn);

    pqxx::result R = W.exec("SELECT * FROM doctors");

    for(auto row:R){

        cout<<"ID: "<<row["id"].as<int>()<<endl;
        cout<<"Name: "<<row["name"].as<string>()<<endl;
        cout<<"Specialization: "<<row["specialization"].as<string>()<<endl;
        cout<<"----------------------\n";
    }
}