#pragma once

#ifndef booking
#define booking

#include "classes.h"
#include "misc.h"
#include "users.h"
#include "menu.h"
#include <iostream>
#include <string>

using namespace std;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////     ADMIN PORTAL    ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////

Airport* addAirport(Airport* air, Airport* airports) {
    int size = airports->num;

    Airport* temp = new Airport[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = airports[i];
    }

    temp[size] = *air;
    airports->num++;
    return temp;
}

Plane* addPlane(Plane* plane, Plane* planes) {
    int size = planes->num;
    

    Plane* temp = new Plane[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = planes[i];
    }

    temp[size] = *plane;
    planes->num++;
    return temp;
}

Flight* addFlight(Flight* flight, Flight* flights) {
    int size = flights->num;

    Flight* temp = new Flight[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = flights[i];
    }

    temp[size] = *flight;
    flights->num++;
    return temp;
}

Plane* getPlane(int id, Plane* planes) {
    for (int i = 0; i < planes->num; i++) {
        if (planes[i].getId() == id) {
            return &planes[i];
        }
    }
    cout << "Plane not found" << endl;
    return NULL;
}

Airport* getAirport(string name, Airport* airports) {
    for (int i = 0; i < airports->num; i++) {
        if (airports[i].getName() == name) {
            return &airports[i];
        }
    }
    cout << "Airport not found" << endl;
    return NULL;
}

Flight* getFlight(int id, Flight* flights) {
    for (int i = 0; i < flights->num; i++) {
        if (flights[i].getId() == id) {
            return &flights[i];
        }
    }
    cout << "Flight not found" << endl;
    return NULL;
}

void viewAirports(Airport* airports) {
    for (int i = 0; i < airports->num; i++) {
        airports[i].display();
    }
}

void viewFlights(Flight* flights) {
    for (int i = 0; i < flights->num; i++) {
        flights[i].display();
        flights[i].displayTickets(flights[i].getPrice());
    }
}

void viewPlanes(Plane* planes) {
    for (int i = 0; i < planes->num; i++) {
        planes[i].display();
    }
}

void viewPassangers(Passanger* passangers) {
    for (int i = 0; i < passangers->num; i++) {
        passangers[i].display();
    }
}

void viewAdmins(Admin* admins) {
    for (int i = 0; i < admins->num; i++) {
        admins[i].display();
    }
}

void editFlight(Airport* airports, Plane* planes, Flight* flights, Passanger* passangers, Admin* admins) {
    cout << "All Flights:" << endl;
    for (int i = 0; i < flights->num; i++) {
        flights[i].display();
    }

    cout << "Enter Flight Id of flight you want to edit: " << endl;
    int id;
    cin >> id;

    Flight* flight = getFlight(id, flights);    
    if (flight == NULL) {
        processing("Flight not found \n returning ...", "returned", false);
        return;
    }

    cout << "Enter Flight tpye International[I] or Local [L]  (I / L): " << endl;
    char type;
    cin >> type;

    // show airports
    for (int i = 0; i < airports->num; i++) {
        airports[i].display();
    }
    cout << "Enter Flight Source Airport name from above: " << endl;
    string source;
    cin >> source;
    Airport src = *getAirport(source, airports);
    if (&src == NULL) {
        processing("Source Airport not found \n returning ...", "returned", false);
        return;
    }

    cout << "Enter Flight Destination Airport name from above: " << endl;
    string destination;
    cin >> destination;
    Airport dest = *getAirport(destination, airports);
    if (&dest == NULL) {
        processing("Destination Airport not found \n returning ...", "returned", false);
        return;
    }
    // show planes
    src.displayPlanes();
    cout << "Enter Plane ID that are parked on airport " << src.getName() << " :" << endl;
    int plane;
    cin >> plane;
    Plane pla = *getPlane(plane, planes);
    if (&pla == NULL) {
        processing("Plane not found \n returning ...", "returned", false);
        return;
    }

    cout << "Enter Flight Day [1-31]:  " << endl;
    int day;
    cin >> day;
    cout << "Enter Flight Month [1-12]: " << endl;
    int month;
    cin >> month;
    cout << "Enter Flight Year: " << endl;
    int year;
    cin >> year;
    cout << "Enter Flight Hour [0-23]: " << endl;
    int hour;
    cin >> hour;
    cout << "Enter Flight Minute [0-59]: " << endl;
    int minute;
    cin >> minute;

    cout << "Enter Flight Duration hour [0-23]: " << endl;
    int dHour;
    cin >> dHour;
    cout << "Enter Flight Duration minute [0-59]: " << endl;
    int dMinute;
    cin >> dMinute;

    Date date(day, month, year, hour, minute);
    Time duration(dHour, dMinute);

    flight->setId(id);
    flight->setType(type);
    flight->setSource(src);
    flight->setDestination(dest);
    flight->setPlane(pla);
    flight->setDate(date);
    flight->setDuration(duration);
    flight->refresh();

    processing("Editing Flight", " Edited Successfully! \n Enjoy your flight", true);
}

void addNewFlight(Airport* airports, Plane* planes, Flight* flights, Passanger* passangers, Admin* admins) {
    cout << "Enter Flight Id: " << endl;
    int id;
    cin >> id;

    cout << "Enter Flight tpye International[I] or Local [L]  (I / L): " << endl;
    char type;
    cin >> type;

    // show airports
    for (int i = 0; i < airports->num; i++) {
        airports[i].display();
    }
    cout << "Enter Flight Source Airport name from above: " << endl;
    string source;
    cin >> source;
    Airport src = *getAirport(source, airports);
    if (&src == NULL) {
        processing("Source Airport not found \n returning ...", "returned", false);
        return;
    }

    cout << "Enter Flight Destination Airport name from above: " << endl;
    string destination;
    cin >> destination;
    Airport dest = *getAirport(destination, airports);
    if (&dest == NULL) {
        processing("Destination Airport not found \n returning ...", "returned", false);
        return;
    }
    // show planes
    src.displayPlanes();
    cout << "Enter Plane ID that are parked on airport " << src.getName() << " :" << endl;
    int plane;
    cin >> plane;
    Plane pla = *getPlane(plane, planes);
    if (&pla == NULL) {
        processing("Plane not found \n returning ...", "returned", false);
        return;
    }

    cout << "Enter Flight Day [1-31]:  " << endl;
    int day;
    cin >> day;
    cout << "Enter Flight Month [1-12]: " << endl;
    int month;
    cin >> month;
    cout << "Enter Flight Year: " << endl;
    int year;
    cin >> year;
    cout << "Enter Flight Hour [0-23]: " << endl;
    int hour;
    cin >> hour;
    cout << "Enter Flight Minute [0-59]: " << endl;
    int minute;
    cin >> minute;

    cout << "Enter Flight Duration hour [0-23]: " << endl;
    int dHour;
    cin >> dHour;
    cout << "Enter Flight Duration minute [0-59]: " << endl;
    int dMinute;
    cin >> dMinute;
    
    Date date(day, month, year, hour, minute);
    Time duration(dHour, dMinute);


    Flight fli(id, type, &src, &dest, &pla, date, duration);

    flights = addFlight(&fli, flights);
    processing("Adding Flight", " Added Successfully! \n Enjoy your flight", true);
}


//////////////////////////////////////////////////////////////////////////////
///////////////////////////     USER PORTAL    ///////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void viewBookedFlights(Passanger& pass, Flight* flights) {
    for(int i = 0; i < flights->num; i++) {
        
        for(int j = 0; j < flights[i].econNum; j++) {
            if(flights[i].getEconomyTickets()[j].getPassanger()->getUsername() == pass.getUsername()) {
                flights[i].display();
            }
        }
        for(int j = 0; j < flights[i].busNum; j++) {
            if(flights[i].getBusinessTickets()[j].getPassanger()->getUsername() == pass.getUsername()) {
                flights[i].display();
            }
        }
    }
}
void delEconTicket(Ticket tic, Ticket tickets[50]) {

    for (int i = 0; i < 50; i++) {
        if (tickets[i].getId() == tic.getId()) {
            for (int j = i; j < 50 - 1; j++) {
                tickets[j] = tickets[j + 1];
            }
            break;
        }
    }
}
void delBusTicket(Ticket tic, Ticket tickets[10]) {

    int size = sizeof(tickets) / sizeof(tickets[0]);

    for (int i = 0; i < size; i++) {
        if (tickets[i].getId() == tic.getId()) {
            for (int j = i; j < size - 1; j++) {
                tickets[j] = tickets[j + 1];
            }
            break;
        }
    }
}
void cancelFlight(Passanger& pass, Flight* flights) {

    cout << " Enter the flight number you want to cancel ticket for: ";
    int id;
    cin >> id;

    for(int i = 0; i < flights->num; i++) {
        
        if (flights[i].getId() == id) {
            for(int j = 0; j < flights[i].econNum; j++) {
                if(flights[i].getEconomyTickets()[j].getPassanger()->getUsername() == pass.getUsername()) {
                    delEconTicket(flights[i].getEconomyTickets()[j], flights[i].getEconomyTickets());
                    processing("Ticket Cancelled Successfully");
                }
            }
            for(int j = 0; j < flights[i].busNum; j++) {
                if(flights[i].getBusinessTickets()[j].getPassanger()->getUsername() == pass.getUsername()) {
                    delBusTicket(flights[i].getBusinessTickets()[j], flights[i].getBusinessTickets());
                    processing("Ticket Cancelled Successfully");
                }
            }
        }
    }
    
}



void bookingMenu(Passanger& pass, Flight* flights) {
    cout << "\033[94m 1: \033[0m Book Local Flight" << endl;
    cout << "\033[94m 2: \033[0m Book International Flight" << endl;

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

    cout << " Enter the flight number you want to buy ticket for: ";
    int id;
    cin >> id;

    cout << " Economy class [E] or Bussiness Class [B] (E/B): ";
    char type;
    cin >> type;

    for (int i = 0; i < flights->num; i++) {
        if (flights[i].getId() == id) {
            if (flights[i].addTicket(id, type, pass)) {
                processing("Ticket Booked Successfully", "Enjoy your flight", true);
            }
            else {
                processing("Ticket Booking Failed", "Please try again", false);
                bookingMenu(pass, flights);
            }
            return;
        }
    }
}



#endif
