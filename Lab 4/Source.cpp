#include <iostream>
#include "../LabTask/Header.h"

using namespace std;

struct student
{
	int RegNo;
	string Name;
	string Department;
	short int Batch;
	float GPA;
};


void sort(student Arr[])
{
	student temp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (Arr[i].GPA > Arr[j].GPA)
			{
				temp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = temp;
			}
		}
	}
}

void print(student Arr[])
{
	cout << "Highest GPA: " << Arr[0].GPA << endl;
	cout << "Lowest GPA: " << Arr[4].GPA << endl;
	cout << "Average GPA: " << (Arr[0].GPA + Arr[1].GPA + Arr[2].GPA + Arr[3].GPA + Arr[4].GPA) / 5 << endl;
}

void studentinfo()
{
	student Arr[5];

	for (int i = 0; i < 5; i++)
	{
		cout << "Enter Registration Number: ";
		cin >> Arr[i].RegNo;
		cout << "Enter Name: ";
		cin >> Arr[i].Name;
		cout << "Enter Department: ";
		cin >> Arr[i].Department;
		cout << "Enter Batch: ";
		cin >> Arr[i].Batch;
		cout << "Enter GPA: ";
		cin >> Arr[i].GPA;
	}

	sort(Arr);
	print(Arr);
}


int main()
{
	printdim();
	studentinfo();
	return 0;
}