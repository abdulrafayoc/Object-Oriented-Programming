#include <iostream>

using namespace std;

class Date 
{
private:
    int month;
    int day;
    int year;
public:
    Date(int year, int month, int day)
    {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    void addDay(int days)
    {
        day += days;
        if (day > 30)
        {
            month++;
            day -= 30;
        }
        if (month > 12)
        {
            year++;
            month -= 12;
        }
    }
    void add(int months, int days)
    {
        day += days;
        if (day > 30)
        {
            month++;
            day -= 30;
        }
        if (month > 12)
        {
            year++;
            month -= 12;
        }
        month += months;
        if (month > 12)
        {
            year++;
            month -= 12;
        }
    }
    void addWeek(int weeks)
    {
        day += weeks*7;
        if (day > 30)
        {
            month++;
            day -= 30;
        }
        if (month > 12)
        {
            year++;
            month -= 12;
        }
    }
    void subtractDay(int days)
    {
        day -= days;
        if (day < 1)
        {
            month--;
            day += 30;
        }
        if (month < 1)
        {
            year--;
            month += 12;
        }
    }
    void subtract(int months , int days)
    {
        day -= days;
        if (day < 1)
        {
            month--;
            day += 30;
        }
        if (month < 1)
        {
            year--;
            month += 12;
        }
        month -= months;
        if (month < 1)
        {
            year--;
            month += 12;
        }
    }
    int getDay()
    {
        return day;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
    }

    bool isLeapYear()
    {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    string toString()
    {
        string str = int2string(year) + "/" + int2string(month) + "/" + int2string(day);
        return str;
    }
    string int2string(int num)
    {
        int temp = num;
        string str = "";
        while (temp > 0)
        {
            str = char(temp % 10 + 48) + str;
            temp /= 10;
        }
        return str;
    }
};

int main()
{
    return 0;
}