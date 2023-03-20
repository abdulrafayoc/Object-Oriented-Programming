#include <iostream>

using namespace std;

class Pizza
{
    char *name;
    char *topping;
    char *size;
    bool is_ready;
    double price;
public:
    Pizza()
    {
        
    }
    Pizza(char *toppingVal, double priceVal)
    {
        topping = toppingVal;
        price = priceVal;

    }
    Pizza(char *toppingVal, double priceVal, char* nameVal, char* sizeVal, bool ready_status)
    {
        topping = toppingVal;
        price = priceVal;
        name = nameVal;
        size = sizeVal;
        is_ready = ready_status;
    }
    Pizza(const Pizza &pizza)
    {
        topping = pizza.topping;
        price = pizza.price;
        name = pizza.name;
        size = pizza.size;
        is_ready = pizza.is_ready;
    }
    void setTopping(char *toppingVal)
    {
        topping = toppingVal;
    }
    void setPrice(double priceVal)
    {
        price = priceVal;
    }
    void setName(char *nameVal)
    {
        name = nameVal;
    }
    void setSize(char *sizeVal)
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
        if(topping != NULL)
        {
            is_ready = true;
        }
    }
    bool Chaeck_status()
    {
        return is_ready;
    }
};