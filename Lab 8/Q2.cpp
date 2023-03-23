#include <iostream>

using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;
public:
    Rational(int numerator = 0, int denominator = 0)
    {
        this->numerator = numerator;    
        this->denominator = denominator;
        int gcd = this->gcd();
		numerator = numerator / gcd;
		denominator = denominator / gcd;
    }
    int gcd()
	{
		int n = numerator;
		int gcd;
		int x;
		gcd = denominator;
		while (n != 0)
		{
			x = n;
			n = gcd % n;
			gcd = x;
		}
		return gcd;
	}
	Rational operator+ (const Rational &obj)
    {
        Rational temp;
        temp.numerator = (numerator * obj.denominator) + (obj.numerator * denominator);
        temp.denominator = (numerator*denominator)/(gcd(denominator, obj.denominator));
        return temp;
    }
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
    Rational operator * (const Rational &obj)
    {
        Rational temp;
        temp.numerator = numerator * obj.numerator;
        temp.denominator = denominator * obj.denominator;
        return temp;
    }
    Rational operator / (const Rational &obj)
    {
        Rational temp;
        temp.numerator = numerator * obj.denominator;
        temp.denominator = denominator * obj.numerator;
        return temp;
    }
    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }
};