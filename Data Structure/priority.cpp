// PRIORITY QUEUE
#include <iostream>
#include <string>
#include "../include/datastructs.h"
#include "../include/main.h"
using namespace std;

PriorityQueue::PriorityQueue() : head(nullptr) {}

int PriorityQueue::getQueueBudget() {
    return queueBudget;
}

void PriorityQueue::addBudget(int grant) {
    queueBudget += grant;
}

Applicant* PriorityQueue::getFirst() {
    return head;
}

void PriorityQueue::insert(Applicant *a)
{
    if (!head || a->priority > head->priority)
    {
        a->next = head;
        head = a;
        return;
    }

    Applicant *curr = head;
    while (curr->next && curr->next->priority >= a->priority)
    {
        curr = curr->next;
    }

    a->next = curr->next;
    curr->next = a;
}

Applicant *PriorityQueue::pop()
{
    if (!head)
        return nullptr;

    Applicant *temp = head;
    head = head->next;
    temp->next = nullptr;
    queueBudget -= temp->grant;
    return temp;
}

<<<<<<< HEAD
bool PriorityQueue::isEmpty() const
{
    return head == nullptr;
}
=======
bool PriorityQueue::isEmpty()
{
    return head == nullptr;
}

void PriorityQueue::displayQueue(){
    Applicant *curr = head;
    cout << "\nPriority Queue:\n";
    while (curr) {
        cout << "Name: " << curr->name 
              << ", Priority: " << curr->priority 
              << ", Grant: " << curr->grant << endl;
        curr = curr->next;
    }
    cout << "NULL\n";
}
>>>>>>> 2a6721c679ab0131928d43b5847c9fad2ba2f07a
