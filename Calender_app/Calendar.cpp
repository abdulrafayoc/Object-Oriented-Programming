 #include <iostream>
#include <iomanip>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;



class event {
private:
    string name;
    int sec;
    int min;
    int hour;
    int day;
    int month;
    int year;
    static int count;
public:
    string getName() {
        return name;
    }
    int getSec() {
        return sec;
    }
    int getMin() {
        return min;
    }
    int getHour() {
        return hour;
    }
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }
    int getCount() {
        return count;
    }
    void setName(string n) {
        name = n;
    }
    void setSec(int s) {
        sec = s;
    }
    void setMin(int m) {
        min = m;
    }
    void setHour(int h) {
        hour = h;
    }
    void setDay(int d) {
        day = d;
    }
    void setMonth(int m) {
        month = m;
    }
    void setYear(int y) {
        year = y;
    }
    void setCount(int c) {
        count = c;
    }
    friend ostream& operator << (ostream& out, const event& e);
    friend istream& operator >> (istream& in, event& e);
    friend event operator - (event e1);
    friend event operator + (event e1);
    event() {
        name = "Empty Event";
        sec = 0;
        min = 0;
        hour = 0;
        day = 0;
        month = 0;
        year = 0;
    }
    event(string n, int s, int m, int h, int d, int mo, int y) {
        name = n;
        sec = s;
        min = m;
        hour = h;
        day = d;
        month = mo;
        year = y;
    }
    event operator = (event e1) {
        this->setName(e1.getName());
        this->setSec(e1.getSec());
        this->setMin(e1.getMin());
        this->setHour(e1.getHour());
        this->setDay(e1.getDay());
        this->setMonth(e1.getMonth());
        this->setYear(e1.getYear());
        return *this;
    }
    event current() {
        time_t now = time(0);
        tm* current_time = localtime(&now);
        return event("Today", current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900);
    }
    event operator + (event& e1) {
        event e2;
        int s = e1.getSec() + this->getSec();
        int m = e1.getMin() + this->getMin();
        int h = e1.getHour() + this->getHour();
        int d = e1.getDay() + this->getDay();
        int mo = e1.getMonth() + this->getMonth();
        int y = e1.getYear() + this->getYear();
        if (s > 60) {
            s -= 60;
            m++;
        }
        if (m > 60) {
            m -= 60;
            h++;
        }
        if (h > 24) {
            h -= 24;
            d++;
        }
        if (d > 30) {
            d -= 30;
            mo++;
        }
        if (mo > 12) {
            mo -= 12;
            y++;
        }
        event e3(e1.getName(), s, m, h, d, mo, y);
        return e3;
    }

    event operator - (event& e1) {
        int s = this->getSec() - e1.getSec();
        int m = this->getMin() - e1.getMin();
        int h = this->getHour() - e1.getHour();
        int d = this->getDay() - e1.getDay();
        int mo = this->getMonth() - e1.getMonth();
        int y = this->getYear() - e1.getYear();
        if (s < 0) {
            s += 60;
            m--;
        }
        if (m < 0) {
            m += 60;
            h--;
        }
        if (h < 0) {
            h += 24;
            d--;
        }
        if (d < 0) {
            d += 30;
            mo--;
        }
        if (mo < 0) {
            mo += 12;
            y--;
        }
        event e3("Time Left till Event:", s, m, h, d, mo, y);
        return e3;
    }
};

int event ::count = 0;
ostream& operator << (ostream& out, const event& e) {
    out << "----------------------------------"<< endl;
    out << "Event name: " << e.name << endl;
    cout << "SS : MM : HH  |  DD - MM - YYYY" << endl;
    out << setfill('0') << setw(2) << e.sec << " : " << setfill('0') << setw(2) << e.min << " : " << setfill('0') << setw(2) << e.hour << "  |  ";
    out << setfill('0') << setw(2) << e.day << " - " << setfill('0') << setw(2) << e.month << " - " << setfill('0') << setw(4) << e.year << endl;
    out << "----------------------------------"<< endl;
    return out;
}
istream& operator >> (istream& in, event& e) {
    cout << "\n\nEnter name of event: ";
    cin >> e.name;
    cout << "Enter day : ";
    do {
        cin >> e.day;
        if (e.day < 1 || e.day>31) {
            cout << "Invalid day. Please enter again: ";
        }
    } while (e.day < 1 || e.day>31);

    cout << "Enter month : ";
    do {
        cin >> e.month;
        if (e.month < 1 || e.month>12) {
            cout << "Invalid month. Please enter again: ";
        }
    } while (e.month < 1 || e.month>12);

    cout << "Enter year : ";
    do {
        cin >> e.year;
        if (e.year < 0) {
            cout << "Invalid year. Please enter again: ";
        }
    } while (e.year < 0);

    cout << "Enter hour : ";
    do {
        cin >> e.hour;
        if (e.hour < 0 || e.hour>23) {
            cout << "Invalid hour. Please enter again: ";
        }
    } while (e.hour < 0 || e.hour>23);

    cout << "Enter minute : ";
    do {
        cin >> e.min;
        if (e.min < 0 || e.min>59) {
            cout << "Invalid minute. Please enter again: ";
        }
    } while (e.min < 0 || e.min>59);

    cout << "Enter second : ";
    do {
        cin >> e.sec;
        if (e.sec < 0 || e.sec>59) {
            cout << "Invalid second. Please enter again: ";
        }
    } while (e.sec < 0 || e.sec>59);
    return in;

}

event operator + (event e1) {
    event e2 = e2.current();
    int s = e1.getSec() + e2.getSec();
    int m = e1.getMin() + e2.getMin();
    int h = e1.getHour() + e2.getHour();
    int d = e1.getDay() + e2.getDay();
    int mo = e1.getMonth() + e2.getMonth();
    int y = e1.getYear() + e2.getYear();

    event e3("Events added:", s, m, h, d, mo, y);
    return e3;
}

void newEvent(event* e, int i) {
    e->setCount(i);
    cin >> *(e + i - 1);
    cout << "\nEvent created successfully" << endl;
    cout << *(e + i - 1);
}

void print(event* e) {
    for (int i = 0; i < e->getCount(); i++)
    {
        cout << "\n\n>Event " << i + 1 << ":" << endl;
        cout << *(e + i);
    }
}
void viewEvent(event* e) {
    cout << "\n\nWhich event do you want to view?:";
    int n;
    cin >> n;
    cout << *(e + n - 1);
    event left;
    event current = current.current();
    left = *(e + n - 1) - current;  //Time left till event error here
    cout << left;
}

void newExisting(event* e, int i) {
	e->setCount(i);
	cout << "Enter the event number you want to add to: ";
	int n;
	cin >> n;
    
    event obj;
    cout << "Enter the date and time you want to add to " << n << "Event :\n";
    cin >> obj;
	cout << *(e + n - 1) + obj;
    event add = *(e + n - 1) + obj;
	cout << "\nEvent created successfully" << endl;
	//cout << *(e + i - 1);
    *(e + i - 1) = add;
}
void menu(event* e)
{
    cout << "Total events: " << e->getCount() << endl;
    cout << "1. Create new event" << endl;
	cout << "2. Add New event from Existing Event" << endl;
    cout << "3. View Existing Event" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        newEvent(e, e->getCount() + 1);
        break;
	case 2:
        print(e);
		newExisting(e, e->getCount() + 1);
		break;
    case 3:
        print(e);
        viewEvent(e);
        break;
    case 4:
        cout << "\nClosing Calender<!>";
        return;
        break;
    default:
        cout << "Invalid choice. Please enter again: ";
        menu(e);
        break;
    }
    menu(e);
}

int main() {
    event* e = new event[3];
    menu(e);

    delete[] e;
    return 0;
}
