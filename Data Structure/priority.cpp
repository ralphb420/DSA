// PRIORITY QUEUE
#pragma once
#include <iostream>
#include <string>
using namespace std;

// ─────────────────────────────────────────
// APPLICANT NODE
// Shared node used by Priority Queue
// ─────────────────────────────────────────
struct Applicant {
    string studentID;
    string name;
    float  gpa;
    float  income;       // monthly family income
    int    priority;     // computed score: higher = more deserving
    bool   isHighPriority;
    Applicant* next;

    Applicant(string id, string n, float g, float inc)
        : studentID(id), name(n), gpa(g), income(inc), next(nullptr) {
        // Priority formula: 60% GPA weight + 40% financial need weight
        // Lower income → higher need score (capped at 50,000)
        float needScore = max(0.0f, (50000.0f - income) / 50000.0f) * 40.0f;
        float acadScore = (gpa / 4.0f) * 60.0f;
        priority       = (int)(acadScore + needScore);
        isHighPriority = (gpa >= 3.5f && income <= 20000.0f);
    }
};

// ─────────────────────────────────────────
// PRIORITY QUEUE — High-need applicants
// Sorted linked list (descending priority)
// Highest priority score is extracted first
// ─────────────────────────────────────────
struct PriorityQueue {
    Applicant* head;
    int        size;

    PriorityQueue() : head(nullptr), size(0) {}

    // Insert applicant in sorted position (descending by priority score)
    void insert(Applicant* a) {
        a->next = nullptr;
        if (!head || a->priority >= head->priority) {
            a->next = head;
            head    = a;
        } else {
            Applicant* curr = head;
            while (curr->next && curr->next->priority > a->priority)
                curr = curr->next;
            a->next    = curr->next;
            curr->next = a;
        }
        size++;
        cout << "[PQ] Inserted: " << a->name
             << " | GPA: " << a->gpa
             << " | Score: " << a->priority << "\n";
    }

    // Remove and return the highest-priority applicant
    Applicant* extractMax() {
        if (!head) {
            cout << "[PQ] Priority queue is empty.\n";
            return nullptr;
        }
        Applicant* temp = head;
        head = head->next;
        size--;
        return temp;
    }

    // Peek at the top without removing
    Applicant* peekMax() {
        return head;
    }

    bool isEmpty() { return head == nullptr; }

    void display() {
        cout << "\n=== PRIORITY QUEUE (High-Priority Applicants) ===\n";
        if (isEmpty()) { cout << "  [empty]\n"; return; }
        Applicant* curr = head;
        int rank = 1;
        while (curr) {
            cout << "  " << rank++ << ". [Score:" << curr->priority << "] "
                 << curr->name << " | ID: " << curr->studentID
                 << " | GPA: " << curr->gpa
                 << " | Income: P" << curr->income << "\n";
            curr = curr->next;
        }
        cout << "  Total: " << size << " applicant(s)\n";
    }
};