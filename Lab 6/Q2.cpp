#include <iostream>

using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational(int n = 0, int d = 0)
    {
        if (n % d == 0)
        {
            numerator = n;
            denominator = d;
        }
        else
        {
            numerator = n;
            denominator = d;
            reduce();
        }
    }
    void reduce()
    {
        int X = 1;
        int i = 1;
        while (i <= numerator && i <= denominator)
        {
            if (numerator % i == 0 && denominator % i == 0)
                X = i;
            i++;
        }
        numerator = numerator / X;
        denominator = denominator / X;
    }
    void addNum(int n1, int d1, int n2, int d2)
    {
        int n = 0, d = 0;
        n = (n1*d2) + (n2*d1);
        d = d1*d2;
        
        Rational(n, d);
    }
    void multNum(int n1, int d1, int n2, int d2)
    {
        int n = 0, d = 0;
        n = n1*n2;
        d = d1*d2;
        
        Rational(n, d);
    }
    void divNum(int n1, int d1, int n2, int d2)
    {
        int n = 0, d = 0;
        n = n1*d2;
        d = d1*n2;
        
        Rational(n, d);
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }

};

int main()
{
    return 0;
}









