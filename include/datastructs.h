#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <iostream>
#include "main.h"
using namespace std;

class PriorityQueue {
private:
    Applicant* head;

public:
    PriorityQueue();
    
    void insert(Applicant* a);
    Applicant* pop();
    bool isEmpty() const;
};

class DualQueue {
private:
    // MAIN QUEUE (FIFO)
    Applicant* mainFront;
    Applicant* mainRear;

    // WAITLIST QUEUE (FIFO)
    Applicant* waitFront;
    Applicant* waitRear;

public:
    // CONSTRUCTOR
    DualQueue() : mainFront(nullptr), mainRear(nullptr), waitFront(nullptr), waitRear(nullptr) {}

    // ─────────────────────────
    // MAIN QUEUE OPERATIONS
    // ─────────────────────────

    void enqueueMain(Applicant* a);
    Applicant* dequeueMain();
    bool isMainEmpty();

    // ─────────────────────────
    // WAITLIST OPERATIONS
    // ─────────────────────────

    void enqueueWaitlist(Applicant* a);
    Applicant* dequeueWaitlist();
    bool isWaitlistEmpty();

    // ─────────────────────────
    // DISPLAY (OPTIONAL DEBUG)
    // ─────────────────────────

    void displayMain() const;
    void displayWaitlist() const;
};

class BlockchainStack {
private:
    Applicant* top;

public:
    BlockchainStack() : top(nullptr) {}

    void push(Applicant* block);
    Applicant* pop();
    Applicant* peek() const;
    bool isEmpty() const;
    void display() const;
};

string getTimeStamp();

#endif