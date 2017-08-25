/*
 *  Process.h
 *
 *  Author: Cyrus Villacampa
 */

#include <string>

#ifndef PROCESS_H_
#define PROCESS_H_

class Process {
public:
    // Constructor
    Process();
    long arrival;   // Initial arrival time of the process
    long totalTickets;  // Number of tickets to be processed
    long running;   // Total time the process has ran
    long sinceFirstRun; // The time it first ran
    long runningInQueueOne; // Total time the process has ran in queue one
    long remainingTimeQuota;    // Total time quota in queue two
    long waiting;   // Total time the process has waited since it's first run
    int age;    // Ageing mechanism used to process in queue two
    long end;   // The time the process used up it's totalTickets
    int priority;   // Priority number of the process
    std::string processIndex;   // Process ID
};

#endif // PROCESS_H_