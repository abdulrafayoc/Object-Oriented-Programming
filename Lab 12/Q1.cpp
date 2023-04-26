#include <iostream>

using namespace std;

class Person {
public:
    string name;
    Person(string n) : name(n) {
        name = n;
        cout << "Person constructor" << endl;
    }
    virtual ~Person() {
        cout << "Person destructor" << endl;
    }
    virtual void print() const {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
public:
    double gpa;
    Student(string n, double g) : Person(n), gpa(g) {
        name = n;
        gpa = g;
        cout << "Student constructor" << endl;
    }
    virtual ~Student() {
        cout << "Student destructor" << endl;
    }
    virtual void print() const {
        Person::print();
        cout << "GPA: " << gpa << endl;
    }
};

int main() {
    Person* p1 = new Person("Ali");
    Student* s1 = new Student("Umer", 1.8);

    p1->print();
    s1->print();
    return 0;
}