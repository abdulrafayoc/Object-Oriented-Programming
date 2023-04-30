#pragma once

#ifndef module1_h
#define module1_h

#include <iostream>
#include <string>

using namespace std;


class User {
private:
    string name;
    string username;
    string password;

public:
    User() {
        name = "";
        username = "";
        password = "";
    }
    User(string name, string username, string password) {
        this->name = name;
        this->username = username;
        this->password = password;
    }
    // Getters
    string getName() {
        return name;
    }
    string getUsername() {
        return username;
    }
    string getPassword() {
        return password;
    }
    // Setters
    void setName(string name) {
        this->name = name;
    }
    void setUsername(string username) {
        this->username = username;
    }
    void setPassword(string password) {
        this->password = password;
    }
    // Methods
    void display() {
        cout << "Name: " << name << endl;
        cout << "Username: " << username << endl;
        cout << "Password: " << password << endl;
    }

};

class Passanger : public User {
private:
    long long int cnic;
    Passport passport;    
    //payment
public:
    Passanger() {
        cnic = 0;

    }
    Passanger(string name, string username, string password, long long int cnic, int id = 0, string country = "") : User(name, username, password) {
        this->cnic = cnic;
        passport.setId(id);
        passport.setCountry(country);
    }
    // Getters
    int getCnic() {
        return cnic;
    }
    // Setters
    void setCnic(long int cnic) {
        this->cnic = cnic;
    }
    // Functions
    void setPassport(int id, string country) {
        passport.setId(id);
        passport.setCountry(country);
    }
    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Username: " << getUsername() << endl;
        cout << "Password: " << getPassword() << endl;
        cout << "CNIC: " << cnic << endl;
        passport.display();
    }
    

};

class Admin : public User {
private:
    string role;
public:
    Admin() {
        role = "";
    }
    Admin(string name, string username, string password, string role) : User(name, username, password) {
        this->role = role;
    }
    // Getters
    string getRole() {
        return role;
    }
    // Setters
    void setRole(string role) {
        this->role = role;
    }
    // Functions
    void display() {
        cout << "Name: " << getName() << endl;
        cout << "Username: " << getUsername() << endl;
        cout << "Password: " << getPassword() << endl;
        cout << "Role: " << role << endl;
    }
};

class Passport {
private:
    int id;
    string country;
public:
    Passport () {
        id = 0;
        country = "";
    }
    Passport(int id, string country) {
        this->id = id;
        this->country = country;
    }
    // Getters
    int getId() {
        return id;
    }
    string getCountry() {
        return country;
    }
    // Setters
    void setId(int id) {
        this->id = id;
    }
    void setCountry(string country) {
        this->country = country;
    }
    // Functions
    void display() {
        cout << "Passport ID: " << id << endl;
        cout << "Country: " << country << endl;
    }

};

bool checkPassanger(string username) {
    int size = sizeof(passangers) / sizeof(passangers[0]);

    for (int i = 0; i < size; i++) {
        if (passangers[i].getUsername() == username) {
            return true;
        }
    }

    return false;
}

bool checkPassangerPassword(string username, string password) {
    int size = sizeof(passangers) / sizeof(passangers[0]);

    for (int i = 0; i < size; i++) {
        if (passangers[i].getUsername() == username && passangers[i].getPassword() == password) {
            return true;
        }
    }

    return false;
}

void addPassanger(Passanger pass) {
    int size = sizeof(passangers) / sizeof(passangers[0]);

    Passanger* temp = new Passanger[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = passangers[i];
    }

    temp[size] = pass;
    delete[] passangers;
    passangers = temp;
}


bool checkAdmin(string username) {
    int size = sizeof(admins) / sizeof(admins[0]);

    for (int i = 0; i < size; i++) {
        if (admins[i].getUsername() == username) {
            return true;
        }
    }

    return false;
}

bool checkAdminPassword(string username, string password) {
    int size = sizeof(admins) / sizeof(admins[0]);

    for (int i = 0; i < size; i++) {
        if (admins[i].getUsername() == username & admins[i].getPassword() == password) {
            return true;
        }
    }

    return false;
}

void addAdmin(Admin adm) {
    int size = sizeof(admins) / sizeof(admins[0]);

    Admin* temp = new Admin[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = admins[i];
    }

    temp[size] = adm;
    delete[] admins;
    admins = temp;
}



#endif