#include <iostream>
using namespace std;


class DayOfYear {
private:
    int day;
    string month;
    int date;
public:
    DayOfYear() {
        day = 1;
        calculateFullDate();
    }
    DayOfYear(int i) {
        day = i;
        calculateFullDate();
    }
    void calculateFullDate() {

        if (day > 0 && day < 31) {
            month = "January";
            date = day;
        } else if (day > 31 && day < 59) {
            month = "February";
            date = day - 31;
        } else if (day > 59 && day < 90) {
            month = "March";
            date = day - 59;
        } else if (day > 90 && day < 120) {
            month = "April";
            date = day - 90;
        } else if (day > 120 && day < 151) {
            month = "May";
            date = day - 120;
        } else if (day > 151 && day < 181) {
            month = "June";
            date = day - 151;
        } else if (day > 181 && day < 212) {
            month = "July";
            date = day - 181;
        } else if (day > 212 && day < 243) {
            month = "August";
            date = day - 212;
        } else if (day > 243 && day < 273) {
            month = "September";
            date = day - 243;
        } else if (day > 273 && day < 304) {
            month = "October";
            date = day - 273;
        } else if (day > 304 && day < 334) {
            month = "November";
            date = day - 304;
        } else if (day > 334 && day < 365) {
            month = "December";
            date = day - 334;
        } else {
            month = "January";
            date = 1;
        }
    }
    DayOfYear operator+ (int val) {
        DayOfYear temp;
        temp.day = day + val;
        temp.calculateFullDate();
        return temp;
    }
    DayOfYear operator+= (DayOfYear &right) {
        day += right.day;
        calculateFullDate();
        return *this;
    }
    DayOfYear operator-= (DayOfYear &right) {
        day -= right.day;
        calculateFullDate();
        return *this;
    }
    DayOfYear operator = (DayOfYear &right) {
        this->day = right.day;
        this->date =  right.date;
        this->month = right.month;
        return *this;
    }
    bool operator == (DayOfYear &right) {
        return (this->day == right.day);
    }
    DayOfYear operator ++ () {
        this->day++;
        return* this;
    }
    DayOfYear operator -- () {
        this->day--;
        return* this;
    }
    DayOfYear operator ++ (int) {
        DayOfYear temp;
        temp.day = this->day;
        this->day++;
        return temp;
    }
    DayOfYear operator -- (int) {
        DayOfYear temp;
        temp.day = this->day;
        this->day--;
        return temp;
    }
    friend ostream& operator << ( ostream& out,DayOfYear &right) {
        out<<right.date << " " << right.month;
        return out;
    }
    istream& operator >> (DayOfYear &right) {
        cout<<"Enter day of the Year: ";
        cin>>right.day;
        right.calculateFullDate();
        return cin;
    }
    
    

};

int main() {
    DayOfYear d1(100);
    DayOfYear d2(200);
    cout<<d2;
    return 0;
}