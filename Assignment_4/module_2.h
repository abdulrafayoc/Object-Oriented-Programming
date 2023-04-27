#ifndef module_2
#define module_2

#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>

using namespace std;

class Costumer : public Inventory {
private:
    string name;
    int id;
    double totalCost = 0;
    static int counter;
    Inventory* inventroy;
public:
    Costumer() {
        name = "";
        id = counter;
        totalCost = 0;
        counter++;
    }
    Costumer(string name, Inventory* inv) {
        this->name = name;
        this->inventroy = inv;
    }

    string getName() {
        return name;
    }
    int getId() {
        return id;
    }
    void addtoCart(Product product, int quantity) {
        addProduct(product.getName(), product.getID(), quantity, product.getPrice());
        totalCost += product.getPrice() * quantity;
    }
    void removeFromCart(Product pro) {
        removeProduct(pro.getID());
    }
    void setTotalCost(double cost) {
        totalCost = cost;
    }
    double getTotalCost() {
        return totalCost;
    }
    int getCartSize() {
        return size;
    }
    void clearCart() {
        products = nullptr;
    }
    void viewCart() {
        cout << name << "'s Cart" << endl;
        viewInventory();
    }


};
int Costumer :: counter = 0; 


bool addToCart(Costumer costumer, Inventory inventory) {
    cout << endl << "What product would you like to add to your cart?";
    cout << endl << "Enter the ID of the product: ";
    int id;
    cin >> id;

    cout << endl << " How many products do you want to buy? ";
    cout << endl << "Enter the quantity : ";
    int quantity;
    cin >> quantity;

    if (inventory.findProduct(id) == -1) {
        cout << endl << "Product not found!" << endl;
        processing("Returning...", "");
        return false;
    }
    
    Product temp = inventory.getProductbyId(id);
    costumer.addtoCart(temp, quantity);

    inventory.getProductbyId(id).setQuantity(inventory.getProductbyId(id).getQuantity() - quantity);
    
    processing("Adding to cart...", "Product added to cart!");
    return true;

}

bool ApplyDiscount (Costumer costumer, Inventory inventory) { // check quantity >> recheck
    cout << endl << "What product would you like to apply discount to?";
    cout << endl << "Enter the ID of the product: ";
    int id;


    cin >> id;

    if (inventory.findProduct(id) == -1) {
        cout << endl << "Product not found!" << endl;
        processing("Returning...", "");
        return false;
    }

    cout << endl << " How many products do you want to buy? ";
    cout << endl << "Enter the quantity : ";
    int quantity;

    do {
        cin >> quantity;
        if (quantity > inventory.getProductbyId(id).getQuantity()) {
            cout << endl << "Not enough products in stock!" << endl;
            cout << endl << "Enter the quantity : ";
        }
        else if (quantity <= 0) {
            cout << endl << "Invalid quantity!" << endl;
            cout << endl << "Enter the quantity : ";
        }
    } while (quantity > inventory.getProductbyId(id).getQuantity() || quantity <= 0);

    cout << "Choose the Discount/Offer you would like to apply: " << endl;
    cout << "1. Ramadan Deal     : 10% discount" << endl;
    cout << "2. Eid Deal         : 20% discount" << endl;
    cout << "3. Independence Day : 30% discount" << endl;
    cout << "4. Blesses Friday   : 40% discount" << endl;
    cout << "5. Premium Member   : 50% discount" << endl;
    if (quantity % 2 == 0)
        cout << "6. But 1 Get 1 Free" << endl;
    else
        cout << "6. But 1 Get 1 Free (Not Applicable)" << endl;

    int choice;
    cin >> choice;

    if (choice == 6 && quantity % 2 != 0) {
        cout << endl << "Not Applicable!" << endl;
        processing("Returning...", "");
        return false;
    }

    double discount;
    switch (choice) {
    case 1:
        discount = 0.1;
        break;
    case 2:
        discount = 0.2;
        break;
    case 3:
        discount = 0.3;
        break;
    case 4:
        discount = 0.4;
        break;
    case 5:
        discount = 0.5;
        break;
    case 6:
        discount = 0.5;
        break;
    }
    costumer.setTotalCost(costumer.getTotalCost() - (costumer.getTotalCost() * discount));
    processing("Applying Discount...", "Discount Applied!");
    return true;
    
}

bool removeFromCart(Costumer costumer, Inventory inventory) {
    cout << endl << "What product would you like to remove from your cart?";
    cout << endl << "Enter the ID of the product: ";
    int id;
    cin >> id;

    if (costumer.findProduct(id) == -1) {
        cout << endl << "Product not found!" << endl;
        processing("Product not Found. \nReturning...", "");
        return false;
    }

    Product temp = costumer.getProductbyId(id);
    costumer.removeFromCart(temp);

    inventory.getProductbyId(id).setQuantity(inventory.getProductbyId(id).getQuantity() + costumer.getProductbyId(id).getQuantity());

    processing("Removing from cart...", "Product removed from cart!");
    return true;
}

#endif