#include <iostream>
#include <iomanip>
#include <string>
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

// MENU FUNCTIONS
int printMenu () {
    int choice;
    cout << "ScholarChain Menu:" << endl;
    cout << "1: Process Scholarship" << endl;
    cout << "2: Show Transactions" << endl;
    cout << "3: Show WaitList" << endl;
    cout << "4: Show Remaining Budget" << endl;
    cout << "5: Sort Transaction" << endl;
    cout << "6: Verify Transaction Integrity" << endl;
    cout << "7: Exit Program" << endl;

    try {
        cout << "Choice (1 - 6): ";
        cin >> choice;
        return choice;
    } catch (e) {
        cout << "Please choose from (1 - 6) only!" << endl;
    }
}

bool switchMenu (int choice) {
    switch (choice) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:
            return true;
        default:

    }

}


