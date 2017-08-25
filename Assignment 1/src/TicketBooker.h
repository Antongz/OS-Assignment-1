/*
 *  TicketBooker.h
 *
 *  Author: Cyrus Villacampa
 *
 *  Interface of TicketBooker class
 */

#ifndef TICKETBOOKER_H_
#define TICKETBOOKER_H_

#include <vector>

 class TicketBooker {
 public:
    // Constructor
    TicketBooker();
    // Start the scheduling algorithm
    void start();
    // Insert an element in queue one(sorted by priority then arrival time then process index)
    void insertQueueOne(Process);
    // Insert an element in queue two(sorted by arrival time then process index)
    void insertQueueTwo(Process);


 private:
    int const QUEUE_ONE_TIME_QUOTA = 5;
    int const QUEUE_TWO_TIME_QUOTA = 20;
    int const THRESHOLD = 2;
    long timer;
    std::vector<Process> queue_one;
    std::vector<Process> queue_two;
 };

 #endif // TICKETBOOKER_H_