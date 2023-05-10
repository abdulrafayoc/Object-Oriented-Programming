#pragma once

#ifndef menu
#define menu

#include "classes.h"
#include "misc.h"
#include "users.h"
#include <iostream>
#include <string>

using namespace std;



void loginSignup(Passanger* passangers, Admin* admins, Flight* flights, Airport* airports, Plane* planes) {
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
        processing("Opening Passanger Login Menu", "Done", true);
        passLogin(passangers, flights);
        break;
    case 2:
        processing("Opening Passanger Signup Menu", "Done", true);
        passSignup(passangers, flights);
        break;
    case 3:
        processing("Opening Admin Login Menu", "Done", true);
        adminLogin(admins, flights, passangers, airports, planes);
        break;
    case 4:
        processing("Opening Admin Signup Menu", "Done", true);
        adminSignup(admins, flights, passangers, airports, planes);
        break;
    case 5:
        processing("Going back...", "Done", true);
        return;
        break;
    default:
        processing("Going back...", "Done", true);
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
        processing("Browsing Local Flights", "Done", true);
        for (int i = 0; i < flights->num; i++) {
            if (flights[i].getType() == 'L') {
                flights[i].display();
            }
        }
    }
    else if (choice == 2) {
        processing("Browsing International Flights", "Done", true);
        for (int i = 0; i < flights->num; i++) {
            if (flights[i].getType() == 'I') {
                flights[i].display();
            }
        }
    }
    else if (choice == 3) {
        processing("Going back...", "Done", true);
        return;
    }
    else {
        processing("Going back...", "Done", true);
        processing("Going back...", "Done", true);
        return;
    }
}

void mainMenu(Passanger* passangers, Admin* admins, Flight* flights, Airport* airports, Plane* planes) {
    
    cout << "\033[94m 1: \033[0m Browse Flights" << endl;
    cout << "\033[94m 2: \033[0m Login/Signup" << endl;
    cout << "\033[31m 3: \033[0m Exit" << endl;

    int choice;
    cout << " Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        processing("Browsing Flights", "Done", true);
        browseFlights(flights);
        mainMenu(passangers, admins, flights, airports, planes);
        break;
    case 2:
        processing("Opening Logging in/Signing up Menu", "Done", true);
        loginSignup(passangers, admins, flights, airports, planes);
        mainMenu(passangers, admins, flights, airports, planes);
        break;
    case 3:
        processing("Exiting...", "Done", true);
        exit(0);
        break;
    default:
        processing("Exiting...", "Done", true);
        return;
    }
}


#endif