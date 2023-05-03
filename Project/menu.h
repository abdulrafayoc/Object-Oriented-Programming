#pragma once

#ifndef menu_h
#define menu_h

#include <iostream>
#include <string>

using namespace std;





void loginSignup() {
    cout << "\033[94m 1: \033[0m Login" << endl;
    cout << "\033[94m 2: \033[0m Signup" << endl;
    cout << "\033[31m 3: \033[0m Back" << endl;

    int choice;
    cout << " Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        // login();
        break;
    case 2:
        // signup();
        break;
    case 3:
        // mainMenu();
        break;
    }
}


void mainMenu(Passanger passangers, ) {
    
    cout << "\033[94m 1: \033[0m Browse Flights" << endl;
    cout << "\033[94m 2: \033[0m Login/Signup" << endl;
    cout << "\033[31m 3: \033[0m Exit" << endl;

    int choice;
    cout << " Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        loginSignup();
        break;
    case 2:
        // registerUser();
        break;
    case 3:
        exit(0);
        break;
    }
}
#endif