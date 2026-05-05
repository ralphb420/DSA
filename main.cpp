#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "include/main.h"
#include "include/datastructs.h"
using namespace std;

int printMenu();
bool switchMenu(int choice);
int budget;

int main() {
    bool connection = true;
    while (!connection) { // WIP
        try {
            cout << "Establishing Connection";
            connection = true;
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
    cout << "ScholarChain Menu:" << endl;
    cout << "1: Process Scholarship" << endl;
    cout << "2: Show Transactions" << endl;
    cout << "3: Show WaitList" << endl;
    cout << "4: Show Remaining Budget" << endl;
    cout << "5: Sort Transaction" << endl;
    cout << "6: Verify Transaction Integrity" << endl;
    cout << "7: Add Budget" << endl;
    cout << "8: Exit Program" << endl;

    try {
        cout << "Choice (1 - 7): ";
        cin >> choice;
    } catch (const exception& e) {
        cout << "Please choose from (1 - 7) only!" << endl;
    }
    return choice;
}

bool switchMenu(int choice) {
    switch (choice) {
        case 1: processScholarship();
            break;
        case 2: showTransactions();
            break;
        case 3: showWaitlist();
            break;
        case 4: showRemainingBudget();
            break;
        case 5: sortTransactions();
            break;
        case 6: verifyTransactionIntegrity();
            break;
        case 7: addBudget();
            break;
        case 8: 
            cout << "Exiting ScholarChain. Goodbye!" << endl;
            return true;
        default:
            cout << "Please choose from (1 - 7) only." << endl;
            break;
    }
    return false;
};

// CASE 1 - PROCESS SCHOLARSHIP

void processScholarship() {

}

// CASE 2 - SHOW TRANSACTION BLOCK

void showTransactions() {
    
}

// CASE 3 - SHOW WAITLIST

void showWaitlist() {
    
}

// CASE 4 - SHOW REMAINING BUDGET

void sortTransactions() {
    
}

// CASE 5 - SORT TRANSACTIONS

void showRemainingBudget() {
    
}

// CASE 6 VERIFY TRANSACTION INTEGRITY

void verifyTransactionIntegrity() {
    
}

// CASE 7 - ADD BUDGET
void addBudget() {
    try {
        cout << "Total Budget: " << budget << endl;
        cout << "Add Budget: ";
        cin >> budget;
    } catch (const exception& e) {
        cout << "Error: " << e << endl;
    }
}
