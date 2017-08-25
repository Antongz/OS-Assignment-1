#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

// Process class
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

// Function headers
void initializeQueues(char *, std::vector<Process *>*);


int main(int argc, char *argv[]) {
    std::vector<Process *> processes;

    // Check if a file name was provided
    if (argc != 2) {
        std::cout << "USAGE: ./main.o [filename]\n";
        exit(EXIT_FAILURE);
    }

    initializeQueues(argv[1], &processes);

    std::vector<Process *>::iterator it;
    for (it = processes.begin(); it < processes.end(); it++) {
        std::cout << (*it)->processIndex << ' ' << (*it)->arrival << ' ' << (*it)->priority << ' ' << (*it)->age << ' ' << (*it)->totalTickets << '\n';
    }
}


// Function implementation
void initializeQueues(char *filename, std::vector<Process *>* processes) {

    // Open the file
    std::ifstream processFile(filename);
    
    // Check if file exist or it was successful in opening the file
    if (!processFile.is_open()) {
        std::cout << "Error opening file \"" << filename << "\"\n";
        exit(EXIT_FAILURE);
    }

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