#include <iostream>

using namespace std;

class Money {
private:
    int dollars;
    int cents;
public:
    Money(){
        dollars = 0;
        cents = 0;
    }
    Money(int dollar, int cents){
        dollars = dollar;
        this->cents = cents;
    }
    void operator++ (){
        cents++;
        if (cents > 99) {
            cents = 0;
            dollars++;
        }
    }
    void operator --(){
        cents--;
        if (cents < 0) {
            cents = 99;
            dollars--;
        }
    }
    void operator*= (const Money& right) {

    }
    bool operator != (const Money& right) {
        if (dollars != right.dollars || cents != right.cents) {
            return true;
        } else {
            return false;
        }
    }
friend ostream& operator <<  (ostream &out,Money& right);
friend istream& operator >> (istream & in,Money& right);
~Money(){
    
    }

};
ostream& operator <<  (ostream &out,Money& right) {
        out << right.dollars << "." << right.cents;
        return out;
}
istream& operator >> (istream & in,Money& right) {
        cout << "Enter dollars: ";
        in >> right.dollars;
        cout << "Enter cents: ";
        in >> right.cents;
        return in;
    }
    