#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

/* ================= Process class ================= */
class Process {
public:
    long arrival;   // Initial arrival time of the process
    long totalTickets;  // Number of tickets to be processed
    long running = 0;   // Total time the process has ran
    long sinceFirstRun = -1; // The time it first ran
    long runningInQueueOne = 0; // Total time the process has ran in queue one
    long remainingTimeQuota;    // Total time quota in queue two
    long waiting = 0;   // Total time the process has waited since it's first run
    int age = 0;    // Ageing mechanism used to process in queue two
    long end = 0;   // The time the process used up it's totalTickets
    int priority;   // Priority number of the process
    std::string processIndex;   // Process ID
};

/* ================= QueueOne class ================= */
class QueueOne {
public:
    // Insert an element in queue one(sorted by priority then arrival time then process index)
    void insert(Process, bool);
    // Pop head of the queue
    Process popHead();
private:
    std::vector<Process*> queue; // Highest priority queue
}

/* ================= QueueTwo class ================= */
class QueueTwo {
public:
    // Insert an element in queue two(sorted by arrival time then process index)
    void insert(Process, bool);
    // Pop head of the queue
    Process popHead();

private:
    std::vector<Process*> queue; // Lowest priority queue
}

/* ================= Scheduling class ================= */
class Scheduling {
public:
    // Start the scheduling algorithm
    void start();

    // Read the file and initialize all queues
    void initializeQueues(std::ifstream);
    
private:
    int const QUEUE_ONE_TIME_QUOTA = 5;
    int const QUEUE_TWO_TIME_QUOTA = 20;
    int const THRESHOLD = 2;
    long timer;
    QueueOne queue_one;
    QueueTwo queue_two;
    
};

/* ====================== Main program =================== */
int main(int argc, char *argv[]) {
    Scheduling ticketBooker;

    // Check if a file name was provided
    if (argc != 2) {
        std::cout << "USAGE: ./main.o [filename]\n";
        exit(EXIT_FAILURE);
    }

    // Open the file
    std::ifstream processFile(filename);
    
    // Check if file exist or it was successful in opening the file
    if (!processFile.is_open()) {
        std::cout << "Error opening file \"" << filename << "\"\n";
        exit(EXIT_FAILURE);
    }

    ticketBooker.initializeQueues(processFile);

    /* ========= DEBUGGING PURPOSES ========= */
    // std::vector<Process *>::iterator it;
    // for (it = processes.begin(); it < processes.end(); it++) {
    //     std::cout << (*it)->processIndex << ' ' << (*it)->arrival << ' ' << (*it)->priority << ' ' << (*it)->age << ' ' << (*it)->totalTickets << '\n';
    // }

}

/* ====================== Class member function implementations ================== */

void Scheduling::initializeQueues(std::ifstream processFile) {
    std::string line;
    std::string str;

    while (std::getline(processFile,line)) {
        int attr = 1;
        int i = 0;

        // Dynamically allocate process objects
        (*processes).insert((*processes).end(), new Process());        
        
        // Extract process index
        while (line[i] != ' ') {
            str += line[i];
            i += 1;
        }
        i += 1;

        // Store process index
        (*((*processes).end()-1))->processIndex = str;
        str = "";

        // Extract and store process attributes
        while (line[i] != '\0') {
            if (line[i] != ' ' && line[i + 1] != '\0') {
                str += line[i];
            } else {
                switch (attr) {
                    case 1: // initial arrival time
                        (*((*processes).end()-1))->arrival = std::stol(str, nullptr);
                        break;
                    case 2: // priority
                        (*((*processes).end()-1))->priority = std::stol(str, nullptr);
                        break;
                    case 3: // age
                        (*((*processes).end()-1))->age = std::stol(str, nullptr);
                        break;
                    case 4: // total tickets
                        (*((*processes).end()-1))->totalTickets = std::stol(str, nullptr);
                        break;
                    default:
                        break;
                }
                attr += 1;
                str = "";
            }

            i += 1;
        }
        
    }
    
    /* ======== DEBUGGING PURPOSES ======= */
    // std::vector<Process *>::iterator it;
    // for (it = (*processes).begin(); it < (*processes).end(); it++) {
    //     std::cout << (*it)->processIndex << ' ' << (*it)->arrival << ' ' << (*it)->priority << ' ' << (*it)->age << ' ' << (*it)->totalTickets << '\n';
    // }

    // Close the file
    processFile.close();
}

void Scheduling::start() {
    // TODO: Implement scheduling algorithm
}

void QueueOne::insert(Process proc, bool strict) {

}

void QueueTwo::insert(Process proc, bool strict) {

}

Process QueueOne::popHead() {

}

Process QueueTwo::popHead() {

}