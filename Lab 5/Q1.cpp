#include <iostream>

using namespace std;

//Build a class Sale with private member variables
class Sale
{
private:
    double itemCost;
    double taxRate;

public:
    Sale()
    {
        itemCost = 0;
        taxRate = 0;
    }
    Sale( double cost, double rate)
    {
        itemCost = cost;
        taxRate = rate;
    }
    double getTax( )
    {
        return itemCost * taxRate;
    }
    double getTotal( )
    {
        return itemCost + getTax();
    }
    void getitemCost()
    {
        cout << "Enter the cost of the item: ";
        cin >> itemCost;
    }
    void gettaxRate()
    {
        cout << "Enter the tax rate: ";
        cin >> taxRate;
    }
};