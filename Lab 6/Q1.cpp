#include <iostream>

using namespace std;
class Holiday{
private:
    string name;
    int day;
    string month;

public:
    bool inSameMonth(Holiday h1, Holiday h2);
    double avgDate(Holiday arr[], int size);
    Holiday()
    {
        name = nullptr;
        day = 0;
        month = nullptr;
    }
    Holiday (string n, int d, string m)
    {
        n = name;
        d = day;
        m = month;
    }
    void setName(string n)
    {
        do
        {
            cout<<"Enter the name of the holiday: ";
            cin>>n;
        }while (n.length() > 50);

        n = name;
    }
    void setDay(int d)
    {
        do
        {
            cout<<"Enter the day of the holiday: ";
            cin>>d;
        } while(d<1 || d>31);

        d = day;
    }
    void setMonth(string m)
    {
        do
        {
            cout<<"Enter the month of the holiday: ";
            cin>>m;
        }while (m.length() > 10);

        m = month;
    }
    string getName()
    {
        return name;
    }
    int getDay()
    {
        return day;
    }
    string getMonth()
    {
        return month;
    }
    void print()
    {
        cout<<"Holiday: "<<name<<endl;
        cout<<"Day: "<<day<<endl;
        cout<<"Month: "<<month<<endl;
    }
    
};

bool Holiday::inSameMonth(Holiday h1, Holiday h2)
{
    if (h1.getMonth() == h2.getMonth())
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

double Holiday::avgDate(Holiday arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i].getDay();
    }
    return sum/size;
}
int main()
{
    
    return 0;
}