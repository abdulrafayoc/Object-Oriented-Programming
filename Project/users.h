#pragma once

#ifndef users
#define users

#include "classes.h"
#include "misc.h"
#include <iostream>
#include <string>

using namespace std;


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
    // cout << "size " << size << endl;

    Passanger* temp = new Passanger[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = passangers[i];
    }

    // cout << "size " << size << endl;

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
    int size = admins->num - 1;

    Admin* temp = new Admin[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = admins[i];
    }

    temp[size] = adm;
    admins = temp;
    admins->num++;
    return temp;
}


void passLogin(Passanger* passangers) {
    string username, password;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if(checkPassanger(username, passangers)) {
        if(checkPassangerPassword(username, password, passangers)) {
            processing("Loging in...", "Welcome!", true);
            // passangerMenu();
        } else {
            processing("Incorrect password!", "Try again", false);
            passLogin(passangers);
        }
    } 
    else {
        processing("User not found!", "Try again", false);
        passLogin(passangers);
    }
}

void passSignup(Passanger* passangers) {
    string name, username, password;
    cout << " Enter name: ";
    cin >> name;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if(checkPassanger(username, passangers)) {
        processing("Checking...", "Username already exists!", false);
        cout << " Do you want to login? (y/n): ";
        
        char choice;
        cin >> choice;

        if(choice == 'y' || choice == 'Y') {
            passLogin(passangers);
        }
        else if (choice == 'n' || choice == 'N'){
            passSignup(passangers);
        }
        else {
            cout << "Invalid choice!" << endl;
            passSignup(passangers);
        }
    } 
    else {
        long long int cnic;
        do {
            cout << " Enter 13-digit CNIC: ";
            cin >> cnic;
            if(cnic < 1000000000000 || cnic > 9999999999999) {
                cout << " Invalid CNIC!" << endl;
            }
        } while(cnic < 1000000000000 || cnic > 9999999999999);

        long long int passId;
        do {
            cout << " Enter 10-digit passport ID: ";
            cin >> passId;
            if(passId < 1000000000 || passId > 9999999999) {
                cout << " Invalid passport ID!" << endl;
            }
        } while(passId < 1000000000 || passId > 9999999999);
        
        Passanger pass(name, username, password, cnic);
        addPassanger(pass, passangers);


        processing("Signing up...", "Welcome!", true);
        // passangerMenu();
    }
}


void adminLogin(Admin* admins) {
    string username, password;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if(checkAdmin(username, admins)) {
        if(checkAdminPassword(username, password, admins)) {
            processing("Loging in...", "Welcome!", true);
            // adminMenu();
        } else {
            processing("Incorrect password!", "Try again", false);
            adminLogin(admins);
        }
    } 
    else {
        processing("User not found!", "Try again", false);
        adminLogin(admins);
    }
}

void adminSignup(Admin* admins) {
    string name, username, password;
    cout << " Enter name: ";
    cin >> name;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if(checkAdmin(username, admins)) {
        processing("Checking...", "Username already exists!", false);
        cout << " Do you want to login? (y/n): ";
        
        char choice;
        cin >> choice;

        if(choice == 'y' || choice == 'Y') {
            adminLogin(admins);
        }
        else if (choice == 'n' || choice == 'N'){
            adminSignup(admins);
        }
        else {
            cout << "Invalid choice!" << endl;
            adminSignup(admins);
        }
    } 
    else {
        cout << " Enter Role: ";
        string role;
        cin >> role;

        Admin adm(name, username, password, role);
        addAdmin(adm, admins);

        processing("Signing up...", "Welcome!", true);
        // adminMenu();
    }
}


#endif
