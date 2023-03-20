#pragma once
#include <iostream>
using namespace std;

int* addNum(int* arr, int size, int num1, int num2)
{
	int* arrr = new int[size + 2];

	for (int i = 0; i < size - 1; i++)
	{
		arrr[i] = arr[i];
	}
	arrr[size] = num1;
	arrr[size + 1] = num2;

	int temp;
	for (int i = 0; i < size + 2; i++)
	{
		for (int j = i + 1; j < size + 2; j++)
		{
			if (arrr[i] < arrr[j])
			{
				temp = arrr[i];
				arrr[i] = arrr[j];
				arrr[j] = temp;
			}
		}
	}

	return arrr;
}