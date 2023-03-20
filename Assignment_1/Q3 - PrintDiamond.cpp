/*
ABDUL RAFAY
SE=B
ROLL NO = 22i - 8762
*/
/*
Example: printDiamond(5) will give us the following output
**********
****  ****
***    ***
**      **
*        *
**      **
***    ***
****  ****
**********
*/


#include<iostream>
using namespace std;

void printStar(int n)
{
	if (n > 0)
	{
		cout << "*";
		printStar(n - 1);
	}
	else
	{
		return;
	}
}

void printSpace(int n)
{
	if (n > 0)
	{
		cout << " ";
		printSpace(n - 1);
	}
	else
	{
		return;
	}
}
	//No loops allowed
	//you can make helper funcation to print different items
	//all funcations must be done with recurrsion

void printDiamond(int n,int x)//define arrguments
{
	if (n > 0)
	{
		printStar(n);
		printSpace(2*(x - n));
		printStar(n);
		cout << endl;
		printDiamond(n - 1,x);
	}
	else if (n == 0)
	{
		printDiamond(n - 1, x);
	}
	else if (n < 0 && n != -x)
	{
		printStar(-n + 1);
		printSpace(2 * (x + n) - 2);
		printStar(-n + 1);
		cout << endl;
		printDiamond(n - 1, x);
	}
	else
	{
		return;
	}
}

void printDiamond(int n)
{
	printDiamond(n, n);
}

int main()
{
	int n;
	cout << "Enter Number of star: ";
	cin >> n;
	printDiamond(n);//define arguments 
}
