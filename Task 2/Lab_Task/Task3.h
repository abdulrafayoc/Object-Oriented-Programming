#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

int sortNreverse(int* arr, int size)
{
    
sort(arr, arr + size);
cout << "Array in reverse order: ";

for (int i = size - 1; i >= 0; i--)
{
    cout << *(arr + i) << " ";
    cout << "Address of arr[" << i << "]: " << (arr + i) << endl;
}

int sum = *arr + *(arr + (size - 1)) + *(arr + (size / 2));
return sum;

}