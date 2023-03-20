#pragma once
#include <iostream>

using namespace std;

class Account
{
private:
	int accountNumber;
	double balance;
	static int base;
public:
	Account()
	{
		base += 1;
		accountNumber = base;
		balance = 0;
	}
	Account(int accountNumber, double balance)
	{
		this->accountNumber = accountNumber;
		this->balance = balance;
	}
	int getAccountID()
	{
		return accountNumber;
	}
	double getBalance()
	{
		return balance;
	}
	void setBalance(double balance)
	{
		this->balance += balance;
	}
	void GetAccountInfo()
	{
		cout << "Account Number: " << accountNumber << endl;
		cout << "Balance: " << balance << endl;
	}

	void deposit(double amount) {
		if (amount < 0) {
			cout << "\nAmount cant be negitive";
			exit(0);
		}
		balance += amount;
	}

	void withdraw(double amount) {
		if (amount < 0) {
			cout << "\nAmount cant be negitive";
			exit(0);
		}
		if (amount > balance) {
			cout << "\nAmount cant be greater than balance";
			exit(0);
		}
		balance -= amount;
	}
	~Account()
	{
		cout << "the Account with account no " << accountNumber << " and balance " << balance << " is destroyed!!";
	}
};

int Account::base = 00000000;
