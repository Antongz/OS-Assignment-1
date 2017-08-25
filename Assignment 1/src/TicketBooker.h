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
    // Insert an element at the head of the list
    void insert(Process);

 private:
    int const QUEUE_ONE_TIME_QUOTA = 5;
    int const QUEUE_TWO_TIME_QUOTA = 20;
    int const THRESHOLD = 2;
    long timer;
    std::vector<Process> queue_one;
    std::vector<Process> queue_two;
 };

 #endif // TICKETBOOKER_H_