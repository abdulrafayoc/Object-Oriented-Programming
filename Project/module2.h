#pragma once

#ifndef module2_h
#define module2_h

#include <iostream>
#include <string>

using namespace std;

class Plane {
private:
    string name;
    string model;
    int capacity;
public:
    Plane() {
        name = "";
        model = "";
        capacity = 50;
    }
    Plane(string name, string model, int capacity) {
        this->name = name;
        this->model = model;
        this->capacity = capacity;
    }
    // Setters
    void setName(string name) {
        this->name = name;
    }
    void setModel(string model) {
        this->model = model;
    }
    void setCapacity(int capacity)
    {
        this->capacity = capacity;
    }
    // Getters
    string getName()
    {
        return name;
    }
    string getModel()
    {
        return model;
    }
    int getCapacity()
    {
        return capacity;
    }
    // Methods
    void display() {
        cout << "Plane Name: " << name << endl;
        cout << "Model: " << model << endl;
        cout << "Capacity: " << capacity << endl;
    }
    
};

class Airport {
private:
    string name;
    string location;
    Plane* planes;
    int filled;
public:
    // Constructors
    Airport() {
        this->name = "";
        this->location = "";
        this->filled = 0;
        planes = new Plane[5];
    }
    Airport(string name, string location) {
        this->name = name;
        this->location = location;
        this->filled = 0;
    }
    // Setters
    void setName(string name) {
        this->name = name;
    }
    void setLocation(string location) {
        this->location = location;
    }
    // Getters
    string getName() {
        return this->name;
    }
    string getLocation() {
        return this->location;
    }
    // Methods
    void display() {
        cout << "Airport Name: " << name << endl;
        cout << "Location: " << location << endl;
    }
    void addPlane(Plane& plane) {
        for (int i = 0; i < 5; i++) {
            if (planes[i].getName() == "") {
                planes[i] = plane;
                break;
            }
        }
    }
    void displayPlanes() {
        for (int i = 0; i < 5; i++) {
            cout << "Plane " << i + 1 << endl;
            planes[i].display();
        }
    }
    

};


#endif