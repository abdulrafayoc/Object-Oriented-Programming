#include <iostream>

using namespace std;

class Distance
{
private:
    int feet;
    int inches;
public:
    Distance(int f = 0, int i = 0)
    {
        feet = f;
        if (i > 12)
        {
            feet += i / 12;
            inches = i % 12;
        }
        else
        {
            inches = i;
        }
    }
    Distance(int i)
    {
        feet = i / 12;
        inches = i - (feet * 12);
    }
    void setFeet(int f)
    {
        feet = f;
    }
    void setInches(int i)
    {
        inches = i;
    }
    int getFeet() const
    {
        return feet;
    }
    int getInches() const
    {
        return inches;
    }
    Distance operator+(const Distance &obj)
    {
        Distance temp;
        temp.feet = obj.feet + this->feet;
        temp.inches = obj.inches + this->inches;
        if (temp.inches > 12)
        {
            temp.feet += temp.inches / 12;
            temp.inches =  temp.inches - (temp.feet * 12);
        }
        return obj;
    }
    Distance operator-(const Distance &obj)
    {
        Distance temp;
        temp.feet = this->feet - obj.feet;
        temp.inches = this->inches - obj.inches;
        if (temp.inches < 0)
        {
            temp.feet -= 1;
            temp.inches = 12 + temp.inches;
        }
        return obj;
    }
    bool operator>(const Distance &obj)
    {
        if (this->feet > obj.feet)
        {
            return true;
        }
        else if (this->feet == obj.feet)
        {
            if (this->inches > obj.inches)
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
    bool operator<(const Distance &obj)
    {
        if (this->feet < obj.feet)
        {
            return true;
        }
        else if (this->feet == obj.feet)
        {
            if (this->inches < obj.inches)
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
    const Distance operator=(const Distance &obj)
    {
        this->feet = obj.feet;
        this->inches = obj.inches;
        return obj;
    }
    
};