#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "include/main.h"
#include "include/datastructs.h"
using namespace std;

<<<<<<< HEAD
// BLOCK NODE
struct block {
    // SIMULATED BLOCK HEADER
    string hash; // OVERALL HASHED TRANSACTION OF THE BLOCK
    string timeStamp;
    string previousHash; //
=======
int printMenu();
bool switchMenu(int choice);
int budget;
>>>>>>> 8d9b10f952cf479b0154c2f5df64e3794f8dff9a

    // BLOCK DATA
    int grant; // "5000"
    string name; // "Ralph Ivan Bituin"
}


// ESTABLISH CONNECTION / -1 DEBUG MODE
bool connection = true;

while (!connection) { // WIP
    try {
        cout << "Establishing Connection";

        connection = true;

    } catch (e) {
        cout << "Error: " << e << endl;
    }
}


// MAIN ENTRY POINT - MENU
bool exit = false;

while(!exit) {
    exit = switchMenu(printMenu);
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
<<<<<<< HEAD
    cout << "7: Exit Program" << endl;
    cout << "Choice (1 - 6): ";
    cin >> choice;
    return choice;
=======
    cout << "7: Add Budget" << endl;
    cout << "8: Exit Program" << endl;
>>>>>>> 8d9b10f952cf479b0154c2f5df64e3794f8dff9a

    try {
        cout << "Choice (1 - 6): ";
        cin >> choice;
        return choice;
    } catch (e) {
        cout << "Please choose from (1 - 6) only!" << endl;
    }
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

<<<<<<< HEAD
int main() {
    // ESTABLISH CONNECTION / -1 DEBUG MODE
bool connection = true;

while (!connection) { // WIP
    try {
        cout << "Establishing Connection";

        connection = true;

    } catch (e) {
        cout << "Error: " << e << endl;
    }
}


// MAIN ENTRY POINT - MENU
bool shouldExit = false;

while(!shouldExit) {
    shouldExit = switchMenu(printMenu);
}
return 0;
}
=======
// CASE 1 - PROCESS SCHOLARSHIP
>>>>>>> 8d9b10f952cf479b0154c2f5df64e3794f8dff9a

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
