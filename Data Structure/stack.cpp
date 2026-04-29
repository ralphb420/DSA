// STACK
#pragma once
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

// ─────────────────────────────────────────
// BLOCK NODE — Blockchain record
// Each approved applicant becomes a Block
// pushed chronologically onto the stack
// ─────────────────────────────────────────
struct Block {
    // Block header (simulated blockchain fields)
    string hash;
    string previousHash;
    string timeStamp;

    // Block payload (scholarship grant data)
    int    grant;
    string recipientName;
    string studentID;

    Block* next;   // points to block below it on the stack

    Block(string prevHash, int g, string recipient, string id)
        : previousHash(prevHash), grant(g),
          recipientName(recipient), studentID(id), next(nullptr) {
        // Timestamp
        time_t now = time(0);
        char   buf[64];
        strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&now));
        timeStamp = string(buf);

        // Simulated hash (replace with SHA-256 for production)
        hash = "BLK-" + id + "-" + to_string(g) + "-" + to_string(now);
    }
};

// ─────────────────────────────────────────
// BLOCK STACK — Immutable ledger
// Records approved scholarship grants
// LIFO: newest block is always on top
// Chain integrity: each block references
//   the hash of the block below it
// ─────────────────────────────────────────
struct BlockStack {
    Block* top;
    int    size;

    BlockStack() : top(nullptr), size(0) {}

    // Push a new approved grant onto the blockchain
    void push(int grant, string name, string id) {
        string prevHash = top ? top->hash : "0000-GENESIS";
        Block* newBlock = new Block(prevHash, grant, name, id);
        newBlock->next  = top;
        top             = newBlock;
        size++;
        cout << "[CHAIN] Block pushed: " << newBlock->hash
             << " | Recipient: " << name
             << " | Grant: P" << grant << "\n";
    }

    // Pop the most recent block (undo / rollback)
    Block* pop() {
        if (!top) {
            cout << "[CHAIN] Blockchain is empty.\n";
            return nullptr;
        }
        Block* temp = top;
        top  = top->next;
        size--;
        cout << "[CHAIN] Block popped: " << temp->hash << "\n";
        return temp;
    }

    // Peek at the top block without removing
    Block* peek() { return top; }

    bool isEmpty() { return top == nullptr; }

    // Display the full blockchain ledger (top → genesis)
    void display() {
        cout << "\n=== BLOCKCHAIN LEDGER ===\n";
        if (isEmpty()) { cout << "  [no blocks yet]\n"; return; }
        Block* curr  = top;
        int    index = size;
        while (curr) {
            cout << "  Block #" << index-- << "\n"
                 << "    Hash     : " << curr->hash        << "\n"
                 << "    Prev Hash: " << curr->previousHash << "\n"
                 << "    Timestamp: " << curr->timeStamp    << "\n"
                 << "    Recipient: " << curr->recipientName
                 <<               " (" << curr->studentID << ")\n"
                 << "    Grant    : P" << curr->grant       << "\n"
                 << "    ─────────────────────────────\n";
            curr = curr->next;
        }
        cout << "  Total blocks: " << size << "\n";
    }

    // Verify chain integrity: each block's previousHash must match
    // the hash of the block below it
    bool verifyChain() {
        cout << "\n=== CHAIN INTEGRITY CHECK ===\n";
        if (!top) { cout << "  Chain is empty.\n"; return true; }
        Block* curr  = top;
        bool   valid = true;
        while (curr->next) {
            if (curr->previousHash != curr->next->hash) {
                cout << "  [TAMPERED] Block " << curr->hash
                     << " has invalid previousHash!\n";
                valid = false;
            }
            curr = curr->next;
        }
        if (valid) cout << "  [OK] Chain integrity verified. " << size << " block(s) intact.\n";
        return valid;
    }

    // Compute total budget disbursed (recursion)
    int totalDisbursed(Block* curr = nullptr, bool init = true) {
        if (init) curr = top;
        if (!curr) return 0;
        return curr->grant + totalDisbursed(curr->next, false);
    }

    ~BlockStack() {
        while (top) {
            Block* temp = top;
            top = top->next;
            delete temp;
        }
    }
};