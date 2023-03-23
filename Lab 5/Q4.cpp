#include <iostream>

using namespace std;

class CoffeeShots
{
private:
    string type = "capuccino";
    double price;
    float volume;
    char size ='l';

public:
CoffeeShots(double price, float volume)
{
    this->price = price;
    this->volume = volume;
    if(volume < 50)
    {
        size = 's';
    }
    else if(volume < 75)
    {
        size = 'm';
    }
    else if(volume > 75)
    {
        size = 'l';
    }
}
CoffeeShots(string type, double price, float volume)
{
    this->type = type;
    this->price = price;
    this->volume = volume;
    if(volume < 50)
    {
        size = 's';
    }
    else if(volume < 75)
    {
        size = 'm';
    }
    else if(volume > 75)
    {
        size = 'l';
    }
}
    string getType()
    {
        return type;
    }
    double getPrice()
    {
        return price;
    }
    float getVolume()
    {
        return volume;
    }
    char getSize()
    {
        return size;
    }
    void setPrice(double price)
    {
        this->price = price;
    }
    void upSize()
    {
        volume += 5;
        price += 5;
    }
    void spillOver(float spilled)
    {
        volume -= spilled;
    }

};
CoffeeShots* createMyCoffee()
{
    string type;
    double price;
    float volume;
    cout << "Enter the type of coffee: ";
    cin >> type;
    cout << "Enter the price of the coffee: ";
    cin >> price;
    cout << "Enter the volume of the coffee: ";
    cin >> volume;

    CoffeeShots *myCoffee = new CoffeeShots(type, price, volume);

    cout << "The type of coffee is: " << myCoffee->getType() << endl;
    cout << "The price of the coffee is: " << myCoffee->getPrice() << endl;
    cout << "The volume of the coffee is: " << myCoffee->getVolume() << endl;
    cout << "The size of the coffee is: " << myCoffee->getSize() << endl;
    cout<<"The coffee has been spilled by ml";
    int spilled;
    cin>>spilled;
    myCoffee->spillOver(spilled);
    cout << "The coffee has been upsized by 5ml" ;
    myCoffee->upSize();
    cout << "The new volume of the coffee is: " << myCoffee->getVolume() << endl;
    cout << "The new price of the coffee is: " << myCoffee->getPrice() << endl;
    cout << "The new size of the coffee is: " << myCoffee->getSize() << endl;
    return myCoffee;
}

int main()
{
    createMyCoffee();
    return 0;
}
