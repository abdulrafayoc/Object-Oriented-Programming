#pragma once

#ifndef menu_h
#define menu_h

#include "classes.h"
#include "misc.h"
#include "users.h"
#include <iostream>
#include <string>

using namespace std;



void loginSignup(Passanger* passangers, Admin* admins) {
    cout << "\033[94m 1: \033[0m Login as Passanger" << endl;
    cout << "\033[94m 2: \033[0m Sign up as Passanger" << endl;

    cout << "\033[94m 3: \033[0m Login as Admin" << endl;
    cout << "\033[94m 4: \033[0m Sign up as Admin" << endl;

    cout << "\033[31m 5: \033[0m Back" << endl;

    int choice;
    cout << " Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        passLogin(passangers);
        break;
    case 2:
        passSignup(passangers);
        break;
    case 3:
        adminLogin(admins);
        break;
    case 4:
        adminSignup(admins);
        break;
    case 5:
        return;
        break;
    default:
        return;
        break;
    }
}

void browseFlights(Flight* flights) {
    cout << "\033[94m 1: \033[0m Browse Local Flights" << endl;
    cout << "\033[94m 2: \033[0m Browse International Flights" << endl;
    
    cout << "\033[31m 3: \033[0m Back" << endl;

    int choice;
    cout << " Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        for (int i = 0; i < flights->num; i++) {
            if (flights[i].getType() == 'L') {
                flights[i].display();
            }
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < flights->num; i++) {
            if (flights[i].getType() == 'I') {
                flights[i].display();
            }
        }
    }
    else if (choice == 3) {
        return;
    }
    else {
        return;
    }
}
void mainMenu(Passanger* passangers, Admin* admins, Flight* flights ) {
    
    cout << "\033[94m 1: \033[0m Browse Flights" << endl;
    cout << "\033[94m 2: \033[0m Login/Signup" << endl;
    cout << "\033[31m 3: \033[0m Exit" << endl;

    int choice;
    cout << " Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        browseFlights(flights);
        break;
    case 2:
        loginSignup(passangers, admins);
        break;
    case 3:
        exit(0);
        break;
    default:
        return;
    }
}


#endif