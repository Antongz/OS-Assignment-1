/*
 *  Process.cpp
 *
 *  Author: Cyrus Villacampa
 *
 *  Implementation of the Process class
 */

#include "Process.h"

// Constructor
Process::Process(void) {
    running = 0;
    sinceFirstRun = -1;
    waiting = 0;
    age = 0;
    end = 0;
}