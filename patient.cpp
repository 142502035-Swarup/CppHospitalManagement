#include "patient.h"
#include <iostream>

using namespace std;

void Patient::addPatient(Database& db) {

    int id,age;
    string name,disease;

    cout<<"Patient ID: ";
    cin>>id;

    cout<<"Name: ";
    cin>>name;

    cout<<"Age: ";
    cin>>age;

    cout<<"Disease: ";
    cin>>disease;

    pqxx::work W(*db.conn);

    string query =
    "INSERT INTO patients VALUES ("+
    to_string(id)+",'"+name+"',"+
    to_string(age)+",'"+disease+"')";

    W.exec(query);
    W.commit();

    cout<<"Patient added\n";
}

void Patient::viewPatients(Database& db) {

    pqxx::work W(*db.conn);

    pqxx::result R = W.exec("SELECT * FROM patients");

    for(auto row:R){

        cout<<"ID: "<<row["id"].as<int>()<<endl;
        cout<<"Name: "<<row["name"].as<string>()<<endl;
        cout<<"Age: "<<row["age"].as<int>()<<endl;
        cout<<"Disease: "<<row["disease"].as<string>()<<endl;
        cout<<"----------------------\n";
    }
}