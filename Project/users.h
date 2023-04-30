#pragma once

#ifndef users.h
#define users.h

#include <iostream>
#include <string>

using namespace std;

void passLogin() {
    string username, password;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if(checkPassanger(username)) {
        if(checkPassword(username, password)) {
            processing("Loging in...", "Welcome!", true);
            // passangerMenu();
        } else {
            processing("Incorrect password!", "Try again", false);
            passLogin();
        }
    } 
    else {
        processing("User not found!", "Try again", false);
        passLogin();
    }
}

void passSignup() {
    string name, username, password;
    cout << " Enter name: ";
    cin >> name;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if(checkPassanger(username)) {
        processing("Checking...", "Username already exists!", false);
        cout << " Do you want to login? (y/n): ";
        
        char choice;
        cin >> choice;

        if(choice == 'y' || choice == 'Y') {
            passLogin();
        }
        else if (choice == 'n' || choice == 'N'){
            passSignup();
        }
        else {
            cout << "Invalid choice!" << endl;
            passSignup();
        }
    } 
    else {
        int cnic;
        do {
            cout << " Enter 13-digit CNIC: ";
            cin >> cnic;
            if(cnic < 1000000000000 || cnic > 9999999999999) {
                cout << " Invalid CNIC!" << endl;
            }
        } while(cnic < 1000000000000 || cnic > 9999999999999);

        int passId;
        do {
            cout << " Enter 10-digit passport ID: ";
            cin >> passId;
            if(passId < 1000000000 || passId > 9999999999) {
                cout << " Invalid passport ID!" << endl;
            }
        } while(passId < 1000000000 || passId > 9999999999);

        Passanger pass(name, username, password, cnic);
        addPassanger(pass);


        processing("Signing up...", "Welcome!", true);
        // passangerMenu();
    }
}

void adminLogin() {
    string username, password;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if(checkAdmin(username)) {
        if(checkAdminPassword(username, password)) {
            processing("Loging in...", "Welcome!", true);
            // adminMenu();
        } else {
            processing("Incorrect password!", "Try again", false);
            adminLogin();
        }
    } 
    else {
        processing("User not found!", "Try again", false);
        adminLogin();
    }
}

void adminSignup() {
    string name, username, password;
    cout << " Enter name: ";
    cin >> name;
    cout << " Enter username: ";
    cin >> username;
    cout << " Enter password: ";
    password = getPassword();

    if(checkAdmin(username)) {
        processing("Checking...", "Username already exists!", false);
        cout << " Do you want to login? (y/n): ";
        
        char choice;
        cin >> choice;

        if(choice == 'y' || choice == 'Y') {
            adminLogin();
        }
        else if (choice == 'n' || choice == 'N'){
            adminSignup();
        }
        else {
            cout << "Invalid choice!" << endl;
            adminSignup();
        }
    } 
    else {
        cout << " Enter Role: ";
        string role;
        cin >> role;

        Admin admin(name, username, password, role);
        addAdmin(admin);

        processing("Signing up...", "Welcome!", true);
        // adminMenu();
    }
}


void loginSignup() {
    cout << "\033[94m 1: \033[0m Login" << endl;
    cout << "\033[94m 2: \033[0m Signup" << endl;
    cout << "\033[31m 3: \033[0m Back" << endl;

    int choice;
    cout << " Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        login();
        break;
    case 2:
        // signup();
        break;
    case 3:
        mainMenu();
        break;
    }
}

#endif
