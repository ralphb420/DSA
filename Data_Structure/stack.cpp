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
        cout << "Timestamp: " << curr->timeStamp << endl;
        cout << "Student No.: " << curr->studentID << endl;
        cout << "Grant: " << curr->grant << endl;
        cout << "----------------------\n";
        curr = curr->next;
    }
}

static bool validateChainRecursive(Applicant* curr, Applicant* prev) {
    if (curr == nullptr) return true;
 
    bool restValid = validateChainRecursive(curr->next, curr);
 
    string recomputed = createHash(curr->timeStamp,
                                   curr->previousHash,
                                   curr->grant,
                                   curr->name);
 
    bool hashOk = (recomputed == curr->hash);
 
    if (!hashOk) {
        cout << "[TAMPERED] Block " << curr->studentID
             << " has an invalid hash!\n"
             << "  Stored   : " << curr->hash      << "\n"
             << "  Expected : " << recomputed       << "\n";
    }
 
    bool linkOk = true;
    if (prev != nullptr) {
        linkOk = (prev->previousHash == curr->hash);
        if (!linkOk) {
            cout << "[BROKEN LINK] Block " << prev->studentID
                 << " does not correctly reference block "
                 << curr->studentID << "!\n"
                 << "  prev->previousHash : " << prev->previousHash << "\n"
                 << "  curr->hash         : " << curr->hash          << "\n";
        }
    }
 
    return hashOk && linkOk && restValid;
}
bool BlockchainStack::validateChain() {
    cout << "Checking BlockChain Integrity" << endl;;
 
    if (isEmpty()) {
        cout << "Chain is empty. Nothing to validate." << endl;
        return true;
    }
 
    bool valid = validateChainRecursive(top, nullptr);
 
    if (valid)
        cout << "Result: Chain is VALID. No tampering detected.\n";
    else
        cout << "Result: Chain is INVALID. Tampering detected!\n";
 
    return valid;
}

