#pragma once
#include <iostream>

using namespace std;


bool isPalidrome(string str)
{
	static int i = 0, j = str.length() - 2;
	if (i != j)
	{
		if (str[i] != str[j])
		{
			return false;
		}
		i++;
		j--;
		isPalidrome(str);
	}
	return true;
}



//bool PrimeNumber(int n)
//{
//	static int i = 2;
//	if (i <= n)
//	{	
//		if (n % i == 0)
//		{	
//			return false;
//		}
//		i++;
//		PrimeNumber(n);
//	}
//	else
//		return true;
//}

bool PrimeNumber(int n)
{
	static int i=2;
	if (n > 2)
	{
		return false;
	}
	else if (n <= 2)
	{
		if (n % i == 0) 
		{
			if (n == i)
				return true;
			else
				return false;
		}
		i++;
		PrimeNumber(n);
	}
	else
	{	
		return true;
	}
}

void printspaces(int n)
{
	if (n > 0)
	{
		cout << " ";
		printspaces(n - 1);
	}
}

void printsteric(int n)
{
	if (n > 0)
	{
		cout << "*";
		printsteric(n - 1);
	}
}

void printdim()
{
	int n = 7;
	if (n > 0)
	{
		printspaces(n);
		printsteric(n - 6);
		cout << endl;
		
		printspaces(n-1);
		printsteric(n - 4);
		cout << endl;

		printspaces(n-2);
		printsteric(n - 2);
		cout << endl;

		printspaces(n-3);
		printsteric(n);
		cout << endl;

		printspaces(n - 2);
		printsteric(n - 2);
		cout << endl;
		printspaces(n - 1);
		printsteric(n - 4);
		cout << endl;

		printspaces(n);
		printsteric(n - 6);
		cout << endl;
		n--;
		
	}
}