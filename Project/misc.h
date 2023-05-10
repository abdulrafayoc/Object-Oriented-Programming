#pragma once

#ifndef misc_h
#define misc_h

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;


bool validatePassword(string password) {
    int n = password.length();
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecialChar = false;
    string specialChars = "!@#$%^&*()-+";
    for (int i = 0; i < n; i++) {
        if (islower(password[i])) {
            hasLower = true;
        }
        else if (isupper(password[i])) {
            hasUpper = true;
        }
        else if (isdigit(password[i])) {
            hasDigit = true;
        }
        else if (specialChars.find(password[i]) != string::npos) {
            hasSpecialChar = true;
        }
    }
    return (n >= 8 && hasLower && hasUpper && hasDigit && hasSpecialChar);
}

string getPassword() {
    string password = "";
    char ch;
    while (true) {
        ch = _getch();
        if (ch == 13 && validatePassword(password)) {
            break;
        } else if (ch == 8) {
            if (password.length() > 0) {
                password.pop_back();
                cout << "\b \b";
            }
        } else if (ch == 32 || ch == 9) {
            continue;
        } else {
            password.push_back(ch);
            cout << "*";
        }
    }
    return password;
}



//string getPassword() {
//    string password;
//    char ch;
//    ch = _getch();
//    while(ch != 13) { // character 13 is enter
//        if(ch == 8) { // character 8 is backspace
//            if(password.length() != 0) {
//                cout << "\b \b";
//                password.resize(password.length() - 1);
//            }
//        }
//        password.push_back(ch);
//        cout << '*';
//        ch = _getch();
//    }
//    return password;
//}

void processing(string message = " ", string done = "", bool good = true) {
    system("cls");
    if (good) {
        cout << "\033[92m";
    } else {
        cout << "\033[91m";
    }

    cout << message << endl;
    for (int i = 0; i < 10; i++) {
        cout << "██";
        Sleep(150);
    }
    
    cout << done << endl;

    cout << "\033[0m";
}

#endif
