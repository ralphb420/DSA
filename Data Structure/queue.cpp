// QUEUE
#pragma once
#include <iostream>
#include <string>
#include "include/datastructs.h"
#include "include/main.h"
using namespace std;

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
    DualQueue() {
        mainFront = mainRear = nullptr;
        waitFront = waitRear = nullptr;
    }

    // ─────────────────────────
    // MAIN QUEUE OPERATIONS
    // ─────────────────────────

    void enqueueMain(Applicant* a) {
        a->next = nullptr;

        if (!mainRear) {
            mainFront = mainRear = a;
        } else {
            mainRear->next = a;
            mainRear = a;
        }
    }

    Applicant* dequeueMain() {
        if (!mainFront) return nullptr;

        Applicant* temp = mainFront;
        mainFront = mainFront->next;

        if (!mainFront) mainRear = nullptr;

        temp->next = nullptr;
        return temp;
    }

    bool isMainEmpty() {
        return mainFront == nullptr;
    }

    // ─────────────────────────
    // WAITLIST OPERATIONS
    // ─────────────────────────

    void enqueueWaitlist(Applicant* a) {
        a->next = nullptr;

        if (!waitRear) {
            waitFront = waitRear = a;
        } else {
            waitRear->next = a;
            waitRear = a;
        }
    }

    Applicant* dequeueWaitlist() {
        if (!waitFront) return nullptr;

        Applicant* temp = waitFront;
        waitFront = waitFront->next;

        if (!waitFront) waitRear = nullptr;

        temp->next = nullptr;
        return temp;
    }

    bool isWaitlistEmpty() {
        return waitFront == nullptr;
    }

    // ─────────────────────────
    // DISPLAY (OPTIONAL DEBUG)
    // ─────────────────────────

    void displayMain() {
        Applicant* curr = mainFront;
        cout << "\nMAIN QUEUE:\n";
        while (curr) {
            cout << curr->name << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    void displayWaitlist() {
        Applicant* curr = waitFront;
        cout << "\nWAITLIST:\n";
        while (curr) {
            cout << curr->name << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }
};