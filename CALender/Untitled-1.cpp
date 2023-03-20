#include <iostream>
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
    //friend event operator + (event e1);
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
        event e2;
        e2.setName(e1.getName());
        e2.setSec(e1.getSec());
        e2.setMin(e1.getMin());
        e2.setHour(e1.getHour());
        e2.setDay(e1.getDay());
        e2.setMonth(e1.getMonth());
        e2.setYear(e1.getYear());
        return e2;
    }
    event current() {
        time_t now = time(0);
        tm* current_time = localtime(&now);
        return event("Today", current_time->tm_hour, current_time->tm_min, current_time->tm_sec, current_time->tm_mday, current_time->tm_mon + 1, current_time->tm_year + 1900);
    }
	event operator + (event e1) {
		event e2;
		e2.setSec(e1.getSec() + sec);
		e2.setMin(e1.getMin() + min);
		e2.setHour(e1.getHour() + hour);
		e2.setDay(e1.getDay() + day);
		e2.setMonth(e1.getMonth() + month);
		e2.setYear(e1.getYear() + year);
		return e2;
	}
};
int event ::count = 0;
ostream& operator << (ostream& out, const event& e) {
    out << "Event name: " << e.name << endl;
    out << "Time :" << e.sec << ":" << e.min << ":" << e.hour;
    out << "Date :" << e.day << "-" << e.month << "-" << e.year;
    cout<<endl<<endl;
    return out;
}
istream& operator >> (istream& in, event& e) {
    cout << "Enter name of event: ";
    cin >> e.name;
    cout << "\nEnter day of event: ";
    do {
        cin >> e.day;
        if (e.day < 1 || e.day>31) {
            cout << "Invalid day. Please enter again: ";
        }
    } while (e.day < 1 || e.day>31);

    cout << "\nEnter month of event: ";
    do {
        cin >> e.month;
        if (e.month < 1 || e.month>12) {
            cout << "Invalid month. Please enter again: ";
        }
    } while (e.month < 1 || e.month>12);

    cout << "\nEnter year of event: ";
    do {
        cin >> e.year;
        if (e.year < 0) {
            cout << "Invalid year. Please enter again: ";
        }
    } while (e.year < 0);

    cout << "\nEnter hour of event: ";
    do {
        cin >> e.hour;
        if (e.hour < 0 || e.hour>23) {
            cout << "Invalid hour. Please enter again: ";
        }
    } while (e.hour < 0 || e.hour>23);

    cout << "\nEnter minute of event: ";
    do {
        cin >> e.min;
        if (e.min < 0 || e.min>59) {
            cout << "Invalid minute. Please enter again: ";
        }
    } while (e.min < 0 || e.min>59);

    cout << "\nEnter second of event: ";
    do {
        cin >> e.sec;
        if (e.sec < 0 || e.sec>59) {
            cout << "Invalid second. Please enter again: ";
        }
    } while (e.sec < 0 || e.sec>59);
    return in;

}
event operator - (event &e1) {
    event today = today.current();
    int s = e1.getSec() - today.getSec();
    int m = e1.getMin() - today.getMin();
    int h = e1.getHour() - today.getHour();
    int d = e1.getDay() - today.getDay();
    int mo = e1.getMonth() - today.getMonth();
    int y = e1.getYear() - today.getYear();
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

void print(event *e) {
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
    left = (*(e + n - 1) - current);
    cout << left;
}
void menu(event* e)
{
	cout << "Total events: " << e->getCount() << endl;
    cout << "1. Create new event" << endl;
    cout << "2. View Existing Event" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    int n;
    cin >> n;
    switch (n)
    {
    case 1:
        newEvent(e, e->getCount()+1);
        break;
    case 2:
        print(e);
        viewEvent(e);
        break;
    case 3:
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