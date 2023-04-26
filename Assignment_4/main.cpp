#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>

#include "module_1.h"
#include "module_2.h"

using namespace std;


void manageInventory(Inventory inventory) {
    cout << "Select:" << endl;
    cout << "1. Add Product" << endl;
    cout << "2. Remove Product" << endl;
    cout << "3. Update Quantity" << endl;
    cout << "4. Update Price" << endl;
    cout << "5. View Inventory" << endl;
    
    cout << "\t-\t" << endl;

    cout << "6. Order Products from Supplier" << endl;
    cout << "7. View Orders" << endl;
    cout << "8. View Suppliers" << endl;

    cout << "10. Exit" << endl;
    
    int choice;
    cin >> choice;
    
    string name;
    int id;
    int quantity;
    double price;

    switch (choice) {
    case 1:
        cout << endl << "Enter product name: ";
        getline(cin, name);
        cout << endl << "Enter product ID: ";
        cin >> id;
        cout << endl << "Enter product quantity: ";
        cin >> quantity;
        cout << endl << "Enter product price: ";
        cin >> price;
        processing("Adding product...", "Product added!");
        inventory.addProduct(name, id, quantity, price);
        system("cls");
        manageInventory(inventory);
        break;
    case 2:
        cout << endl << "Enter product ID: ";
        cin >> id;
        if (inventory.removeProduct(id)) {
            processing("Removing product...", "Product removed!");
        }
        else {
            cout << endl << "Product not found!" << endl;
        }
        system("cls");
        manageInventory(inventory);
        break;
    case 3:
        cout << endl << "Enter product ID: ";
        cin >> id;
        cout << endl << "Enter product quantity: ";
        cin >> quantity;

        processing("Updating quantity...", "Quantity updated!");
        inventory.getProducts(inventory.findProduct(id)).setQuantity(quantity);
        manageInventory(inventory);
        break;
    case 4:
        cout << endl << "Enter product ID: ";
        cin >> id;

        cout << endl << "Enter product price: ";
        cin >> price;

        processing("Updating price...", "Price updated!");
        inventory.getProducts(inventory.findProduct(id)).setPrice(price);
        manageInventory(inventory);
        break;
    case 5:
        processing("Viewing inventory...", "Inventory viewed!");
        inventory.viewInventory();
        cout << endl << "\t----------" << endl;
        manageInventory(inventory);
        break;
    case 6:
        processing("Exiting...", "Exited!");
        exit(0);
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}



int main() {
    Inventory inventory;
    inventory.addProduct("Oil", 12, 10, 100);
    inventory.addProduct("Pasta", 25, 20, 200);
    inventory.addProduct("Milk", 33, 30, 300);
    inventory.addProduct("Cookies", 81, 40, 400);
    inventory.addProduct("Bread", 54, 50, 500);

    Supplier* supplier;
    supplier = new Supplier[2];
    
    supplier[0] = Supplier(1, "Ghuas and Brothers suppliers");
    supplier[0].addProduct("Snacks", 98, 10, 100);
    supplier[0].addProduct("Milk", 33, 20, 200);
    supplier[0].addProduct("Cookies", 81, 30, 300);
    supplier[0].addProduct("Bread", 54, 40, 400);
    supplier[0].addProduct("Oil", 12, 50, 500);

    supplier[1] = Supplier(2, "Maleek and Brothers suppliers");
    supplier[1].addProduct("Oil", 12, 10, 100);
    supplier[1].addProduct("Pasta", 25, 20, 200);
    supplier[1].addProduct("Shampoo", 77, 30, 300);
    supplier[1].addProduct("Beer", 69, 40, 400);

    cout << endl << "Welcome to the Inventory Management System";
    cout << endl << "------------------------------------------";

    cout << endl << "1: Manage Inventory";
    cout << endl << "2: Manage Shop";
    cout << endl << "4: Exit";

    int choice;
    cout << endl << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        manageInventory(inventory);
        break;
    case 2:
        
        break;
    }
    
    
    return 0;
}
