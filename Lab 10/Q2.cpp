#include <iostream>

using namespace std;

class Employee
{
private:
    string name;
    int empID;
public:
    Employee(string n, int id)
    {
        name = n;
        empID = id;
    }
};
class HourlyEmployee : public Employee
{
private:
    double hourlyRate;
public:
    HourlyEmployee(double h, string n, int id) : Employee(n, id)
    {
        hourlyRate = h;
    }
    int calculate_the_hourly_income(int hoursWorked)
    {
        return hourlyRate * hoursWorked;
    }
};
class PermanentEmployee : public Employee
{
private:
    double hourlyRate;
public:
    PermanentEmployee(double h, string n, int id) : Employee(n, id)
    {
        hourlyRate = h;
    }
    int calculate_the_income(int hoursWorked)
    {
        return hourlyRate * hoursWorked;
    }
};

int main()
{
    HourlyEmployee h(100, "Ali", 1);
    PermanentEmployee p(100, "Ali", 1);
    cout << h.calculate_the_hourly_income(10) << endl;
    cout << p.calculate_the_income(10) << endl;
    return 0;
}