#include <iostream>
using namespace std;

class Pizza
{
    char* name;
    char* topping;
    char* size;
    bool is_ready;
    double price;
public:
    Pizza()
    {
        name = new char[1];
        topping = new char[1];
        size = new char[1];
        *name = '\0';
        *topping = '\0';
        *size = '\0';
        is_ready = false;
        price = 0;
    }
    Pizza(char* toppingVal, double priceVal)
    {
        topping = toppingVal;
        price = priceVal;
    }
    Pizza(char* toppingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status)
    {
        topping = toppingVal;
        price = priceVal;
        name = nameVal;
        size = sizeVal;
        is_ready = ready_status;
    }
    Pizza(const Pizza& pizza)
    {
        topping = pizza.topping;
        price = pizza.price;
        name = pizza.name;
        size = pizza.size;
        is_ready = pizza.is_ready;
    }
    void setTopping(char* toppingVal)
    {
        topping = toppingVal;
    }
    void setPrice(double priceVal)
    {
        price = priceVal;
    }
    void setName(char* nameVal)
    {
        name = nameVal;
    }
    void setSize(char* sizeVal)
    {
        size = sizeVal;
    }
    char* getTopping()
    {
        return topping;
    }
    double getPrice()
    {
        return price;
    }
    char* getName()
    {
        return name;
    }
    char* getSize()
    {
        return size;
    }
    void makePizza()
    {
        if (topping != NULL)
        {
            is_ready = true;
        }
    }
    bool Chaeck_status()
    {
        return is_ready;
    }
};

int main()
{
    char* topping = new char[7];
    cin >> topping;
    char* name = new char[12];
    cin >> name;
    char* size = new char[6];
    cin >> size;
    Pizza pizza1;
    Pizza pizza2(topping, 100);
    Pizza pizza3(topping, 100, name, size, false);
    Pizza pizza4(pizza3);
    pizza4.setTopping(topping);
    pizza4.setPrice(200);
    pizza4.setName(name);
    pizza4.setSize(size);
    pizza4.makePizza();
    cout << "Pizza 1 Topping: " << pizza1.getTopping() << endl;
    cout << "Pizza 1 Price: " << pizza1.getPrice() << endl;
    cout << "Pizza 1 Name: " << pizza1.getName() << endl;
    cout << "Pizza 1 Size: " << pizza1.getSize() << endl;
    cout << "Pizza 1 Status: " << pizza1.Chaeck_status() << endl;
    cout << "Pizza 2 Topping: " << pizza2.getTopping() << endl;
    cout << "Pizza 2 Price: " << pizza2.getPrice() << endl;
    cout << "Pizza 2 Name: " << pizza2.getName() << endl;
    cout << "Pizza 2 Size: " << pizza2.getSize() << endl;
    cout << "Pizza 2 Status: " << pizza2.Chaeck_status() << endl;
    cout << "Pizza 3 Topping: " << pizza3.getTopping() << endl;
    cout << "Pizza 3 Price: " << pizza3.getPrice() << endl;
    cout << "Pizza 3 Name: " << pizza3.getName() << endl;
    cout << "Pizza 3 Size: " << pizza3.getSize() << endl;
    cout << "Pizza 3 Status: " << pizza3.Chaeck_status() << endl;
    cout << "Pizza 4 Topping: " << pizza4.getTopping() << endl;
    cout << "Pizza 4 Price: " << pizza4.getPrice() << endl;
    cout << "Pizza 4 Name: " << pizza4.getName() << endl;
    cout << "Pizza 4 Size: " << pizza4.getSize() << endl;
    cout << "Pizza 4 Status: " << pizza4.Chaeck_status() << endl;
    return 0;
}