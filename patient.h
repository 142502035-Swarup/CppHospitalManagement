#ifndef PATIENT_H
#define PATIENT_H

#include "database.h"

class Patient {

public:

    static void addPatient(Database& db);
    static void viewPatients(Database& db);

};

#endif