#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>

#include "module_1.h"
#include "module_2.h"
#include "module_3.h"

using namespace std;
void managePOS (Inventory& inventory, Costumer* costumer, Order* orders, Supplier* supplier, Sale* sales);
void manageInventory(Inventory& inventory, Supplier* supplier , Order* orders, Costumer* costumer, Sale* sales);

void mainMenu(Inventory& inventory, Supplier* supplier , Order* orders, Costumer* costumer, Sale* sales) {
    Sleep(1000);
    system("cls");
    cout << endl << "\033[34m     +--------------------------------------------------+";
    cout << endl << "\033[94m     | -- Welcome to the Inventory Management System -- |";
    cout << endl << "\033[34m     +--------------------------------------------------+\033[00m" << endl;

    cout << endl << "\033[34m 1: \033[00m Manager Dashboard  :  Manage Inventory";
    cout << endl << "\033[34m 2: \033[00m Salesman Dashboard :  Point of Sales";
    cout << endl << "\033[34m 4: \033[00m Exit";

    int choice;
    cout << endl << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        manageInventory(inventory, supplier, orders, costumer, sales);
        break;
    case 2:
		managePOS(inventory, costumer, orders, supplier, sales);
        
        break;
    }
}

void managePOS(Inventory& inventory, Costumer* costumer, Order* orders, Supplier* supplier, Sale* sales) {

    costumer = new Costumer("Ahmed Ali", &inventory);

    cout << endl << "\033[34m 1: \033[00m Add Products to Cart";
    cout << endl << "\033[34m 2: \033[00m Apply Discounts to Cart";
    cout << endl << "\033[34m 3: \033[00m Refund Products";
    cout << endl << "\033[34m 4: \033[00m Checkout";
    cout << endl << "\033[34m 5: \033[00m View Sale Report";
    cout << endl << "\033[34m 6: \033[00m View Inventory Report";
    cout << endl << "\033[34m 7: \033[00m Profit Report";
    
    cout << endl << "\t-\t";
    
    cout << endl << "\033[34m 9: \033[00m Back";
    cout << endl << "\033[34m 0: \033[00m Exit";

    int choice;
    cout << endl << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
    case 1:
        addToCart(costumer[0], inventory);
        processing("Adding to cart...", "Added to cart!");
        managePOS(inventory, costumer, orders, supplier, sales);
        break;
    case 2:
        ApplyDiscount(costumer[0], inventory);
        managePOS(inventory, costumer, orders, supplier, sales);
        break;
    case 3:
        removeFromCart(costumer[0], inventory);
        managePOS(inventory, costumer, orders, supplier, sales);
        break;
    case 4:
        checkout(costumer[0], inventory, sales);
        managePOS(inventory, costumer, orders, supplier, sales);
        break;
    case 5:
        viewSaleReport(sales, inventory, costumer );
        managePOS(inventory, costumer, orders, supplier, sales);
        break;
    case 6:
        // viewInventoryReport(inventory);
        managePOS(inventory, costumer, orders, supplier, sales);
        break;
    case 7:
        // viewProfitReport(inventory);
        managePOS(inventory, costumer, orders, supplier, sales);
        break;
    case 9:
        processing("Going back...", "");
        mainMenu(inventory, supplier, orders, costumer, sales);
        break;
    case 0:
        processing("Exiting...", "Exited!");
        exit(0);
        break;
    }
}

void manageInventory(Inventory& inventory, Supplier* supplier, Order* orders, Costumer* costumer, Sale* sales) {
    cout << "Select:" << endl;
    cout << "\033[34m 1: \033[00m Add Product" << endl;
    cout << "\033[34m 2: \033[00m Remove Product" << endl;
    cout << "\033[34m 3: \033[00m Update Quantity" << endl;///////////////
    cout << "\033[34m 4: \033[00m Update Price/Apply Discounts" << endl;////////////////
    cout << "\033[34m 5: \033[00m View Inventory" << endl;
    
    cout << "\t-\t" << endl;

    cout << "\033[34m 6: \033[00m Order Products from Suppliers" << endl;///////
    cout << "\033[34m 7: \033[00m View Orders from Suppliers" << endl;///////////////
    cout << "\033[34m 8: \033[00m View Suppliers" << endl;
    
    cout << "\t-\t" << endl;
    
    cout << "\033[34m 9: \033[00m Back" << endl;
    cout << "\033[33m 0: \033[00m Exit" << endl;
    
    int choice;
    cin >> choice;
    
    string name;
    int id;
    int quantity;
    double price;
    static int numOdr = 0;

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
        
        manageInventory(inventory, supplier , orders, costumer, sales);
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
        
        manageInventory(inventory, supplier , orders, costumer, sales);
        break;
    case 3:
        cout << endl << "Enter product ID: ";
        cin >> id;
        cout << endl << "Enter updated product quantity: ";
        cin >> quantity;
        cout << " the Product name is: " << inventory.getProducts(inventory.findProduct(id)).getName() << endl;
        cout << " the Product index is: " << inventory.findProduct(id)<< endl;
        cout << " the Product is now: " << inventory.getProducts(inventory.findProduct(id)).getQuantity() << endl;

        processing("Updating quantity...", "Quantity updated!");
        inventory.getProducts(inventory.findProduct(id)).setQuantity(quantity);
        system("cls");
        manageInventory(inventory, supplier , orders, costumer, sales);
        break;
    case 4:
        // cout << endl << "Enter product ID: ";
        // cin >> id;

        // cout << " the Product name is: " << inventory.getProducts(inventory.findProduct(id)).getName() << endl;
        // cout << " the Product index is: " << inventory.findProduct(id)<< endl;
        // cout << " the Product is now: " << inventory.getProducts(inventory.findProduct(id)).getPrice() << endl;

        // cout << endl << "Enter product's new price: ";
        // cin >> price;

        managePrice(inventory);

        processing("Updating price...", "Price updated!");
        system("cls");
        manageInventory(inventory, supplier , orders, costumer, sales);
        break;
    case 5:
        processing("Viewing inventory...", "Inventory viewed!");
        inventory.viewInventory();
        cout << endl << "\t----------" << endl;
        
        manageInventory(inventory, supplier, orders, costumer, sales);
        break;
    case 6:
		processing("Ordering products...", "Products ordered!");
		if (orderProduct(inventory, supplier, orders))
        {
            numOdr++;
            cout << endl << "Order number " << numOdr << " placed!" << endl;
        }
        // system("cls");
		manageInventory(inventory, supplier, orders, costumer, sales);
		break;
    case 7:
        processing("Viewing orders...", "Orders viewed!");
        // numOdr = sizeof(orders) / sizeof(Order);
        for (int i = 0; i < numOdr; i++) {
            cout << "\nOrder " << i + 1 << ":" << endl;
            orders[i].viewOrder();
        }
        manageInventory(inventory, supplier, orders, costumer, sales);
        break;
    case 8:
        processing("Viewing suppliers...", "Suppliers viewed!");

        for (int i = 0; i < 2; i++) {
            cout << endl << "Name: " << supplier[i].getName() << endl;
            cout << "\tID: " << supplier[i].getId() << endl;
            supplier[i].viewInventory();
        }
        manageInventory(inventory, supplier, orders, costumer, sales);
        break;
    case 9:
        system("cls");
        mainMenu(inventory, supplier, orders, costumer, sales);
        break;
    case 0:
        processing("Exiting...", "Exited!");
        exit(0);
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }
}

int main() {
    processing("Starting the program!...", "Started!");
    Inventory inventory;
    inventory.addProduct("Oil", 12, 10, 100);
    inventory.addProduct("Pasta", 25, 20, 200);
    inventory.addProduct("Milk", 33, 30, 300);
    inventory.addProduct("Cookies", 81, 40, 400);
    inventory.addProduct("Bread", 54, 50, 500);

    Supplier* supplier;
    supplier = new Supplier[2];
    
    supplier[0] = Supplier(111, "Chaudhary and Brothers suppliers");
    supplier[0].addProduct("Snacks", 98, 10, 100);
    supplier[0].addProduct("Milk", 33, 20, 200);
    supplier[0].addProduct("Cookies", 81, 30, 300);
    supplier[0].addProduct("Bread", 54, 40, 400);
    supplier[0].addProduct("Oil", 12, 50, 500);

    supplier[1] = Supplier(222, "Malik and Nawab suppliers");
    supplier[1].addProduct("Oil", 12, 10, 100);
    supplier[1].addProduct("Pasta", 25, 20, 200);
    supplier[1].addProduct("Shampoo", 77, 30, 300);
    supplier[1].addProduct("Beer", 69, 40, 400);

    Order* orders = nullptr;
    Costumer* costumer = nullptr;
    Sale* sales = nullptr;


    mainMenu(inventory, supplier, orders, costumer, sales);
    
    
    return 0;
}
