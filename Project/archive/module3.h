#pragma once

#ifndef module3_h
#define module3_h


#include <iostream>
#include <string>

#include "module1.h"
#include "module2.h"

using namespace std;

class Flight {
private:
    int id;
    Airport* source;
    Airport* destination;
    Plane* plane;
public:
    Flight() {
        id = 0;
        source = NULL;
        destination = NULL;
    }
    Flight(int id, Airport* source, Airport* destination, Plane* plane) {
        this->id = id;
        this->source = source;
        this->destination = destination;
        this->plane = plane;
    }
    // Setters
    void setId(int id) {
        this->id = id;
    }
    void setSource(Airport& source) {
        this->source = &source;
    }
    void setDestination(Airport& destination) {
        this->destination = &destination;
    }
    void setPlane(Plane& plane) {
        this->plane = &plane;
    }
    // Getters
    int getId() {
        return id;
    }
    Airport* getSource() {
        return source;
    }
    Airport* getDestination() {
        return destination;
    }
    Plane* getPlane() {
        return plane;
    }
    // Methods
    void display() {
        cout << "Flight ID: " << id << endl;
        cout << "Source: " << source->getName() << endl;
        cout << "Destination: " << destination->getName() << endl;
        cout << "Plane: " << plane->getName() << endl;
    }
};

#endif