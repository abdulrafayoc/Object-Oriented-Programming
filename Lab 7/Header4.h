#pragma once
#include <iostream>

using namespace std;

class Circle {
public:
	double radius;
private:
	Circle(double radius)
	{
		if (radius < 0)
		{
			exit(1);
		}
		else
		{
			this->radius = radius;
		}
	}
	Circle()
	{
		radius = 0.0;
	}
	Circle(const Circle& circle)
	{
		radius = circle.radius;
	}
	~Circle()
	{

	}
	void setRadius(double radius)
	{
		if (radius < 0)
		{
			exit(1);
		}
		else
		{
			this->radius = radius;
		}
	}
	double getRadius() const
	{
		return radius;
	}
	double getArea() const
	{
		return 3.14 * radius * radius;
	}
	double getparameter() const
	{
		return 2 * 3.14 * radius;
	}
};
