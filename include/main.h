#ifndef MAIN_H
#define MAIN_H

#include <string>
#include <algorithm>
using namespace std;

struct Applicant {
    // SIMULATED BLOCK HEADER
    string hash; // OVERALL HASHED TRANSACTION OF THE BLOCK
    string timeStamp;
    int    priority;
    bool   isHighPriority;
    string previousHash; //
    Applicant* next;


    // BLOCK DATA
    int grant; // "5000"
    string name; // "Ralph Ivan Bituin"
    string studentID;
    float  income;
    float  gpa;


    // CONSTRUCTOR
    Applicant(string id, string name, float gpa, float income)
        : studentID(id), name(name), gpa(gpa), income(income), next(nullptr) {
        // Priority formula: 60% GPA weight + 40% financial need weight
        // Lower income → higher need score (capped at 50,000)
        float needScore = max(0.0f, (50000.0f - income) / 50000.0f) * 40.0f;
        float acadScore = (gpa / 4.0f) * 60.0f;
        priority       = (int)(acadScore + needScore);
        isHighPriority = (gpa >= 3.5f && income <= 20000.0f);
    }
};

#endif