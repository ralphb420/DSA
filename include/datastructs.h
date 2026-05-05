#ifndef DATASTRUCTS_H
#define DATASTRUCTS_H

#include <string>
struct Applicant;

// PRIORITY QUEUE
class PriorityQueue {
private:
    Applicant* head;
    int queueBudget;

public:

    int PriorityQueue::getQueueBudget();
    void addBudget(int grant);


    Applicant* getFirst();
    PriorityQueue();
    void insert(Applicant* a);
    Applicant* pop();
    bool isEmpty();
    void PriorityQueue::displayQueue();
};

// DUAL QUEUE
class DualQueue {
private:
    Applicant* mainFront;
    Applicant* mainRear;
    Applicant* waitFront;
    Applicant* waitRear;
    int queueBudget;
    int waitlistBudget;

public:
    DualQueue();

    int getQueueBudget();
    void addBudget(int grant);

    void enqueueMain(Applicant* a);
    Applicant* dequeueMain();
    bool isMainEmpty();

    int getWaitlistBudget();
    void addWaitlistBudget(int grant);

    void enqueueWaitlist(Applicant* a);
    Applicant* dequeueWaitlist();
    bool isWaitlistEmpty();

    Applicant* getFirst();
    Applicant* getFirstWaitlist();

    void displayMain();
    void displayWaitlist();
};

// STACK
class BlockchainStack {
private:
    Applicant* top;

public:
    BlockchainStack();

    void push(Applicant* a);
    Applicant* pop();
    Applicant* peek();
    bool isEmpty();
    void display();
    bool validateChain();
};

string createHash(string timeStamp, string previousHash, int grant, string name);
string getTimeStamp();

#endif