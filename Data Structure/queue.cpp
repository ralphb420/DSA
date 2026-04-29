// QUEUE
#pragma once
#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────
// FORWARD DECLARATION
// Applicant is defined in priority.cpp
// Include priority.cpp before queue.cpp
// ─────────────────────────────────────────

// ─────────────────────────────────────────
// NORMAL QUEUE — Standard applicants
// First-Come, First-Served (FIFO)
// For applicants who do NOT qualify for
// the high-priority queue
// ─────────────────────────────────────────
struct NormalQueue {
    Applicant* front;
    Applicant* rear;
    int        size;

    NormalQueue() : front(nullptr), rear(nullptr), size(0) {}

    // Add applicant to the rear of the queue
    void enqueue(Applicant* a) {
        a->next = nullptr;
        if (!rear) {
            front = rear = a;
        } else {
            rear->next = a;
            rear       = a;
        }
        size++;
        cout << "[NQ] Enqueued: " << a->name
             << " | ID: " << a->studentID << "\n";
    }

    // Remove and return the front applicant (FIFO)
    Applicant* dequeue() {
        if (!front) {
            cout << "[NQ] Normal queue is empty.\n";
            return nullptr;
        }
        Applicant* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        size--;
        return temp;
    }

    // Peek at the front without removing
    Applicant* peekFront() {
        return front;
    }

    bool isEmpty() { return front == nullptr; }

    void display() {
        cout << "\n=== NORMAL QUEUE (Standard Applicants) ===\n";
        if (isEmpty()) { cout << "  [empty]\n"; return; }
        Applicant* curr  = front;
        int        pos   = 1;
        while (curr) {
            cout << "  " << pos++ << ". "
                 << curr->name << " | ID: " << curr->studentID
                 << " | GPA: " << curr->gpa
                 << " | Income: P" << curr->income << "\n";
            curr = curr->next;
        }
        cout << "  Total: " << size << " applicant(s)\n";
    }
};

// ─────────────────────────────────────────
// WAITLIST — Overflow when budget runs out
// Applicants here are re-evaluated when
// budget becomes available again (iteration)
// ─────────────────────────────────────────
struct Waitlist {
    Applicant* front;
    Applicant* rear;
    int        size;

    Waitlist() : front(nullptr), rear(nullptr), size(0) {}

    void add(Applicant* a) {
        a->next = nullptr;
        if (!rear) {
            front = rear = a;
        } else {
            rear->next = a;
            rear       = a;
        }
        size++;
        cout << "[WL] Added to waitlist: " << a->name << "\n";
    }

    Applicant* next() {
        if (!front) return nullptr;
        Applicant* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        size--;
        return temp;
    }

    // Iterative check: re-process waitlist if budget is available
    void checkWaitlist(int& remainingBudget, int grantAmount) {
        cout << "\n=== WAITLIST CHECK ===\n";
        if (isEmpty()) { cout << "  Waitlist is empty.\n"; return; }

        NormalQueue requeue;
        while (!isEmpty()) {
            Applicant* a = next();
            if (remainingBudget >= grantAmount) {
                remainingBudget -= grantAmount;
                cout << "  [APPROVED from waitlist] " << a->name
                     << " | Remaining budget: P" << remainingBudget << "\n";
            } else {
                requeue.enqueue(a);
                cout << "  [STILL WAITING] " << a->name << "\n";
            }
        }
        // Re-add unprocessed back to waitlist
        while (!requeue.isEmpty()) add(requeue.dequeue());
    }

    bool isEmpty() { return front == nullptr; }

    void display() {
        cout << "\n=== WAITLIST ===\n";
        if (isEmpty()) { cout << "  [empty]\n"; return; }
        Applicant* curr = front;
        int pos = 1;
        while (curr) {
            cout << "  " << pos++ << ". " << curr->name
                 << " | ID: " << curr->studentID << "\n";
            curr = curr->next;
        }
        cout << "  Total waiting: " << size << "\n";
    }
};