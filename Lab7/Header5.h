#pragma once
#include <iostream>

using namespace std;

class Rational
{
private:
	int numer;
	int denom;

	int gcd()
	{
		int n = numer;
		int gcd;
		int x;
		gcd = denom;
		while (n != 0)
		{
			x = n;
			n = gcd % n;
			gcd = x;
		}
		return gcd;
	}

	void normalize()
	{
		if ((numer < 0) && (denom < 0)) {
			denom *= -1;
		}
		else if ((numer > 0) && (denom < 0)) {
			numer *= -1;
			denom *= -1;
		}

		int gcd = this->gcd();
		if (numer < 0)
			numer = numer / gcd;
		denom = denom / gcd;

	}

public:
	Rational()
	{
		numer = 0;
		denom = 1;
	}
	Rational(int nume, int deno)
	{
		this->numer = nume;
		this->denom = deno;
	}
	int getNumerator()
	{
		return numer;
	}
	int getDenominator()
	{
		return denom;
	}
	void setNumerator(int nume)
	{
		this->numer = nume;
	}
	void setDenominator(int deno)
	{
		this->denom = deno;
	}

};
