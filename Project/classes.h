#pragma once

#include <iostream>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////     USER : PASSANGER AND ADMIN     ///////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class User {
protected:
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

class Passport {
protected:
    long int id;
    string country;
    bool visa;
public:
    Passport() {
        id = 0;
        country = "";
    }
    Passport(int id, string country, bool visa = true) {
        this->id = id;
        this->country = country;
    }
    // Getters
    long int getId() {
        return id;
    }
    string getCountry() {
        return country;
    }
    bool getVisa() {
        return visa;
    }
    // Setters
    void setId(long int id) {
        this->id = id;
    }
    void setCountry(string country) {
        this->country = country;
    }
    void setVisa(bool visa) {
        this->visa = visa;
    }
    // Functions
    void display() {
        cout << "Passport ID: " << id << endl;
        cout << "Country: " << country << endl;
        if (visa) {
            cout << "Visa: Valid" << endl;
        }
        else {
            cout << "Visa: Invalid" << endl;
        }
    }

};

class Passanger : public User {
private:
    long long int cnic;
    Passport passport;
public:
    static int num;
    Passanger() {
        cnic = 0;
    }
    Passanger(string name, string username, string password, long long int cnic, int id = 0, string country = "", bool visa = true) : User(name, username, password) {
        this->cnic = cnic;
        passport.setId(id);
        passport.setCountry(country);
        passport.setVisa(visa);
    }
    Passanger(Passanger& pass) {
        this->name = pass.name;
        this->username = pass.username;
        this ->password = pass.password;
        this->cnic = pass.cnic;
        this->passport = pass.passport;
    }
    ~Passanger() {
        
    }
    // Getters
    long long int getCnic() {
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
    void editDetails() {
        cout << "  Your Current Details :" << endl;
        display();
        cout << endl;

        cout << "Enter current name: " << name << endl;
        cout << "Enter new name: ";
        cin >> name;
        
        cout << "Enter current username: " << username << endl;
        cout << "Enter new username: ";
        cin >> username;

            string pass2;
        do{
            cout << "Enter new password: ";
            cin >> password;
            cout << "re-enter new password: ";
            cin >> pass2;
            if (pass2 != password) {
                cout << " Passwords do not match!" << endl;
                cout << " Enter again: " << endl;
            }
        } while (pass2 != password);
        

        do {
            cout << " Enter new 13-digit CNIC: ";
            cin >> cnic;
            if (cnic < 1000000000000 || cnic > 9999999999999) {
                cout << " Invalid CNIC!" << endl;
            }
        } while (cnic < 1000000000000 || cnic > 9999999999999);

        long int passId;
        do {
            cout << " Enter 10-digit passport ID: ";
            cin >> passId;
            if (passId < 1000000000 || passId > 9999999999) {
                cout << " Invalid passport ID!" << endl;
            }
            passport.setId(passId);
        } while (passId < 1000000000 || passId > 9999999999);

        cout << "Enter new passport country: ";
        string country;
        cin >> country;
        passport.setCountry(country);

        cout << "Visa status is Valid [Y] or invalid[N] : " << endl;
        char visa;
        cin >> visa;
        if (visa == 'Y' || visa == 'y') {
            passport.setVisa(true);
        }
        else if (visa == 'N' || visa == 'n') {
            passport.setVisa(false);
        }
        else {
            cout << "Invalid input!" << endl;
        }
    }
    void display() {
        cout << endl;
        cout << "\033[94m--------------------------\033[0m" << endl;
        cout << endl;
        cout << "Name: " << getName() << endl;
        cout << "Username: " << getUsername() << endl;
        cout << "Password: " << getPassword() << endl;
        cout << "CNIC: " << cnic << endl;
        passport.display();
    }
};
int Passanger::num = 0;

class Admin : public User {
private:
    string role;
public:
    static int num;
    Admin() {
        role = "";
    }
    Admin(string name, string username, string password, string role) : User(name, username, password) {
        this->role = role;
    }
    ~Admin() {
        
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
        cout << endl;
        cout << "\033[94m--------------------------\033[0m" << endl;
        cout << endl;
        cout << "Name: " << getName() << endl;
        cout << "Username: " << getUsername() << endl;
        cout << "Password: " << getPassword() << endl;
        cout << "Role: " << role << endl;
    }
};
int Admin::num = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////    PLANE AND AIRPORT  /////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class Plane {
private:
    string name;
    int id;
public:
    static int num;
    Plane() {
        name = "";
        id = 0;
    }
	Plane(string name, int id) {
        this->name = name;
        this->id = id;
    }
    ~Plane() {
        
    }
    // Setters
    void setName(string name) {
        this->name = name;
    }
    void setId(int id) {
        this->id = id;
    }
    // Getters
    string getName() {
        return name;
    }
    int getId() {
        return id;
    }
    // Methods
    void display() {
        cout << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << endl;
    }
};
int Plane::num = 0;

class Airport {
private:
    string name;
    string location;
    Plane* plane; int numPlanes;
public:
    static int num; 
    Airport() {
        name = "";
        location = "";
    }
    Airport(string name, string location) {
        this->name = name;
        this->location = location;

        plane = NULL;
        numPlanes = 0;

    }
    ~Airport() {
        
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
        return name;
    }
    string getLocation() {
        return location;
    }
    Plane* getPlane() {
        return plane;
    }
    // Methods
    void addPlane(Plane plane) {
        if(numPlanes == 5) {
            cout << "No more space in airport! \n Airport is full!" << endl;
            return;
        }
        Plane* temp = new Plane[numPlanes + 1];
        for (size_t i = 0; i < numPlanes; i++) {
            temp[i] = this->plane[i];
        }
        temp[numPlanes] = plane;
        numPlanes++;
        delete[] this->plane;
        this->plane = temp;

    }
    void displayPlanes() {
        cout << endl;
        cout << "\033[94m--------------------------\033[0m" << endl;
        cout << endl;
        cout << "Planes: " << endl;
        for (size_t i = 0; i < numPlanes; i++) {
            cout << "\tPlane " << i + 1 << ": " << endl;
            cout << "\t";
            plane[i].display();
        }
    }
    void display() {
        cout << endl;
        cout << "\033[94m--------------------------\033[0m" << endl;
        cout << endl;
        cout << "Airport Name: " << name << endl;
        cout << "Airport Location: " << location << endl;
        cout << "Planes: " << endl;
        for (size_t i = 0; i < numPlanes; i++) {
            cout << "\tPlane " << i + 1 << ": " << endl;
            cout << "\t";
            plane[i].display();
        }
    }
};
int Airport::num = 0;


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////     FLIGHTS AND TICKETS      ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


class Ticket {
private:
    int id;
    char classType; // 'E' or 'B' for economy or business
	Passanger* passanger;
public:
    Ticket() {
        id = 0;
        classType = '\0';
		passanger = NULL;
    }
    Ticket(int id, char classType, Passanger* passanger) {
        this->id = id;
        this->classType = classType;
		this->passanger = NULL;
    }
    // Setters
    void setId(int id) {
        this->id = id;
    }
    void setClassType(char classType) {
        this->classType = classType;
    }
	void setPassanger(Passanger& passanger) {
		this->passanger = &passanger;
	}
    // Getters
    int getId() {
        return id;
    }
    char getClassType() {
        return classType;
    }
    Passanger* getPassanger() {
        return passanger;
    }
    // Methods
    void display() {
        cout << endl;
        cout << "\033[94m--------------------------\033[0m" << endl;
        cout << endl;
        cout << "Ticket ID: " << id << endl;
		cout << "Passanger name: " << passanger->getName() << endl;
    }
};

class Date {
private:
    int day;
    int month;
    int year;

    int hour;
    int minute;
public:
    Date() {
        day = 0;
        month = 0;
        year = 0;
        hour = 0;
        minute = 0;
    }
    Date(int day, int month, int year, int hour = 0, int minute = 0 ) {
        this->day = day;
        this->month = month;
        this->year = year;
        this->hour = hour;
        this->minute = minute;
    }
    Date(int hour, int minute) {
        this->hour = hour;
        this->minute = minute;
    }
    // Setters
    void setYear(int year) {
        this->year = year;

    }
    void setMonth(int month) {
        this->month = month;
        if (this->month > 12) {
            this->month = 12 - this->month;
            year++;
        }
    }
    void setDay(int day) {
        this->day = day;
        if (this->day > 31) {
            this->day = 31 - this->day;
            setMonth(month + 1);

        }
    }
    void setHour(int hour) {
        this->hour = hour;
        if (this->hour > 23) {
            this->hour = 23;
            setDay(day + 1);
        }
    }
    void setMinute(int minute) {
        this->minute = minute;
        if (this->minute > 59) {
            this->minute = 59;
            setHour(hour + 1);
        }
    }

    // Getters
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
    int getHour() {
        return hour;
    }
    int getMinute() {
        return minute;
    }
    // Methods
    void display() {
        cout << day << "/" << month << "/" << year << "  " << hour << ":" << minute << endl;
    }
};

class Time {
private:
    int hour;
    int minute;
public:
    Time() {
        hour = 0;
        minute = 0;
    }
    Time(int hour, int minute) {
        this->hour = hour;
        this->minute = minute;
    }
    // Setters
    void setHour(int hour) {
        this->hour = hour;
        if (this->hour > 23) {
            this->hour = 23;
        }
    }
    void setMinute(int minute) {
        this->minute = minute;
        if (this->minute > 59) {
            this->minute = 59;
        }
    }
    // Getters
    int getHour() {
        return hour;
    }
    int getMinute() {
        return minute;
    }
    // Methods
    void display() {
        cout << hour << ":" << minute << endl;
    }
};

class Flight {
private:
    int id;
    char type;
    Date departureDate;
    Time duration;
    double price;
    Airport* source;
    Airport* destination;
    Plane* plane;
    Ticket* economyTickets; 
    Ticket* businessTickets;

public:
    static int num;
    int econNum;
    int busNum;
    Flight() {
        id = 0;
        type = '\0'; // 'I' or 'L' for international or local
        departureDate = Date();
        duration = Time();
        source = NULL;
        destination = NULL;
        plane = NULL;
        economyTickets = new Ticket[50];
        businessTickets = new Ticket[10];
        econNum = 0;
        busNum = 0;
    }
    Flight(int id, char type, Airport* source, Airport* destination, Plane* plane, Date date = Date(), Time duration = Time()) {
        this->id = id;
        this->type = type;
        this->source = source;
        this->destination = destination;
        this->plane = plane;
        this->departureDate = date;
        this->duration = duration;
        this->duration = Time();
        economyTickets = new Ticket[50];
        businessTickets = new Ticket[10];
        econNum = 0;
        busNum = 0;

        if (type == 'I') {
            price = 10000 * duration.getHour() + (duration.getMinute() / 60.0);
        }
        else if (type == 'L') {
            price = 20000 * duration.getHour() + (duration.getMinute() / 60.0);
        }
    }
    ~Flight() {
        
    }
    // Setters
    void setId(int id) {
        this->id = id;
    }
    void setType(char type) {
        this->type = type;
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
    void setDate(Date date) {
        this->departureDate = date;
    }
    void setDuration(Time duration) {
        this->duration = duration;
    }
    void setPrice(int price) {
        this->price = price;
    }
    // Getters
    int getId() {
        return id;
    }
    char getType() {
        return type;
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
    Ticket* getEconomyTickets() {
        return economyTickets;
    }
    Ticket* getBusinessTickets() {
        return businessTickets;
    }
    Date getDepartureDate() {
        return departureDate;
    }
    Time getDuration() {
        return duration;
    }
    double getPrice() {
        return price;
    }

    // Methods
    void refresh() {
        if (type == 'I') {
            price = 10000 * duration.getHour() + (duration.getMinute() / 60.0);
        }
        else if (type == 'L') {
            price = 20000 * duration.getHour() + (duration.getMinute() / 60.0);
        }
    }
    bool addTicket(int id, char classType, Passanger& pass) {
        
        if (classType == 'E') {
            if (econNum == 50) {
                cout << "Economy class is full" << endl;
                return false;
            }
            economyTickets[econNum].setId(id);
            economyTickets[econNum].setClassType(classType);
            economyTickets[econNum].setPassanger(pass);
            econNum++;
            return true;
        }
        else if (classType == 'B') {
            if (busNum == 10) {
                cout << "Business class is full" << endl;
                return false;
            }
            businessTickets[busNum].setId(id);
            businessTickets[busNum].setClassType(classType);
            businessTickets[busNum].setPassanger(pass);
            busNum++;
            return true;
        }
        else {
            cout << "\033[91m Invalid class type \033[0m" << endl;
            return false;
        }
    }
    void displayTickets(double price) {
        if(econNum == 0) {
            cout << "No economy class tickets is booked!" << endl;
        }
        for (size_t i = 0; i < econNum; i++) {
            economyTickets[i].display();
            cout << "Price: " << price << endl;
        }
        if(busNum == 0) {
            cout << "No business class tickets is booked!" << endl;
        }
        for (size_t i = 0; i < busNum; i++) {
            businessTickets[i].display();
            cout << "Price: " << price << endl;
        }
    }
    void display() {
        cout << "\033[94m--------------------------\033[0m" << endl;
        cout << endl;
        cout << "Flight ID: " << id << endl;
        if (type == 'I') {
            cout << "Type: International" << endl;
            cout << "Flight: Indirect" << endl;
        }
        else if (type == 'L') {
            cout << "Type: Local" << endl;
            cout << "Flight: Direct" << endl;
        }
        cout << "Available Economy Class Tickets: " << 50 - econNum << endl;
        cout << "Available Business Class Tickets: " << 10 - busNum << endl;
        cout << "Departure Date: "; departureDate.display();
        cout << "Duration: "; duration.display();
        cout << "Arival Date: "; 
        Date arivalDate = departureDate;
        arivalDate.setHour(arivalDate.getHour() + duration.getHour());
        arivalDate.setMinute(arivalDate.getMinute() + duration.getMinute());
        arivalDate.display();

        cout << "Price: " << price << endl;
        cout << "Source: " << source->getName() << endl;
        cout << "Destination: " << destination->getName() << endl;
        cout << "Plane: " << plane->getName() << endl;
        cout << endl;
    }
};
int Flight::num = 0;