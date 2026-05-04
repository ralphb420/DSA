// PRIORITY QUEUE
#include <iostream>
#include <string>
#include "include/datastructs.h"
#include "include/main.h"
using namespace std;


class PriorityQueue {
private:
    Applicant* head;

public:
    PriorityQueue() : head(nullptr) {}

    void insert(Applicant* a) {
        if (!head || a->priority > head->priority) {
            a->next = head;
            head = a;
            return;
        }

        Applicant* curr = head;
        while (curr->next && curr->next->priority >= a->priority) {
            curr = curr->next;
        }

        a->next = curr->next;
        curr->next = a;
    }

    Applicant* pop() {
        if (!head) return nullptr;

        Applicant* temp = head;
        head = head->next;
        temp->next = nullptr;
        return temp;
    }

    bool isEmpty() {
        return head == nullptr;
    }
};