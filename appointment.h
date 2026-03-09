#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include "database.h"

class Appointment {

public:

    static void book(Database& db);
    static void view(Database& db);

};

#endif