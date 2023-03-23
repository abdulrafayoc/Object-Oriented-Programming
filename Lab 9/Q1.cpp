#include <iostream>

using namespace std;

class Polynomial {
private:
    double a;
    double b;
    double c;
public:
    Polynomial() {
        a = 0;
        b = 0;
        c = 0;
    }
    Polynomial (double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    double getA() {
        return a;
    }
    double getB() {
        return b;
    }
    double getC() {
        return c;
    }
    void setA(double a) {
        this->a = a;
    }
    void setB(double b) {
        this->b = b;
    }
    void setC(double c) {
        this->c = c;
    }
    bool operator==(Polynomial &p) {
        return (a == p.getA() && b == p.getB() && c == p.getC());
    }
    Polynomial operator += (Polynomial &p) {
        a += p.getA();
        b += p.getB();
        c += p.getC();
        return *this;
    }
    Polynomial operator -= (Polynomial &p) {
        a -= p.getA();
        b -= p.getB();
        c -= p.getC();
        return *this;
    }
    Polynomial operator += (int n) {
        a += n;
        b += n;
        c += n;
        return *this;
    }
    Polynomial operator -= (int n) {
        a -= n;
        b -= n;
        c -= n;
        return *this;
    }
    void DisplayPolynomial(){
        cout << a << "x^2 + " << b << "x + " << c << endl;
    }
};