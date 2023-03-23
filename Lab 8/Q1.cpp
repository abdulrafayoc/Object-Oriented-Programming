#include <iostream>

using namespace std;

class Money{
private:
    int dollars;
    int cents;
public:
    Money()
    {
        dollars = 0;
        cents = 0;
    }
    Money(int dollars, int cents)
    {
        this->dollars = dollars;
        this->cents = cents;
    }
    Money operator= (const Money& right)
    {
        this->dollars = right.dollars;
        this->cents = right.cents;
        return right;
    }
    Money operator+ (const Money& right)
    {
        this->dollars += right.dollars;
        this->cents += right.cents;
    }
    Money operator- (const Money& right)
    {
        this->dollars -= right.dollars;
        this->cents -= right.cents;
    }
    bool operator< (const Money& right)
    {
        if(this->dollars < right.dollars)
            {
                return true;
            }
        else if(this->dollars == right.dollars)
        {
            if(this->cents < right.cents)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    bool operator> (const Money& right)
    {
        if(this->dollars > right.dollars)
            {
                return true;
            }
        else if(this->dollars == right.dollars)
        {
            if(this->cents > right.cents)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    ~Money()
    {
        
    }

};
int main()
{
    
}