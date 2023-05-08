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
private:
    int id;
    string country;
public:
    Passport() {
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


class Passanger : public User {
private:
    long long int cnic;
    Passport passport;
    //payment
public:
    static int num;
    Passanger() {
        cnic = 0;
    }
    Passanger(string name, string username, string password, long long int cnic, int id = 0, string country = "") : User(name, username, password) {
        this->cnic = cnic;
        passport.setId(id);
        passport.setCountry(country);
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
    void display() {
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
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
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
        Plane* temp = new Plane[numPlanes + 1];
        for (size_t i = 0; i < numPlanes; i++) {
            temp[i] = this->plane[i];
        }
        temp[numPlanes] = plane;
        numPlanes++;
        delete[] this->plane;
        this->plane = temp;

    }
    void display() {
        cout << "Airport Name: " << name << endl;
        cout << "Airport Location: " << location << endl;
        cout << "Planes: " << endl;
        for (size_t i = 0; i < numPlanes; i++) {
            cout << "Plane " << i + 1 << ": " << endl;
            cout << "Plane Name: " << plane[i].getName() << endl;
            cout << "Plane ID: " << plane[i].getId() << endl;
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
	void setPassanger(Passanger* passanger) {
		this->passanger = passanger;
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
        cout << "Ticket ID: " << id << endl;
		cout << "Passanger name: " << passanger->getName() << endl;
    }
};

class Flight {
private:
    int id;
    char type;
    Airport* source;
    Airport* destination;
    Plane* plane;
    Ticket* econnomyTickets;
    Ticket* businessTickets;
public:
    static int num;
    Flight() {
        id = 0;
        type = '\0'; // 'I' or 'L' for international or local
        source = NULL;
        destination = NULL;
        plane = NULL;
        econnomyTickets = new Ticket[50];
        businessTickets = new Ticket[10];
    }
    Flight(int id, char type, Airport* source, Airport* destination, Plane* plane) {
        this->id = id;
        this->type = type;
        this->source = source;
        this->destination = destination;
        this->plane = plane;
        econnomyTickets = new Ticket[50];
        businessTickets = new Ticket[10];
    }
    Flight(Flight& flight) {
        this->id = flight.id;
        this->type = flight.type;
        this->source = flight.source;
        this->destination = flight.destination;
        this->plane = flight.plane;
        this->econnomyTickets = flight.econnomyTickets;
        this->businessTickets = flight.businessTickets;
    }
    Flight& operator= (Flight& flight) {
		this->id = flight.id;
        this->type = flight.type;
		this->source = flight.source;
		this->destination = flight.destination;
		this->plane = flight.plane;
        this->econnomyTickets = flight.econnomyTickets;
        this->businessTickets = flight.businessTickets;
		return *this;
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

        //        plane.setFlight(this);
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
    // Methods
    void display() {
        cout << "Flight ID: " << id << endl;
        if (type == 'I')
            cout << "Type: International" << endl;
        else if (type == 'L') 
            cout << "Type: Local" << endl;
        cout << "Source: " << source->getName() << endl;
        cout << "Destination: " << destination->getName() << endl;
        cout << "Plane: " << plane->getName() << endl;
    }
};
int Flight::num = 0;


