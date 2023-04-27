#ifndef module_1
#define module_1

#include <iostream>
#include <string>
#include <windows.h>
#include <stdlib.h>

using namespace std;


void processing(string msg, string dmsg) {
    system("cls");
    cout << endl << endl << "\033[33m" << msg<< endl;
    for (int i = 0; i < 10; i++) {
        cout << ".";
        Sleep(400);
    }
    cout << endl << "\033[32m" << dmsg << "\033[m" << endl;
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
    /*Product(Product& product) {
        name = product.name;
        id = product.id;
        quantity = product.quantity;
        price = product.price;
    }*/
    void copyProduct(Product product) {
        name = product.name;
        id = product.id;
        quantity = product.quantity;
        price = product.price;
    }
    Product& operator=(Product& product) {
        name = product.name;
        id = product.id;
        quantity = product.quantity;
        price = product.price;
        return *this;
    }
    Product& operator=(const Product& product) {
        name = product.name;
        id = product.id;
        quantity = product.quantity;
        price = product.price;
        return *this;
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
    void setQuantity(int qu){
        quantity = qu;
    }
    void setPrice(double pr){
        price = pr;
    }
    void viewProduct() {
        cout << "\033[94m-------  Product  -------\033[00m" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: " << price << endl;
        cout << "\033[94m-------------------------\033[00m" << endl;
    }
};

void setPrice(Product& product, double price) {
    product.setPrice(price);
}

class Inventory {
protected:
    int size;
    Product* products;
public:
    Inventory() {
        size = 0;
        products = new Product[1];
    }
    int getSize() {
        return size;
    }
    Product getProductbyId(int id) {
        for (int i = 0; i < size; i++) {
            if (products[i].getID() == id) {
                return products[i];
            }
        }
        cout << endl << "Product not found!" << endl;
        return Product();
    }
    Product& getPro() {
        return products[0];
    }
    Product getProducts(int i) {
        if (i < size) {
            return products[i];
        }
        else {
            cout << endl << "Product not found!" << endl;
        }
        return Product();
    }
    int findProduct(int id) {
        for (int i = 0; i < size; i++) {
            if (products[i].getID() == id) {
                return i;
            }
        }
        // cout << endl << "Product not found!" << endl;
        return -1;
    }
    void addProduct(string name, int id, int quantity, double price) {
        Product* temp;
        temp = new Product[size + 1];
    
        for (int i = 0; i < size; i++) {
            temp[i] = products[i];
        }
    
        temp[size] = Product(name, id, quantity, price);
        delete[] products;
        products = temp;
        size++;
        cout << "\033[32mProduct Added: \033[00m " << name << " with ID " << id << " and quantity " << quantity << " and price " << price << "index " << size << endl;
    }
    void setProPrice(int index, double pri) {
        products[index].setPrice(pri);
    }
    bool removeProduct(int id) {
        if (size == 0) {
            cout << "No product Found, Empty!" << endl;
            return false;
        }
        else if (findProduct(id) == -1) {
            cout << "Product not found" << endl;
            return false;
        }
        else {
            for (int i = 0; i < size; i++) {
                if (products[i].getID() == id) {
                    Product* temp = new Product[size - 1];
                    for (int j = 0; j < i; j++) {
                        temp[j] = products[j];
                    }
                    for (int j = i; j < size - 1; j++) {
                        temp[j] = products[j + 1];
                    }
                    delete[] products;
                    products = temp;
                    size--;
                    return true;
                    break;
                }
                else if (i == size - 1) {
                    return false;
                }
            }
        }
        return false;
    }
    void viewInventory() {
        cout << "-------  Inventory  -------" << endl;
        cout << "Size of Inventory: " << size << endl << endl;
        for (int i = 0; i < size; i++) {
            cout << "Index: " << i << endl;
            products[i].viewProduct();
        }
    }
};



class Supplier : public Inventory {
private:
    int id;
    string name;
public:
    Supplier() {
        id = 0;
        name = "";
    }
    Supplier(int id, string name) {
        this->id = id;
        this->name = name;
    }
    void addProduct(string name, int id, int quantity, double price) {
        Inventory::addProduct(name, id, quantity, price);
    }
    
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }

};

class Order {
private:
    int supId;
    int quantity;
    double price;
    double total;
    Product product;
    Supplier* supplier;
public:
    Order() {
        cout << "new Order Created" << endl;
        supId = 0;
        quantity = 0;
        price = 0;
        total = 0;
    }  
    Order(Supplier *supp, int proId, int quan) {
        supId = supp->getId();
        quantity = quan;

        supplier = supp;

        price = supp->getProductbyId(proId).getPrice();
        total = price * quan;
        
        product = (supp->getProductbyId(proId));
    }
    Order(const Order& order) {
        supId = order.supId;
        quantity = order.quantity;
        price = order.price;
        total = order.total;
        product = order.product;
        supplier = order.supplier;
    }
    // Order& operator=(const Order& order) {
    //     supId = order.supId;
    //     quantity = order.quantity;
    //     price = order.price;
    //     total = order.total;
    //     product = order.product;
    //     return *this;
    // }
    int getSupID() {
        return supId;
    }
    int getProductID() {
        return product.getID();
    }
    int getQuantity() {
        return quantity;
    }
    double getPrice() {
        return price;
    }
    double getTotal() {
        return total;
    }
    Supplier getSupplier() {
        return *supplier;
    }
    string getProductName() {
        return product.getName();
    }
    void viewOrder() {
        cout << "\033[94m-------  Order  -------\033[00m" << endl;
        cout << "Supplier ID: " << supId << endl;
        cout << "Product: " << product.getName() << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price per product: " << price << endl;
        cout << "Total bill: " << total << endl;
        cout << "\033[94m-----------------------\033[00m" << endl << endl;
    }

    
};

void addOrder(Order* orders, Order order){
    Order* temp;
    static int size = 0; 

    cout << "total orders: " << size << endl;
    temp = new Order[size + 1];
    cout << "temp created" << endl;
    for (int i = 0; i < size; i++) {
        temp[i] = *(orders + i);
    }
    cout << "copying orders" << endl;
    temp[size] = Order(order);
    cout << "new order added" << endl;
    delete[] orders;
    cout << "orders freed" << endl;
    orders = temp;
    cout << "orders copied" << endl;
    size++;

    cout << "Ordering..." << endl;
    cout << "Product Ordered!" << endl;
    orders[size - 1].viewOrder();
    return;
}

bool orderProduct(Inventory inventory, Supplier* supplier, Order* orders) {
    cout<<"What product would you like to order? \nEnter Product ID:";
    int proID;
    cin >> proID;

    static int supSize = 2;
    cout << "There are " << supSize << " suppliers" << endl;
    int index;

    index = inventory.findProduct(proID);

    // inventory.getProducts(index).viewProduct();
    // Sleep(3000);


    if (index == -1) {
        cout << "Product doesn't Exist in inventory." << endl;
    }
    else if (inventory.getProducts(index).getQuantity() < 100) {
        cout << "Quantity is less than 100 in inventory." << endl;
    }
    else {
        cout << "Product is already in stock!" << endl;
        processing("Product is already in stock!\nCanceling Order...", "Order Canceled!");
        return false;
    }
    
    int supIndex;

    for (int j = 0; j < supSize; j++) {
        if (supplier[j].findProduct(proID) == -1){
            cout << "Supplier " << j + 1 << " do not have product!" << endl; 
            if (j == supSize - 1) {
                cout << "No supplier has product!" << endl;
                processing("No supplier has product!\nCanceling Order...", "Order Canceled!");
                return false;
            }
        }
        else {
            cout << "Supplier " << j + 1 << " do have this product!!" << endl; 
            supIndex = j;
            supplier[j].getProductbyId(proID).viewProduct();
            break;
        }
    }

    cout << "How many would you like to order? : ";
    int qu;
    do {
        cin >> qu;
        if (qu > supplier[supIndex].getProducts(supIndex).getQuantity()) {
            cout << "Quantity must not be greater than Supplier's!\nTry again: ";
        }
        else {
            break;
        }
    } while (qu > supplier[supIndex].getProductbyId(proID).getQuantity());


    Order view(&supplier[supIndex], proID, qu);
    cout << "\033[94mOrder details: \033[00m" << endl;
    view.viewOrder();

    cout << "Would you like to order from this supplier? (Y/N)" << endl;
    char choice;
    do {
        cin >> choice;
        if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
            break;
        }
        else {
            cout << "Invalid input!\nTry again: ";
        }
    } while (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N');
    
    if (choice == 'y' || choice == 'Y') {
        cout << "Ordering product..." << endl;
        
        addOrder(orders, Order(&supplier[supIndex], proID, qu));
        
        int temp = supplier[supIndex].getProductbyId(proID).getQuantity();
        supplier[supIndex].getProductbyId(proID).setQuantity(temp - qu);

        processing("Ordering product...", "Product ordered!");
        return true;
    }
    else if (choice == 'n' || choice == 'N') {
        cout << "Canceling order..." << endl;
        processing("Canceling order...", "Order canceled!");
        return false;
    }
    else {
        cout << "Invalid input!" << endl;
        processing("Invalid input!\nCanceling order...", "Order canceled!");
        return false;
    }

}

void takeProduct(Inventory inventory, Supplier supplier, Order* orders) {
    for (int i = 0; i < sizeof(orders)/sizeof(Order); i++) {
        cout << "Order ID: 00" << i + 1 << endl;
        orders[i].viewOrder();
    }

    cout << "What Order would you like to take?" <<endl;

    int orderID;
    cin >> orderID;

    if (orderID > sizeof(orders)/sizeof(orders[0])) {
        cout << "Order ID not found!" << endl;
        return;
    }

    cout << "Order ID found!" << endl;

    int proID = orders[orderID - 1].getProductID();

    int invQuan = inventory.getProductbyId(proID).getQuantity() + orders->getQuantity();
    inventory.getProductbyId(proID).setQuantity(invQuan);

    int supQuan = supplier.getProductbyId(proID).getQuantity() - orders->getQuantity();
    supplier.getProductbyId(proID).setQuantity(supQuan);
    
    processing("Taking product...", "Product taken!");

    
    cout << "The quantity on Inventory is now: " << inventory.getProducts(orders->getProductID()).getQuantity() << endl;
    
    
    // cout << "What product would you like to take?" <<endl;
    // cout << "Enter Product ID:";
    // int proID;
    // cin >> proID;

    // // static int supSize = 2;
    // int index;

    // for (int i = 0; i < 10; i++) {
    //     if (proID == inventory.getProducts(i).getID()) {
    //         cout << "Product ID found!" << endl;
    //         index = i;
    //         break;
    //     }
    //     else {
    //         cout << "Product ID not found!" << endl;
    //     }
    // }
    
    // int supIndex;
    // for (int i = 0; i < 5; i++) {
    //     if (proID == supplier.getProducts(i).getID()) {
    //         cout << "Supplier has product!" << endl;
    //         supIndex = i;
    //         break;
    //     }
    //     else {
    //         cout << "Supplier does not have product!" << endl;
    //         processing("Supplier does not have product!\nCanceling Order...", "Order Canceled!");
    //     }
    // }
    
    // int quantity = inventory.getProducts(index).getQuantity() + supplier.getProducts(supIndex).getQuantity();

    // processing("Taking product...", "Product taken!");

    // inventory.getProducts(index).setQuantity(quantity);
    // supplier.getProducts(supIndex).setQuantity(0);
    
    // cout << "The quantity is now: " << inventory.getProducts(index).getQuantity() << endl;
    
}

void managePrice(Inventory inventory) {
    cout << "What product would you like to set/update the price of?" <<endl;
    cout << "Enter Product ID:";
    int proID;
    cin >> proID;
    
    if (inventory.findProduct(proID) == -1) {
        cout << "Product ID not found!" << endl;
        return;
    }
    
    cout << "Product ID found!" << endl;

    inventory.getProductbyId(proID).viewProduct();
    
    int index = inventory.findProduct(proID);

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
        cout << "1. Ramadan Deal     : 10% discount" << endl;
        cout << "2. Eid Deal         : 20% discount" << endl;
        cout << "3. Independence Day : 30% discount" << endl;
        cout << "4. Blesses Friday   : 40% discount" << endl;
        cout << "5. Premium Member   : 50% discount" << endl;
        cout << "6. Costum Discount" << endl;
        
        int swi;
        cin >> swi;

        double discount;
        


        switch (swi) {
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
            cout << "What is the discount in percentage?" << endl;
            cin >> discount;
            discount /= 100;
            if (discount < 0) {
                cout << "Discount cannot be negative!" << endl;
                return;
            }
        }
        
        double price = inventory.getProducts(index).getPrice();
        price *+ discount;
        // setPrice(inventory.getProductbyId(proID),price);
        // inventory.getProductAddress(index).setPrice(price);
        inventory.setProPrice(index, price);
        
        processing("Updating Price...", "Price Updated!");  
    }
    else {
        cout << "Invalid choice!" << endl;
        return;
    }
}



#endif