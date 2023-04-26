#include <iostream>

using namespace std;

class Shape {
protected:
    string type;
public:
    Shape() {
        type = "";
    }
    Shape(string t){
        type = t;
    }
    virtual ~Shape() {

    }
    virtual void area() = 0;
    virtual void display() {
        cout << "Type: " << type << endl;
    }
};

class Rectangle : public Shape {
private:
    float width;
    float height;
public:
    Rectangle()
    {
        type = "Rectangle";
        width = 0;
        height = 0;
    }
    Rectangle(string t, float w, float h){
        type = t;
        width = w;
        height = h;
    }
    virtual ~Rectangle() {

    }
    virtual void area() {
        cout << "Area: " << width * height << endl;
    }
    virtual void display() {
        Shape::display();
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
    }
};

class Triangle : public Shape {
private:
    float base;
    float height;
public:
    Triangle()
    {
        type = "Triangle";
        base = 0;
        height = 0;
    }
    Triangle(string t, float b, float h){
        type = t;
        base = b;
        height = h;
    }
    virtual ~Triangle() {

    }
    virtual void area() {
        cout << "Area: " << 1 / 2 * base * height << endl;
    }
    virtual void display() {
        Shape::display();
        cout << "Base: " << base << endl;
        cout << "Height: " << height << endl;
    }
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle()
    {
        type = "Circle";
        radius = 0;
    }
    Circle(string t, float r){
        type = t;
        radius = r;
    }
    virtual ~Circle() {

    }
    virtual void area() {
        cout << "Area: " << 3.14 * radius * radius << endl;
    }
    virtual void display() {
        Shape::display();
        cout << "Radius: " << radius << endl;
        cout << "Type: " << type << endl;
    }
};

int main() {
    Shape* s1 = new Rectangle("Rectangle", 4, 6);
    Shape* s2 = new Triangle("Triangle", 3, 4);
    Shape* s3 = new Circle("Circle", 5);

    s1->display();
    s1->area();

    s2->display();
    s2->area();

    s3->display();
    s3->area();

    return 0;
}