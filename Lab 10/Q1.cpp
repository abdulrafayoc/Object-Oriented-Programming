#include <iostream>

using namespace std;

class vehicle
{
protected:
    double price;
    double milage;
public:
    vehicle()
    {
        price = 0;
        milage = 0;
    }
    vehicle(double p, double m)
    {
        price = p;
        milage = m;
    }
};
class car : public vehicle
{
protected:
    int cost;
    int warranty;
    int seating;
    string fuel;
public:
    car()
    {
        cost = 0;
        warranty = 0;
        seating = 0;
        fuel = " ";
    }
    car(double p, double m, int c, int w, int s, string f) : vehicle(p, m)
    {
        cost = c;
        warranty = w;
        seating = s;
        fuel = f;
    }

};
class bike : public vehicle
{
protected:
    int cylinder;
    int gear;
    string cooling;
    string wheel;
    int tank;
public:
    bike()
    {
        cylinder = 0;
        gear = 0;
        cooling = " ";
        wheel = " ";
        tank = 0;
    }
    bike(double p, double m, int c, int g, string co, string w, int t) : vehicle(p, m)
    {
        cylinder = c;
        gear = g;
        cooling = co;
        wheel = w;
        tank = t;
    }
};
class audi : public car
{
protected:
    string model;
public:
    audi()
    {
        model = " ";
    }
    audi(double p, double m, int c, int w, int s, string f, string mo) : car(p, m, c, w, s, f)
    {
        model = mo;
    }
    void display()
    {
        cout << "Price: " << price << endl;
        cout << "Milage: " << milage << endl;
        cout << "Cost: " << cost << endl;
        cout << "Warranty: " << warranty << endl;
        cout << "Seating: " << seating << endl;
        cout << "Fuel: " << fuel << endl;
        cout << "Model: " << model << endl;
    }
};
class ford : public car
{
protected:
    string model;
public:
    ford()
    {
        model = " ";
    }
    ford(double p, double m, int c, int w, int s, string f, string mo) : car(p, m, c, w, s, f)
    {
        model = mo;
    }
    void display()
    {
        cout << "Price: " << price << endl;
        cout << "Milage: " << milage << endl;
        cout << "Cost: " << cost << endl;
        cout << "Warranty: " << warranty << endl;
        cout << "Seating: " << seating << endl;
        cout << "Fuel: " << fuel << endl;
        cout << "Model: " << model << endl;
    }
};

class bajaj : public bike
{
protected:
    string model;
public:
    bajaj()
    {
        model = " ";
    }
    bajaj(double p, double m, int c, int g, string co, string w, int t, string mo) : bike(p, m, c, g, co, w, t)
    {
        model = mo;
    }
    void display()
    {
        cout << "Price: " << price << endl;
        cout << "Milage: " << milage << endl;
        cout << "Cylinder: " << cylinder << endl;
        cout << "Gear: " << gear << endl;
        cout << "Cooling: " << cooling << endl;
        cout << "Wheel: " << wheel << endl;
        cout << "Tank: " << tank << endl;
        cout << "Model: " << model << endl;
    }
};
class tvs : public bike
{
protected:
    string model;
public:
    tvs()
    {
        model = " ";
    }
    tvs(double p, double m, int c, int g, string co, string w, int t, string mo) : bike(p, m, c, g, co, w, t)
    {
        model = mo;
    }
    void display()
    {
        cout << "Price: " << price << endl;
        cout << "Milage: " << milage << endl;
        cout << "Cylinder: " << cylinder << endl;
        cout << "Gear: " << gear << endl;
        cout << "Cooling: " << cooling << endl;
        cout << "Wheel: " << wheel << endl;
        cout << "Tank: " << tank << endl;
        cout << "Model: " << model << endl;
    }
};

int main()
{
    audi a8(1000000, 20, 100000, 5, 5, "Petrol", "Audi A8");
    ford f150(500000, 15, 50000, 3, 5, "Diesel", "Ford F150");
    bajaj pulsar(100000, 30, 4, 5, "Air", "Alloy", 15, "Bajaj Pulsar");
    tvs apache(50000, 40, 2, 4, "Water", "Steel", 10, "TVS Apache");
    a8.display();
    f150.display();
    pulsar.display();
    apache.display();
    return 0;
}