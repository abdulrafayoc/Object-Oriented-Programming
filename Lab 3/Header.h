#pragma once
#include <iostream>
#include "Header.h"
using namespace std;


int calDiagonal(int** p, int sizeA, int sizeB)
{
	int sum = 0;
	for (int i = 0; i < sizeA; i++)
	{
		sum += p[i][sizeA - 1 - i];
	}
	return sum;
}


void Raja_Jee_Airlines()
{
	int seats[13][6];

	cout << "What class you want?\n[1]FirstClass\n[2]BusinessClass\n[3]EconomyClass\n";
	int cho;
	cin >> cho;
	if (cho == 1)
	{
		cout << "------Welcome to First Class -----------\n";
		cout << "Enter your Desired Row [available: 1 - 2] :";
		cin >> cho; 
		cout << "Enter your Desired Column [available: 1 - 6]";
		cin >> cho;
	}
	else if (cho == 2)
	{
		cout << "------Welcome to Business Class -----------\n";
		cout << "Enter your Desired Row [available: 3 - 7] :";
		cin >> cho;
		cout << "Enter your Desired Column [available: 1 - 6] :";
		cin >> cho;
	}
	else if (cho == 3)
	{
		cout << "------Welcome to Economy Class -----------\n";
		cout << "Enter your Desired Row [available: 8 - 13] :";
		cin >> cho;
		cout << "Enter your Desired Column [available: 1 - 6] :";
		cin >> cho;
	}
	return;
}


int** Upper_half(int** Array, int rows, int columns)
{
	int** result = new int* [rows];
	for (int i = 0; i < rows; i++) 
	{
		result[i] = new int[columns];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			result[i][j] = Array[i][j];
		}
	}

	for (int i = 1; i < rows; i++)
	{
		for (int j = 0; j < i;j++)
		{
			result[i][j] = 0;
		}
	}
	return result;
}


int** Product(int** matrix1, int** matrix2, int rowM1, int colM1, int rowM2, int colM2)
{
	int** result = new int* [rowM1];
	for (int i = 0; i < rowM1; i++) {
		result[i] = new int[colM2];
	}


	for (int i = 0; i < rowM1; i++)
	{
		for (int j = 0; j < colM2; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < rowM2; k++)
			{
				result[i][j] += matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	return result;
}


bool PrimeNumber(int n) 
{
	int i = 2;
	if (i < n)
	{
		if (n % i == 0)
			return false;
		i++;
		PrimeNumber(n-1);
	}

	return true;
}