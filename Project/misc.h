#pragma once

#ifndef misc_h
#define misc_h

#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>

using namespace std;


string getPassword() {
    string password;
    char ch;
    ch = _getch();
    while(ch != 13) { // character 13 is enter
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    return password;
}

void processing(string message = " ", string done = "", bool good = true) {
    if (good) {
        cout << "\033[92m";
    } else {
        cout << "\033[91m";
    }

    cout << message << endl;
    for (int i = 0; i < 10; i++) {
        cout << "██";
        Sleep(50);
    }
    cout << done << endl;

    cout << "\033[0m";
}

#endif
