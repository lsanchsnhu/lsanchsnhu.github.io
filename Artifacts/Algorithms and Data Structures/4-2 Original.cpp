#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;
string clientData[2][5] = { {"Bob Jones","Sarah Davis","Amy Friendly","Johnny Smith","Carol Spears"},{"1","2","1","1","2"} };


void CheckUserPermissionAccess() {
    cout << "Enter your username : " << endl;
    string user;
    cin >> user;
    cout << "Enter your password : " << endl;
    int pass;
    cin >> pass;
    // this just compares the user input to a hardcoded value that can be found by disassembling the source code
    while (pass != 123) {
        cout << "Invalid Password. Please try again" << endl;
        cin >> pass;
    }
}

void DisplayInfo() {
    cout << "You chose 1\n" << "Client's Name Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
    for (int i = 0; i < 5; i++) {
        cout << clientData[0][i] << " selected option " << clientData[1][i] << endl;
    }
}

void ChangeCustomerChoice() {
    cout << "You chose 2" << endl;
    cout << "Enter the number of client you wish to chang" << endl;
    int client;
    cin >> client;
    cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
    cin >> clientData[1][client - 1];
}

int main() {
    cout << "Hello! Welcome to our Investment Company" << endl;
    cout << "Created by: Luc Sanchez" << endl;
    
    CheckUserPermissionAccess();

    while (1) {
        cout << "What would you like to do?\n" << "DISPLAY the client list(enter 1)\n" << "CHANGE a client's choice(enter 2)\n" << "Exit the program(enter 3)" << endl;
        int option;
        cin >> option;
        switch (option) {
        case 1:
            DisplayInfo();
            break;
        case 2:
            ChangeCustomerChoice();
            break;
        case 3:
            exit(0);
        // this just re-displayed the options if something other than 1, 2, or 3 were picked. Now it explicitly tells you
        // that those are the only options and to try again
        default:
            cout << "Invalid Selection, please choose from 1-3:" << endl;
            break;
        }
    }
    return 0;
}


