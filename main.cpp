#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "include/main.h"
#include "include/datastructs.h"
using namespace std;

int printMenu();
bool switchMenu(int choice);

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
    cout << "7: Exit Program" << endl;

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
            break;
    }
    return false;
}


