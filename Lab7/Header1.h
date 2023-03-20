#pragma once
#include <iostream>

using namespace std;

class Laptop
{
private:
	string model;
	string MAC;
	string company;
public:
	Laptop()
	{
		this->model = "HP";
		this->MAC = "123.45.67.89";
		this->company = "HP";
	}
	Laptop(string model, string MAC, string company)
	{
		this->model = model;
		this->MAC = MAC;
		this->company = company;
	}
	string getModel()
	{
		return model;
	}
	string getMacAddress()
	{
		return MAC;
	}
	string getName()
	{
		return company;
	}
	void setModel(string model)
	{
		this->model = model;
	}
	void setMacAddress(string MAC)
	{
		this->MAC = MAC;
	}
	void setCompanyName(string company)
	{
		this->company = company;
	}
	void GetLaptopInfo()
	{
		cout << "Model: " << model << endl;
		cout << "MAC: " << MAC << endl;
		cout << "Company: " << company << endl;
	}

};
