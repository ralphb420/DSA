#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <cctype>
#include "include/main.h"
#include "include/datastructs.h"
using namespace std;

int printMenu();
bool switchMenu(int choice);
int budget;
int budgetUsed;

void processScholarship();
void pushQueue();
void showTransactions();
void showQueue();
void sortTransactions();
void showRemainingBudget();
void verifyTransactionIntegrity();
void addBudget();

PriorityQueue priorityq;
DualQueue queue;
BlockchainStack blockchain;

int main() {
    cout << "Establishing Connection..." << endl;
    cout << "Welcome Admin!\n" << endl;
    
    bool connection = false;
    while (!connection) { // WIP
        try {
            int choice;
            cout << "Please set budget before processing!" << endl;
            cout << "Budget: ";
            
            // Input Error Capture
            if (!(cin >> choice)) {
                cin.clear();
                string invalidInput;
                cin >> invalidInput;
                cout << "Invalid input. Please enter a valid integer." << endl;

            } else {
                if (choice <= 0) {
                    cout << "Budget must be positive." << endl;
                    choice = 0;
                } else {
                    budget = choice;
                    connection = true;
                }
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    bool exitProgram = false;
    while (!exitProgram) {
        exitProgram = switchMenu(printMenu());
    }

    return 0;
}

int printMenu() {
    int choice = 0;
    cout << "\nScholarChain Menu:" << endl;
    cout << "1: Process Scholarship" << endl;
    cout << "2: Push Queue to BlockChain" << endl;
    cout << "3: Show Transactions" << endl;
    cout << "4: Show Queue" << endl;
    cout << "5: Show Remaining Budget" << endl;
    cout << "6: Sort Transaction" << endl;
    cout << "7: Verify Transaction Integrity" << endl;
    cout << "8: Add Budget" << endl;
    cout << "9: Exit Program" << endl;

    try {
        cout << "Choice (1 - 9): ";
        cin >> choice;
    } catch (const exception& e) {
        cout << "Please choose from (1 - 9) only!" << endl;
    }
    return choice;
}

bool switchMenu(int choice) {
    switch (choice) {
        case 1: 
            cout << endl;
            processScholarship();
            break;
        case 2: 
            cout << endl;
            pushQueue();
            break;
        case 3: 
            cout << endl;
            blockchain.display();
            break;
        case 4: 
            cout << endl;
            showQueue();
            break;
        case 5: 
            cout << endl;
            showRemainingBudget();
            break;
        case 6: 
            cout << endl;
            sortTransactions();
            break;
        case 7: 
            cout << endl;
            verifyTransactionIntegrity();
            break;
        case 8: 
            cout << endl;
            addBudget();
            break;
        case 9: 
            cout << endl;
            cout << "Exiting ScholarChain. Goodbye!" << endl;
            return true;
        default:
            cout << "Please choose from (1 - 9) only." << endl;
            break;
    }
    return false;
};

// CASE 1 - PROCESS SCHOLARSHIP

void processScholarship() {
    string id; 
    string name;
    float gpa;
    float income;
    bool priority;
    int grant;
    
    try {
        cout << "\nProcessing Scholarships" << endl;
        cout << "Enter Student ID Number: ";
        cin >> id;

        cin.ignore(1);
        cout << "Enter Student Name: ";
        getline(cin, name);
    } catch (const exception& e) {
        cout << "Please enter text only!" << endl;
    }

    try {
        cout << "Enter Student GPA: ";
        cin >> gpa;

        cin.ignore(1);
        cout << "Enter Student/Family Income: ";
        cin >> income;

        cout << "Enter Scholarship Grant: ";
        cin >> grant;
    } catch (const exception& e) {
        cout << "Please enter numbers only!" << endl;
    }

    Applicant* applicant = new Applicant(id, name, gpa, income);
    applicant->grant = grant;

    if (applicant->isHighPriority) {
        cout << "Applicant is queued for the priority queue." << endl;
        priorityq.insert(applicant);
    } else if (budget <= 0) {
        cout << "Applicant is queued for the waitlist queue." << endl;
        queue.enqueueWaitlist(applicant);
    } else {
        cout << "Applicant is queued for the normal queue." << endl;
        queue.enqueueMain(applicant);
    }

    try {
        char choice;
        cout << "\nWould you like to process another? (Y/N): ";
        cin >> choice;

        switch((char)tolower(choice)) {
            case 'y':
                processScholarship();
                break;
            case 'n':
                break;
            default:
                cout << "Please choose from Y or N" << endl;
                break;
        }
    } catch (const exception& e) {
        cout << "Error" << e.what() << endl;
    }
}

// CASE 2 - PUSH QUEUE TO BLOCKCHAIN

void pushToBlockchain(Applicant* a, BlockchainStack& chain) {
    a->timeStamp = getTimeStamp();

    if (chain.peek() == nullptr) {
        a->previousHash = "";
    } else {
        a->previousHash = chain.peek()->hash;
    }

    a->hash = createHash(a->timeStamp, a->previousHash, a->grant, a->name);
    chain.push(a);
}

void pushQueue() {
    int totalQueueBudget = (queue.getWaitlistBudget()) + (priorityq.getQueueBudget());
    if(priorityq.isEmpty() == true && queue.isMainEmpty() == true && queue.isWaitlistEmpty() == true) {
        cout << "Queues are empty.";
    } else if (totalQueueBudget < budget-budgetUsed) {
        // WAITLIST FIRST IF NOT FIRST BATCH
        while(!queue.isWaitlistEmpty()) {
            Applicant* a = queue.getFirstWaitlist();
            pushToBlockchain(a, blockchain);
            budgetUsed += a->grant;
            queue.dequeueWaitlist();
        }

        // PRIORITY QUEUE FIRST
        while(!priorityq.isEmpty()) {
            Applicant* a = priorityq.getFirst();
            pushToBlockchain(a, blockchain);
            budgetUsed += a->grant;
            priorityq.pop();
        }
        // NORMAL QUEUE
        while(!queue.isMainEmpty()) {
            Applicant* a = queue.getFirst();
            pushToBlockchain(a, blockchain);
            budgetUsed += a->grant;
            queue.dequeueMain();
        }

        cout << "\nSuccessfully Pushed Queues to BlockChain." << endl;
    }
}

// CASE 4 - SHOW QUEUE

void showQueue()
{
    try
    {
        int choice;
        cout << "Please select a Queue:" << endl;
        cout << "[1]: Normal Queue" << endl;
        cout << "[2]: Waitlist Queue" << endl;
        cout << "[3]: Priority Queue" << endl;

        if (!(cin >> choice))
        {
            cin.clear();
            string invalidInput;
            cin >> invalidInput;
            cout << "Invalid input. Please enter a valid integer." << endl;
        }
        else
        {
            switch (choice)
            {
            case 1:
                queue.displayMain();
                break;
            case 2:
                queue.displayWaitlist();
                break;
            default:
                priorityq.displayQueue();
                break;
            }
        }
    }
    catch (const exception &e)
    {
        cout << "Error: " << e.what() << endl;
    }
}

// CASE 5 - SHOW REMAINING BUDGET

void showRemainingBudget() {
    cout << "Total Budget: " << budget << endl;
    cout << "Remaining Budget: " << (budget - budgetUsed) << endl;
}

// CASE 6 - SORT TRANSACTIONS

void sortTransactions() {
    blockchain.display();
}

// CASE 7 VERIFY TRANSACTION INTEGRITY

void verifyTransactionIntegrity() {
    
}

// CASE 8 - ADD BUDGET
void addBudget() {
    int input;
    try {
        cout << "Total Budget: " << budget << endl;
        cout << "Add Budget: ";
        cin >> input;

        if(input <= 0) {
            cout << "Budget must not be 0 or negative" << endl;
        } else {
            budget += input;
        }
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
