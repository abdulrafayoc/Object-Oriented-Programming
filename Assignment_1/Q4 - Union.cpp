/*
ABDUL RAFAY
SE=B
ROLL NO = 22i - 8762
*/
/*
The program will have two arrays with a set of values. 
Call a function named find_union and result will be stored in result array that contains the union of all elements of two array. 
Example 
Arr1 = {1,3,6,7,9,3}
Arr2 = {2,3,6,10}
ResultUnionArr = {1,2,3,6,7,10}
Note: You can add helping function in the code.
*/
#include<iostream>
using namespace std;

struct arrayUnion
{
	int arr1[10]; //keep this size
	int arr2[5]; // keep this size
	int* ResultUnionArr;

	void input()
	{
		//input of the arr1 and arr2
		for (int i = 0; i < 10; i++)
		{
			cout << "Enter " << i + 1 << " element of Set 1: ";
			cin >> arr1[i];
		}
		cout << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Enter " << i + 1 << " element of Set 2: ";
			cin >> arr2[i];
		}
	}
	int n = 15;
	void find_union()
	{
		//find union of arr1 and arr2
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (arr1[i] == arr2[j])
				{
					n--;
				}
			}
		}
		ResultUnionArr = new int[n];
		cout << "array created of size " << n << endl;

		for (int i = 0; i < 10; i++)
		{
			ResultUnionArr[i] = arr1[i];
		}

		for (int i = 0, j = 0; j < 5; j++)
		{
			if (Repetetion(j) == false)
			{
				ResultUnionArr[10 + i] = arr2[j];
				i++;
			}
		}
		sortArr(ResultUnionArr);
	}

	bool Repetetion(int i)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr1[j] == arr2[i])
			{
				return true;
			}
		}
		return false;

	}
	
	void printresult()
	{
		//print array with union

		//int arrsiz = sizeof(ResultUnionArr);
		//cout << "size of arrr is " << arrsiz<<endl;
		cout << "The Union of Sets is : {";
		for (int i = 0; i < n; i++)
		{
			cout << ResultUnionArr[i] << " , ";
		}
		cout << "}" << endl;
	}
	void sortArr(int arr[])
	{
		int temp;
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n - 1; k++)
			{
				if (arr[k] > arr[k + 1])
				{
					temp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = temp;
				}
			}
		}
	}
};


int main()
{
	arrayUnion u;
	u.input();
	u.find_union();
	u.printresult();
	//main will remain same
}