#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "include/main.h"
#include "include/datastructs.h"
using namespace std;

// BLOCK NODE
struct block {
    // SIMULATED BLOCK HEADER
    string hash; // OVERALL HASHED TRANSACTION OF THE BLOCK
    string timeStamp;
    string previousHash; //

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
    cout << "7: Exit Program" << endl;
    cout << "Choice (1 - 6): ";
    cin >> choice;
    return choice;

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
        case 7: 
            cout << "Exiting ScholarChain. Goodbye!" << endl;
            return true;
        default:
            cout << "Please choose from (1 - 7) only." << endl;
            break;
    }
    return false;
};

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

