// STACK
#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include "include/datastructs.h"
#include "include/main.h"
using namespace std;


class BlockchainStack {
private:
    Applicant* top;

public:
    BlockchainStack() : top(nullptr) {}

    void push(Applicant* block) {
        block->next = top;
        top = block;
    }

    Applicant* pop() {
        if (!top) return nullptr;

        Applicant* temp = top;
        top = top->next;
        temp->next = nullptr;
        return temp;
    }

    Applicant* peek() {
        return top;
    }

    void display() {
        Applicant* curr = top;
        while (curr) {
            cout << "Hash: " << curr->hash << endl;
            cout << "Prev: " << curr->previousHash << endl;
            cout << "Name: " << curr->name << endl;
            cout << "----------------------\n";
            curr = curr->next;
        }
    }
};