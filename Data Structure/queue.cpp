// QUEUE
#include <iostream>
#include <string>
#include "../include/datastructs.h"
#include "../include/main.h"
using namespace std;

DualQueue::DualQueue()
    : mainFront(nullptr), mainRear(nullptr),
      waitFront(nullptr), waitRear(nullptr) {}

// ─────────────────────────
// MAIN QUEUE OPERATIONS
// ─────────────────────────

int DualQueue::getQueueBudget() {
    return queueBudget;
}

void DualQueue::addBudget(int grant) {
    queueBudget += grant;
}

void DualQueue::enqueueMain(Applicant *a)
{
    a->next = nullptr;

    if (!mainRear)
    {
        mainFront = mainRear = a;
    }
    else
    {
        mainRear->next = a;
        mainRear = a;
    }
}

Applicant *DualQueue::dequeueMain()
{
    if (!mainFront)
        return nullptr;

    Applicant *temp = mainFront;
    mainFront = mainFront->next;

    if (!mainFront)
        mainRear = nullptr;

    temp->next = nullptr;
    queueBudget -= temp->grant;
    return temp;
}

bool DualQueue::isMainEmpty(){
    return mainFront == nullptr;
}

// ─────────────────────────
// WAITLIST OPERATIONS
// ─────────────────────────

void DualQueue::addWaitlistBudget(int grant) {
    waitlistBudget += grant;
}

int DualQueue::getWaitlistBudget() {
    return waitlistBudget;
}

void DualQueue::enqueueWaitlist(Applicant *a)
{
    a->next = nullptr;

    if (!waitRear)
    {
        waitFront = waitRear = a;
    }
    else
    {
        waitRear->next = a;
        waitRear = a;
    }
}

Applicant *DualQueue::dequeueWaitlist()
{
    if (!waitFront)
        return nullptr;

    Applicant *temp = waitFront;
    waitFront = waitFront->next;

    if (!waitFront)
        waitRear = nullptr;

    temp->next = nullptr;
    waitlistBudget -= temp->grant;
    return temp;
}

bool DualQueue::isWaitlistEmpty()
{
    return waitFront == nullptr;
}


void DualQueue::displayMain() {
    Applicant *curr = mainFront;
    cout << "\nMAIN QUEUE:\n";
    while (curr)
    {
        cout << curr->name << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}

Applicant* DualQueue::getFirst() {
    return mainFront;
}

Applicant* DualQueue::getFirstWaitlist() {
    return waitFront;
}

void DualQueue::displayWaitlist() {
    Applicant *curr = waitFront;
    cout << "\nWAITLIST:\n";
    while (curr)
    {
        cout << curr->name << " -> ";
        curr = curr->next;
    }
    cout << "NULL\n";
}