#include "appointment.h"
#include <iostream>

using namespace std;

void Appointment::book(Database& db){

    int patient_id,doctor_id;
    string date;

    cout<<"Patient ID: ";
    cin>>patient_id;

    cout<<"Doctor ID: ";
    cin>>doctor_id;

    cout<<"Date: ";
    cin>>date;

    pqxx::work W(*db.conn);

    string query =
    "INSERT INTO appointments(patient_id,doctor_id,date) VALUES("
    +to_string(patient_id)+","+to_string(doctor_id)+",'"+date+"')";

    W.exec(query);
    W.commit();

    cout<<"Appointment booked\n";
}

void Appointment::view(Database& db){

    pqxx::work W(*db.conn);

    pqxx::result R = W.exec("SELECT * FROM appointments");

    for(auto row:R){

        cout<<"Appointment ID: "<<row["id"].as<int>()<<endl;
        cout<<"Patient ID: "<<row["patient_id"].as<int>()<<endl;
        cout<<"Doctor ID: "<<row["doctor_id"].as<int>()<<endl;
        cout<<"Date: "<<row["date"].as<string>()<<endl;

        cout<<"----------------------\n";
    }
}