#include <iostream>
#include <cstring>
using namespace std;

class Pizza {
    char* name;
    char* toppings;
    char* size;
    bool is_ready;
    double price;

public:

    Pizza() {
        name = new char[1];
        toppings = new char[1];
        size = new char[1];
        *name = '\0';
        *toppings = '\0';
        *size = '\0';
        is_ready = false;
        price = 0;
    }

    Pizza(char* toppingVal, double priceVal) {
        name = new char[1];
        size = new char[1];
        *name = '\0';
        toppings = new char[strlen(toppingVal) + 1];
        for (int i = 0; i < strlen(toppingVal) + 1; i++) {
            toppings[i] = toppingVal[i];
        }
        *size = '\0';
        price = priceVal;
        is_ready = false;
    }

    Pizza(char *toppingVal, double priceVal, char *nameVal, char* sizeVal, bool ready_status) {
        name = new char[strlen(nameVal) + 1];
        for (int i = 0; i < strlen(nameVal) + 1; i++) {
            name[i] = nameVal[i];
        }
        toppings = new char[strlen(toppingVal) + 1];
        for (int i = 0; i < strlen(toppingVal) + 1; i++) {
            toppings[i] = toppingVal[i];
        }
        size = new char[strlen(sizeVal) + 1];
        for (int i = 0; i < strlen(sizeVal); i++) {
            size[i] = sizeVal[i];
        }
        price = priceVal;
        is_ready = ready_status;
    }

    Pizza(const Pizza& pizza) {
        name = new char[strlen(pizza.name) + 1];
        for (int i = 0; i < strlen(pizza.name); i++) {
            name[i] = pizza.name[i];
        }
        toppings = new char[strlen(pizza.toppings) + 1];
        for (int i = 0; i < strlen(pizza.toppings); i++) {
            toppings[i] = pizza.toppings[i];
        }
        size = new char[strlen(pizza.size) + 1];
        for (int i = 0; i < strlen(pizza.size); i++) {
            size[i] = pizza.size[i];
        }
        price = pizza.price;
        is_ready = pizza.is_ready;
    }

    void setTopping(char* toppingVal) {
        toppings = new char[strlen(toppingVal) + 1];
        for (int i = 0; i < strlen(toppingVal); i++) {
            toppings[i] = toppingVal[i];
        }
    }

    void setPrice(double priceVal) {
        price = priceVal;
    }

    void setName(char* nameVal) {
        name = new char[strlen(nameVal) + 1];
        for (int i = 0; i < strlen(nameVal); i++) {
            name[i] = nameVal[i];
        }
    }

    void setSize(char* sizeVal) {
        size = new char[strlen(sizeVal) + 1];
        for (int i = 0; i < strlen(sizeVal); i++) {
            size[i] = sizeVal[i];
        }
    }

    ~Pizza() {
        delete[] toppings;
    }

    char* getSize() {
        return size;
    }

    char* getName() {
        return name;
    }

    char* getToppings() {
        return toppings;
    }

    double getPrice() {
        return price;
    }

    void makePizza() {
        if (*toppings != '\0') {
            is_ready = true;
        }
    }

    bool check_status() {
        return is_ready;
    }

};

int main() {
    char* name = new char[10];
    char* size = new char[10];
    char* toppings = new char[10];
    double price = 0;
    bool is_ready = false;

    Pizza pizza1;
    cout << endl << "Enter name of pizza: ";
    cin >> name;
    pizza1.setName(name);
    cout << endl << "Enter size of pizza: ";
    cin >> size;
    pizza1.setSize(size);
    cout << endl << "Enter toppings of pizza: ";
    cin >> toppings;
    pizza1.setTopping(toppings);
    cout << endl << "Enter price of pizza: ";
    cin >> price;
    pizza1.setPrice(price);
    pizza1.makePizza();
    cout << endl << "Pizza name: " << pizza1.getName();
    cout << endl << "Pizza size: " << pizza1.getSize();
    cout << endl << "Pizza toppings: " << pizza1.getToppings();
    cout << endl << "Pizza price: " << pizza1.getPrice();
    cout << endl << "Pizza ready status: " << pizza1.check_status();

    Pizza pizza2(pizza1);

    cout << endl << "Enter name of pizza: ";
    cin >> name;
    pizza2.setName(name);
    cout << endl << "Enter size of pizza: ";
    cin >> size;
    pizza2.setSize(size);
    cout << endl << "Enter toppings of pizza: ";
    cin >> toppings;
    pizza2.setTopping(toppings);
    cout << endl << "Enter price of pizza: ";
    cin >> price;
    pizza2.setPrice(price);
    pizza2.makePizza();

    cout << endl << "Pizza name: " << pizza2.getName();
    cout << endl << "Pizza size: " << pizza2.getSize();
    cout << endl << "Pizza toppings: " << pizza2.getToppings();
    cout << endl << "Pizza price: " << pizza2.getPrice();
    cout << endl << "Pizza ready status: " << pizza2.check_status();

    cout << endl << "Pizza name of pizza1: " << pizza1.getName();
    cout << endl << "Pizza size of pizza1: " << pizza1.getSize();
    cout << endl << "Pizza toppings of pizza1: " << pizza1.getToppings();
    cout << endl << "Pizza price of pizza1: " << pizza1.getPrice();
    cout << endl << "Pizza ready status of pizza1: " << pizza1.check_status();



    return 0;
}