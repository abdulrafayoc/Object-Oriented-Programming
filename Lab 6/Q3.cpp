#include <iostream>

using namespace std;

class Sphere
{
private:
    const double PI = 3.14159;  
    double radius;
public:
    Sphere()
    {
        radius = 0;
    }
    Sphere(double r)
    {
        radius = r;
    }
    void setRadius(double r)
    {
        radius = r;
    }
    double getRadius()
    {
        return radius;
    }
    double getDiameter()
    {
        return 2*radius;
    }
    double getArea()
    {
        return 4*PI*radius*radius;
    }
    double getCircumference()
    {
        return 2*PI*radius;
    }
    double getVolume()
    {
        return (4/3)*PI*radius*radius*radius;
    }
};

int main()
{
    cout<<"Enter the radius of the sphere: ";
    double r;
    cin>>r;
    Sphere s1(r);
    
    cout<<"Radius: "<<s1.getRadius()<<endl;
    cout<<"Diameter: "<<s1.getDiameter()<<endl;
    cout<<"Area: "<<s1.getArea()<<endl;
    cout<<"Circumference: "<<s1.getCircumference()<<endl;
    cout<<"Volume: "<<s1.getVolume()<<endl;
    return 0;
}
