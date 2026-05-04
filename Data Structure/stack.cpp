// STACK
#include <iostream>
#include <string>
#include <ctime>
#include "../include/datastructs.h"
#include "../include/main.h"
using namespace std;

BlockchainStack::BlockchainStack() : top(nullptr) {}

void BlockchainStack::push(Applicant* block) {
    block->next = top;
    top = block;
}

Applicant* BlockchainStack::pop() {
    if (!top) return nullptr;

    Applicant* temp = top;
    top = top->next;
    temp->next = nullptr;
    return temp;
}

Applicant* BlockchainStack::peek() {
    return top;
}

bool BlockchainStack::isEmpty() {
    return top == nullptr;
}

void BlockchainStack::display() {
    Applicant* curr = top;
    while (curr) {
        cout << "Hash: " << curr->hash << endl;
        cout << "Prev: " << curr->previousHash << endl;
        cout << "Student No.: " << curr->studentID << endl;
        cout << "Grant: " << curr->grant << endl;
        cout << "----------------------\n";
        curr = curr->next;
    }
}
