/*
ABDUL RAFAY
SE=B
ROLL NO = 22i - 8762
*/
/*
FAST university has hired you to make an operating system for their lifts. Below are specifications of the lifts OS.
The lift will be place in a building with 6 floors including a basement. 
From basement to top floors are labeled as -1,0,1,2,3,4 respectively. 
In the morning, the lift goes operation from the basement. The lift can go up and down. 
If maintained is required, the lift can be halted. If the lift is halted, the lift not usable during that period. 
Once unhalted, the lift can be used again.
With the help of above information, make a lift operating system 
*/

#include<iostream>
#include<windows.h>
using namespace std;

int liftup(int current_floor, int requested_floor);
int liftdown(int current_floor, int requested_floor);


int lift_operating_system(int requested_floor, int current_floor, char lift_status)
{
	
	
	cout << "lift Operating System" << endl;
	if (lift_status == 'W' && requested_floor < current_floor)
	{
		current_floor = liftdown(current_floor, requested_floor);
	}
	else if (lift_status == 'W' && requested_floor > current_floor)
	{
		current_floor = liftup(current_floor, requested_floor);
	}
	else
	{

	}
	return current_floor;
}

int liftup(int current_floor,int requested_floor )
{
	cout << "\033[33mYou are now on floor " << current_floor <<"\033[0m" << endl;
	Sleep(200);
	if (current_floor < requested_floor)
	{
		liftup(current_floor + 1, requested_floor);
	}
	else
	{
		return current_floor;
	}
}
int liftdown(int current_floor,int requested_floor )
{
	
	cout << "\033[33mYou are now on floor " << current_floor << "\033[0m" << endl;
	Sleep(200);
	if (current_floor > requested_floor)
	{
		liftup(current_floor - 1, requested_floor);
	}
	else
	{
		return current_floor;
	}
}
char halt_lift(char status)
{
	//halts the lift, no up and down operation can be performed. Stored H for halting
	return 'H';
	cout << endl << "\033[31mThe lift is halted\033[0m";
	
}
char un_halt_lift(char status)
{
	//Unhatls the lift. Store W which represents that the lift is working
	return 'W';
	cout << endl << "\033[32mThe lift is unhalted\033[0m";
}
int main()
{
	int total_floors = 6; // total number of floors
	int current_floor = -1; // starts with basement
	int requested_service; //choice of user
	int requested_floor; //floor the lift goes on
	char status= 'W'; //W for working , H for halted
	while(1)
	{
		cout<<"Please select a funcation of your choice";
		cout<< endl << "1. Go to a specific floor";
		cout<< endl << "2. Halt Lift";
		cout<< endl << "3. Unhalt Lift";
		cout<< endl << "4. Exit";
		
		cout << endl << "Enter your choice : ";

		cin >> requested_service;
		
		switch (requested_service)
		{
			case 1:
			{
				do
				{
					cout << endl << "Enter Floor You want to Go to : ";
					cin >> requested_floor;
					if (requested_floor > 4 || requested_floor < -1)
					{
						cout << endl << "\033[31mInvalid Floor\033[0m";
					}
					else if (requested_floor == current_floor)
					{
						cout << endl << "You are already on this floor";
					}
				} while (requested_floor > 4 || requested_floor < -1);


				current_floor = lift_operating_system(requested_floor, current_floor, status);//arguments 
				cout << "\033[32myou are now on floor " << current_floor << "\033[00m" << endl;
			}
			break;
			case 2:
			{
				status = halt_lift(status);
				cout << "\033[31mThe Lift is Halted\033[00m" << endl;
			}
			break;
			case 3:
			{
				status = un_halt_lift(status);
				cout << "\033[32mThe Lift is Un-Halted\033[00m" << endl;

			}
			break;
			case 4:
			{
				exit(0);
			}
			break;
		}
	}
	
}
