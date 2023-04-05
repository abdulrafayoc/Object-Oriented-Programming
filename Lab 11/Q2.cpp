#include <iostream>

using namespace std;

class Car {
    string make;
    string model;
    string regno;
    int year;
public:
    Car() {
        make = "";
        model = "";
        regno = "";
        year = 0;
    }
    Car(string m, string c, string r, int y) {
        this->make = m;
        this->model = c;
        this->regno = r;
        this->year = y;
    }
    string getMake() {
        return make;
    }
    string getModel() {
        return model;
    }
    string getRegno() {
        return regno;
    }
    int getYear() {
        return year;
    }
    void setMake(string make) {
        this->make = make;
    }
    void setModel(string model) {
        this->model = model;
    }
    void setRegno(string regno) {
        this->regno = regno;
    }
    void setYear(int year) {
        this->year = year;
    }
};

class Garage {
    string name;
    int index;
    int capacity;
    Car *gar;
public:
    Garage() {
        name = "";
        index = 0;
        capacity = 10;
        gar = new Car [capacity];
    }
    Garage(string n, int i, int c) {
        this->name = n;
        this->index = i;
        this->capacity = c;
        gar = new Car [capacity];
    }
    bool IsEmpty () {
        if (index == 0)
            return true;
        else
            return false;
    }
    bool IsFull () {
        if (index == capacity)
            return true;
        else
            return false;
    }
    bool Push (Car c) {
        if (IsFull())
            return false;
        else {
            gar[index] = c;
            index++;
            return true;
        }
    }
    bool Find (string reg) {
        for (int i = 0; i < index; i++) {
            if (gar[i].getRegno() == reg)
                return true;
        }
        return false;
    }
    bool Remove (string reg) {
        for (int i = 0; i < index; i++) {
            if (gar[i].getRegno() == reg) {
                for (int j = i; j < index; j++) {
                    gar[j] = gar[j+1];
                }
                index--;
                cout << "Car removed!" << endl;
                return true;
            }
        }
        return false;
    }
    void Display () {
        for (int i = 0; i < index; i++) {
            cout << gar[i].getMake() << " " << gar[i].getModel() << " " << gar[i].getRegno() << " " << gar[i].getYear() << endl;
        }
    }
};

int main () {
    Garage g("My_Garage", 0, 10);
    Car c1("Toyota", "Corolla", "ABC123", 2010);
    Car c2("Honda", "Civic", "DEF456", 2012);
    Car c3("Nissan", "Sunny", "GHI789", 2014);
    Car c4("Suzuki", "Swift", "JKL012", 2016);

    g.Push(c1);
    g.Push(c2);
    g.Push(c3);
    g.Push(c4);

    if (g.Find("ABC123"))
        cout << "Car found!" << endl;
    else
        cout << "Car not found!" << endl;
    
    if (g.Find("MNO345"))
        cout << "Car found!" << endl;
    else
        cout << "Car not found!" << endl;

    if (g.Remove("ABC123"))
        cout << endl;
    else
        cout << "Car not found!" << endl;

    if (g.Remove("MNO345"))
        cout << endl;
    else
        cout << "Car not found!" << endl;

    return 0;
}