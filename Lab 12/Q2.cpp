#include <iostream>

using namespace std;

class Employee {
public:
    string name;
    char initial;
    string lastName;

    Employee(string fn, char i, string ln) : name(fn), initial(i), lastName(ln) {}
    virtual ~Employee() {}

    virtual double earnings() const = 0;
    virtual void print() const {
        cout << name << " " << initial << "." << lastName;
    }
};

class SalariedEmployee : public Employee {
public:
    double salary;

    SalariedEmployee(string fn, char i, string ln, double s) : Employee(fn, i, ln), salary(s) {}
    virtual ~SalariedEmployee() {}

    virtual double earnings() const {
        return salary;
    }
    virtual void print() const {
        Employee::print();
        cout << "Salaried :" << earnings() << endl;
    }
};

class HourlyEmployee : public Employee {
public:
    double hourlyRate;
    double hoursWorked;

    HourlyEmployee(string fn, char i, string ln, double r, double h) : Employee(fn, i, ln), hourlyRate(r), hoursWorked(h) {}
    virtual ~HourlyEmployee() {}

    virtual double earnings() const {
        return hourlyRate * hoursWorked;
    }
    virtual void print() const {
        Employee::print();
        cout << " Hourly :" << earnings() << endl;
    }
};

int main() {
    SalariedEmployee se("abdul", 'D', "RAfay", 5000);
    HourlyEmployee he("not", 'M', "Dolee", 20, 160);

    se.print();
    he.print();

    return 0;
}