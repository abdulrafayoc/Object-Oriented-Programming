#ifndef module_3
#define module_3

#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>

using namespace std;


class Sale {
private:
    int id;
    double totalCost;
    static int counter;
    string date;
    Product* products;
public:
    Sale() {
        id = counter;
        totalCost = 0;
        counter++;
        date = "";
    }
    Sale(Costumer& costumer) {
        id = counter;
        counter++;
        totalCost = costumer.getTotalCost();
        date = "";
        products = &costumer.getPro();
    }
    int getId() {
        return id;
    }
    double getTotalCost() {
        return totalCost;
    }
    string getDate() {
        return date;
    }
    void setTotalCost(double cost) {
        totalCost = cost;
    }
    int getNum() {
        return counter;
    }

    void viewSale() {
        cout << "Sale ID: " << id << endl;
        cout << "Products: " << endl << endl;
        for (int i = 0; i < sizeof(products)/sizeof(Product); i++) {
            cout << products[i].getName() << " : pkr " << products[i].getPrice() << " X " << products[i].getQuantity() << endl;
        }
        cout << "Total Cost: pkr" << totalCost << endl;
    }

};
int Sale::counter = 0;


void newSale(Sale* sales, Sale s) {
    int size = sizeof(sales) / sizeof(Sale);
    Sale* temp = new Sale[size + 1];

    for (int i = 0; i < size; i++) {
        temp[i] = sales[i];
    }

    temp[size] = s;

    sales = temp;
    size++;

    delete[] temp;
}


void checkout(Costumer costumer, Inventory& inventory, Sale* sales) {
    system("cls");

    costumer.viewCart();
    cout << endl << "Total Cost: " << costumer.getTotalCost();
    cout << endl << "Enter amount paid: ";
    double amountPaid;
    cin >> amountPaid;
    processing("Processing Payment...", "Done!");
    if (amountPaid < costumer.getTotalCost()) {
        cout << endl << "Amount paid is less than total cost!";
        checkout(costumer, inventory, sales);
    }
    
    cout << endl << "Change: " << amountPaid - costumer.getTotalCost();
    cout << endl << "Thank you for shopping with us!";
    
    newSale(sales, Sale(costumer));
    sales[sales->getNum() - 1].viewSale();
    
    costumer.setTotalCost(0);
    costumer.clearCart();
    
}

void allSales(Sale* sales) {
    system("cls");
    cout << "Sales Report" << endl << endl;
    int size = sizeof(sales) / sizeof(Sale);
    for (int i = 0; i < size; i++) {
        sales[i].viewSale();
    }
    cout << "\033[31mNo Record Available!\nPerform Sales to see the report!\033[00m";
    Sleep(2000);
}
void salesByCostumer(Sale* sales, Costumer costumer) {
    system("cls");
    cout << "Sales Report by Costumer :" << costumer.getName() << endl << endl;
    int size = sizeof(sales) / sizeof(Sale);
    for (int i = 0; i < size; i++) {
        if (sales[i].getId() == costumer.getId()) {
            sales[i].viewSale();
        }
    }
    cout << "\033[31mNo Record Available!\nPerform Sales to see the report!\033[00m";
    Sleep(2000);
}
void salesByProduct(Sale* sales, Product& product) {
    system("cls");
    cout << "Sales Report by Product :" << product.getName() << endl << endl;
    int size = sizeof(sales) / sizeof(Sale);
    for (int i = 0; i < size; i++) {
        if (sales[i].getId() == product.getID()) {
            sales[i].viewSale();
        }
    }
    cout << "\033[31mNo Record Available!\nPerform Sales to see the report!\033[00m";
    Sleep(2000);

}
void salesByDate(Sale* sales, string date) {
    system("cls");
    cout << "Sales Report by Date :" << date << endl << endl;
    int size = sizeof(sales) / sizeof(Sale);
    for (int i = 0; i < size; i++) {
        if (sales[i].getDate() == date) {
            sales[i].viewSale();
        }
    }
    cout << "\033[31mNo Record Available!\nPerform Sales to see the report!\033[00m";
    Sleep(2000);

}

Costumer findCostumer(Costumer* costumers, int id) {
    int size = sizeof(costumers) / sizeof(Costumer);
    for (int i = 0; i < size; i++) {
        if (costumers[i].getId() == id) {
            return costumers[i];
        }
    }
    return Costumer();
}
void viewSaleReport(Sale* sales, Inventory inventory , Costumer* costumers) {
    cout << "1. All Sales" << endl;
    cout << "2. Sales by Costumer" << endl;
    cout << "3. Sales by Product" << endl;
    cout << "4. Sales by Date" << endl;

    int choice;
    cin >> choice;
        int id;
        string date;
        

    switch (choice) {
    case 1:
        allSales(sales);
        break;
    case 2:
        cout << "Enter Costumer ID: ";
        cin >> id;

        salesByCostumer(sales, findCostumer(costumers, id));
        break;
    case 3: 
        cout << "Enter Product ID: ";
        cin >> id;
        salesByProduct(sales, inventory.getPro());
        break;
    case 4:
        cout << "Enter Date: ";
        cin >> date;
        salesByDate(sales, date);
        break;
    default:
        cout << "Invalid Choice!";
        break;
    }
}


#endif