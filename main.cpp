#include <iostream>
#include "database.h"
#include "patient.h"
#include "doctor.h"
#include "appointment.h"

using namespace std;

int main(){

    Database db;

    int choice;

    while(true){

        cout<<"\n===== Hospital Management System =====\n";

        cout<<"1 Add Patient\n";
        cout<<"2 View Patients\n";
        cout<<"3 Add Doctor\n";
        cout<<"4 View Doctors\n";
        cout<<"5 Book Appointment\n";
        cout<<"6 View Appointments\n";
        cout<<"7 Exit\n";

        cout<<"Choice: ";
        cin>>choice;

        switch(choice){

            case 1:
                Patient::addPatient(db);
                break;

            case 2:
                Patient::viewPatients(db);
                break;

            case 3:
                Doctor::addDoctor(db);
                break;

            case 4:
                Doctor::viewDoctors(db);
                break;

            case 5:
                Appointment::book(db);
                break;

            case 6:
                Appointment::view(db);
                break;

            case 7:
                return 0;

            default:
                cout<<"Invalid choice\n";
        }
    }
}