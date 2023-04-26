#ifndef module_1
#define module_1

#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>


using namespace std;


void processing(string msg, string dmsg) {
    cout << endl << endl << msg << endl;
    for (int i = 0; i < 10; i++) {
        cout << ".";
        Sleep(500);
    }
    cout << endl << dmsg << endl;
}

class Product {
private:
    string name; 
    int id;
    int quantity;
    double price;
public:
    Product() {
        name = "";
        id = 0;
        quantity = 0;
        price = 0;
    }
    Product(string name, int id, int quantity, double price){
        this->name = name;
        this->id = id;
        this->quantity = quantity;
        this->price = price;
    }

    string getName(){
        return name;
    }
    int getID(){
        return id;
    }
    int getQuantity(){
        return quantity;
    }
    double getPrice(){
        return price;
    }

    void setName(string name){
        this->name = name;
    }
    void setID(int id){
        this->id = id;
    }
    void setQuantity(int quantity){
        this->quantity = quantity;
    }
    void setPrice(double price){
        this->price = price;
    }
};

class Supplier {
private:
    int id;
    string name;
    Product* products;
public:
    Supplier() {
        id = 0;
        name = "";
    }
    Supplier(int id, string name){
        this->id = id;
        this->name = name;
    }
    int getID(){
        return id;
    }
    string getName(){
        return name;
    }
    Product getProducts(int i) {
        return products[i];
    }
    void addProduct(string name, int id, int quantity, double price) {
        products = new Product[sizeof(products) + 1];
        products[sizeof(products) - 1] = Product(name, id, quantity, price);
    }
};

class Inventory {
private:
    Product* products;
public:
    Inventory() {
        
    }
    Product getProducts(int i) {
        if (i < sizeof(products)) {
            return products[i];
        }
        else {
            cout << endl << "Product not found!" << endl;
            return Product();
        }
    }
    int findProduct(int id) {
        for (int i = 0; i < sizeof(products); i++) {
            if (products[i].getID() == id) {
                return i;
            }
        }
        cout << endl << "Product not found!" << endl;
        return -1;
    }
    void addProduct(string name, int id, int quantity, double price) {
        products = new Product[sizeof(products) + 1];
        products[sizeof(products) - 1] = Product(name, id, quantity, price);
    }
    bool removeProduct(int id) {
        for (int i = 0; i < sizeof(products); i++) {
            if (products[i].getID() == id) {
                products[i] = products[sizeof(products) - 1];
                products = new Product[sizeof(products) - 1];
                return true;
                break;
            }
            else if (i == sizeof(products) - 1) {
                return false;
            }
        }
    }
    void viewInventory() {
        cout << "Inventory:" << endl;
        for (int i = 0; i < sizeof(products); i++) {
            cout << "Product ID: " << products[i].getID() << endl;
            cout << "Product Name: " << products[i].getName() << endl;
            cout << "Product Quantity: " << products[i].getQuantity() << endl;
            cout << "Product Price: " << products[i].getPrice() << endl << endl;
        }
    }
};

void orderProduct(Inventory inventory, Supplier supplier) {
    cout<<"What product would you like to order? \nEnter Product ID:";
    int productID;
    cin >> productID;

    int index;

    for (int i = 0; i < 10; i++) {
        if (productID == inventory.getProducts(i).getID()) {
            cout << "Product ID found!" << endl;
            index = i;
            break;
        }
        else {
            cout << "Product ID not found!" << endl;
        }
    }
    if (inventory.getProducts(index).getQuantity() < 100) {
        cout << "Quantity is less than 100." << endl;
    }
    else {
        cout << "Product is already in stock!" << endl;
        cout << "Canceling Order." << endl;
        return;
    }
    
    int supIndex;
    for (int i = 0; i < 5; i++) {
        if (productID == supplier.getProducts(i).getID()) {
            cout << "Supplier have product!" << endl;
            supIndex = i;
            break;
        }
        else {
            cout << "Supplier does not have product!" << endl;
        }
    }

    processing("Ordering product...", "Product ordered!");    
}

void takeProduct(Inventory inventory, Supplier supplier) {
    cout << "What product would you like to take?" <<endl;
    cout << "Enter Product ID:";
    int productID;
    cin >> productID;

    int index;

    for (int i = 0; i < 10; i++) {
        if (productID == inventory.getProducts(i).getID()) {
            cout << "Product ID found!" << endl;
            index = i;
            break;
        }
        else {
            cout << "Product ID not found!" << endl;
        }
    }
    
    int supIndex;
    for (int i = 0; i < 5; i++) {
        if (productID == supplier.getProducts(i).getID()) {
            cout << "Supplier has product!" << endl;
            supIndex = i;
            break;
        }
        else {
            cout << "Supplier does not have product!" << endl;
        }
    }
    
    int quantity = inventory.getProducts(index).getQuantity() + supplier.getProducts(supIndex).getQuantity();

    processing("Taking product...", "Product taken!");

    inventory.getProducts(index).setQuantity(quantity);
    supplier.getProducts(supIndex).setQuantity(0);
    
    cout << "The quantity is now: " << inventory.getProducts(index).getQuantity() << endl;
    
}

void managePrice(Inventory inventory) {
    cout << "What product would you like to set/update the price of?" <<endl;
    cout << "Enter Product ID:";
    int productID;
    cin >> productID;
    
    int index;

    for (int i = 0; i < 10; i++) {
        if (productID == inventory.getProducts(i).getID()) {
            cout << "Product ID found!" << endl;
            index = i;
            break;
        }
        else {
            cout << "Product ID not found!" << endl;
        }
    }
    
    cout << "Select:" << endl;
    cout << "1. Set New Price" << endl;
    cout << "2. Apply Discount" << endl;
    int choice;
    cin >> choice;
    if (choice == 1) {   
        cout << "What is the new price of the product?" << endl;
        double price;
        cin >> price;
        if (price < 0) {
            cout << "Price cannot be negative!" << endl;
            return;
        }
        else {
            inventory.getProducts(index).setPrice(price);
            cout << "Price changed!" << endl;
        }
    }
    else if (choice == 2) {
        cout << "Choose Discount:" << endl;
        cout << "1. 10% Ramadan " << endl;
        cout << "2. 20%" << endl;
        cout << "3. 30%" << endl;
        cout << "4. 40%" << endl;
        cout << "5. 50% " << endl;
        cout << "6. Costum Discount" << endl;
        cout << "What is the discount name?" << endl;
        string discountName;
        getline(cin, discountName);

        cout << "What is the discount in percentage?" << endl;
        double discount;
        cin >> discount;
        if (discount < 0) {
            cout << "Discount cannot be negative!" << endl;
            return;
        }
        else {
            double price = inventory.getProducts(index).getPrice();
            price = price - (price * (discount / 100));
            inventory.getProducts(index).setPrice(price);
            cout << "Discount applied!" << endl;
        }
    }
    else {
        cout << "Invalid choice!" << endl;
        return;
    }
}



#endif