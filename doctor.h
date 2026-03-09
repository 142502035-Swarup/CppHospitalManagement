#ifndef DOCTOR_H
#define DOCTOR_H

#include "database.h"

class Doctor {

public:

    static void addDoctor(Database& db);
    static void viewDoctors(Database& db);

};

#endif