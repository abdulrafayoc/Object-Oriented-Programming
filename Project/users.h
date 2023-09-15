#pragma once

#ifndef users
#define users

#include "classes.h"
#include "misc.h"
#include "menu.h"

#include "booking.h"
#include <iostream>
#include <string>

using namespace std;

void adminMenu(Airport* airports, Plane* planes, Flight* flights, Passanger* passangers, Admin* admins) {
    cout << "\033[94m 1: \033[0m Add Airport" << endl;
    cout << "\033[94m 2: \033[0m Add Plane" << endl;
    cout << "\033[94m 3: \033[0m Add Flight" << endl;
    cout << "\033[94m 4: \033[0m Edit Flight" << endl;

    cout << "\033[94m 5: \033[0m View Flights" << endl;
    cout << "\033[94m 6: \033[0m View Airports" << endl;
    cout << "\033[94m 7: \033[0m View Planes" << endl;
    
    cout << "\033[94m 8: \033[0m View Passangers" << endl;
    cout << "\033[94m 9: \033[0m View Admins" << endl;

    cout << "\033[31m 10: \033[0m Back" << endl;

    int choice;

    cout << " Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        processing("Opening Add Airport Menu", "Done", true);
        cout << " Enter Airport Name: ";
        string name;
        cin >> name;
        cout << " Enter city: ";
        string city;
        cin >> city;
        
        Airport air(name, city);
        airports = addAirport(&air, airports);
        processing("Adding Airport...", "Airport added!", true);
        adminMenu(airports, planes, flights, passangers, admins);
    }
    else if (choice == 2) {
        processing("Opening Add Plane Menu", "Done", true);
        cout << " Enter Plane Name: ";
        string name;
        cin >> name;
        cout << " Enter Plane id: ";
        int id;
        cin >> id;

        Plane plane(name, id);
        planes = addPlane(&plane, planes);
        processing("Adding Plane...", "Plane added!", true);
        adminMenu(airports, planes, flights, passangers, admins);
    }
    else if (choice == 3) {
        processing("Opening Add Flight Menu", "Done", true);
        addNewFlight(airports, planes, flights, passangers, admins);
        adminMenu(airports, planes, flights, passangers, admins);
    }
    else if (choice == 4) {
        processing("Opening Edit Flight Menu", "Done", true);
        editFlight(airports, planes, flights, passangers, admins);
        adminMenu(airports, planes, flights, passangers, admins);
    }
    else if (choice == 5) {
        processing("Opening View Flights Menu", "Done", true);
        viewFlights(flights);
        adminMenu(airports, planes, flights, passangers, admins);
    }
    else if (choice == 6) {
        processing("Opening View Airports Menu", "Done", true);
        viewAirports(airports);
        adminMenu(airports, planes, flights, passangers, admins);
    }
    else if (choice == 7) {
        processing("Opening View Planes Menu", "Done", true);
        viewPlanes(planes);
        adminMenu(airports, planes, flights, passangers, admins);
    }
    else if (choice == 8) {
        processing("Opening View Passangers Menu", "Done", true);
        viewPassangers(passangers);
        adminMenu(airports, planes, flights, passangers, admins);
    }
    else if (choice == 9) {
        processing("Opening View Admins Menu", "Done", true);
        viewAdmins(admins);
        adminMenu(airports, planes, flights, passangers, admins);
    }
    else if (choice == 0) {
        processing("Going back...", "Done", true);
        return;
    } else {
        processing("Going back...", "Done", true);
        return;
    }

}

void passangerMenu(Passanger& pass, Flight* flights) {
    cout << "\033[94m 1: \033[0m Book a Flight" << endl;
    cout << "\033[94m 2: \033[0m Cancel a Flight" << endl;

    cout << "\033[94m 3: \033[0m View Booked Flight" << endl;
    cout << "\033[94m 4: \033[0m View Account Details" << endl;
    cout << "\033[94m 5: \033[0m Edit Account Details" << endl;

    cout << "\033[94m 6: \033[0m Add balance" << endl;

    cout << "\033[31m 7: \033[0m Back" << endl;

    int choice;
    cout << " Enter your choice: ";
    cin >> choice;

        int temp;
    switch (choice) {
    case 1:
        processing("Opening Booking Menu", "Done", true);
        bookingMenu(pass, flights);
        passangerMenu(pass, flights);
        break;
    case 2:
        processing("Opening Cancel Menu", "Done", true);
        cancelFlight(pass, flights);
        passangerMenu(pass, flights);
        break;
    case 3:
        processing("Opening View Booked Flights Menu", "Done", true);
        viewBookedFlights(pass, flights);
        passangerMenu(pass, flights);
        break;
    case 4:
        processing("Opening View Account Details Menu", "Done", true);
        pass.display();
        passangerMenu(pass, flights);
        break;
    case 5:
        processing("Opening Edit Account Details Menu", "Done", true);
        pass.editDetails();
        passangerMenu(pass, flights);
        break;
    case 6:
        cout << "enter balance" << endl;
        cin >> temp;
        break;
    case 7:
        return;
        break;
    default:
        return;
        break;
    }
    processing("Going back...", "Done", true);
}

bool checkPassanger(string username, Passanger* passangers) {
    int size = passangers->num;

    for (int i = 0; i < size; i++) {
        if (passangers[i].getUsername() == username) {

            return true;
        }
    }

    return false;
}

bool checkPassangerPassword(string username, string password, Passanger* passangers) {
    int size = passangers->num;

    for (int i = 0; i < size; i++) {
        if (passangers[i].getUsername() == username && passangers[i].getPassword() == password) {
            return true;
        }
    }

    return false;
}

Passanger* addPassanger(Passanger& pass, Passanger* passangers) {
    int size = pass.num;

    Passanger* temp = new Passanger[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = passangers[i];
    }

    temp[size] = pass;
    pass.num++;
    return temp;
}

bool checkAdmin(string username, Admin* admins) {
    int size = admins->num;

    for (int i = 0; i < size; i++) {
        if (admins[i].getUsername() == username) {
            return true;
        }
    }
    return false;
}

bool checkAdminPassword(string username, string password, Admin* admins) {
    int size = admins->num;

    for (int i = 0; i < size; i++) {
        if (admins[i].getUsername() == username && admins[i].getPassword() == password) {
            return true;
        }
    }

    return false;
}

Admin* addAdmin(Admin& adm, Admin* admins) {
    int size = admins->num;

    Admin* temp = new Admin[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = admins[i];
    }

    temp[size] = adm;
    admins->num++;
    return temp;
}

Passanger* getPassanger(string username, Passanger* passangers) {
    int size = passangers->num;

    for (int i = 0; i < size; i++) {
        if (passangers[i].getUsername() == username) {
            return &passangers[i];
        }
    }
    return NULL;
}

void passLogin(Passanger* passangers, Flight* flights) {
    string username, password;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if (checkPassanger(username, passangers)) {
        if (checkPassangerPassword(username, password, passangers)) {
            processing("Loging in...", "Welcome!", true);
            passangerMenu(*getPassanger(username, passangers), flights);
        }
        else {
            processing("Incorrect password!", "Try again", false);
            passLogin(passangers, flights);
        }
    }
    else {
        processing("User not found!", "Try again", false);
        passLogin(passangers, flights);
    }
}

void passSignup(Passanger* passangers, Flight* flights) {
    string name, username, password;
    cout << " Enter name: ";
    cin >> name;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if (checkPassanger(username, passangers)) {
        processing("Checking...", "Username already exists!", false);
        cout << " Do you want to login? (y/n): ";

        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            passLogin(passangers, flights);
        }
        else if (choice == 'n' || choice == 'N') {
            passSignup(passangers, flights);
        }
        else {
            cout << "Invalid choice!" << endl;
            passSignup(passangers, flights);
        }
    }
    else {
        long long int cnic;
        do {
            cout << " Enter 13-digit CNIC: ";
            cin >> cnic;
            if (cnic < 1000000000000 || cnic > 9999999999999) {
                cout << " Invalid CNIC!" << endl;
            }
        } while (cnic < 1000000000000 || cnic > 9999999999999);

        long long int passId;
        do {
            cout << " Enter 10-digit passport ID: ";
            cin >> passId;
            if (passId < 1000000000 || passId > 9999999999) {
                cout << " Invalid passport ID!" << endl;
            }
        } while (passId < 1000000000 || passId > 9999999999);

        Passanger pass(name, username, password, cnic);
        passangers = addPassanger(pass, passangers);


        processing("Signing up...", "Welcome!", true);
        passangerMenu(*getPassanger(username, passangers), flights);
    }
}

void adminLogin(Admin* admins, Flight* flights, Passanger* passangers, Airport* airports, Plane* planes) {
    string username, password;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if (checkAdmin(username, admins)) {
        if (checkAdminPassword(username, password, admins)) {
            processing("Loging in...", "Welcome!", true);
            adminMenu(airports, planes, flights, passangers, admins);
        }
        else {
            processing("Incorrect password!", "Try again", false);
            adminLogin(admins, flights, passangers, airports, planes);
        }
    }
    else {
        processing("User not found!", "Try again", false);
        adminLogin(admins, flights, passangers, airports, planes);
    }
}

void adminSignup(Admin* admins, Flight* flights, Passanger* passangers, Airport* airports, Plane* planes) {
    string name, username, password;
    cout << " Enter name: ";
    cin >> name;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if (checkAdmin(username, admins)) {
        processing("Checking...", "Username already exists!", false);
        cout << " Do you want to login? (y/n): ";

        char choice;
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            adminLogin(admins, flights, passangers, airports, planes);
        }
        else if (choice == 'n' || choice == 'N') {
            adminSignup(admins, flights, passangers, airports, planes);
        }
        else {
            cout << "Invalid choice!" << endl;
            adminSignup(admins, flights, passangers, airports, planes);
        }
    }
    else {
        cout << " Enter Role: ";
        string role;
        cin >> role;

        Admin adm(name, username, password, role);
        admins = addAdmin(adm, admins);

        processing("Signing up...", "Welcome!", true);
        adminMenu(airports, planes, flights, passangers, admins);
    }
}


#endif
