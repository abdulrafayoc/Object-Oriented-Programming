#include <iostream>
#include <cmath>

using namespace std;

class Point {
    int x;
    int y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Point(const Point& p) {
        x = p.x;
        y = p.y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    void display() {
        cout << "(" << x << "," << y << ")" << endl;
    }
    friend ostream & operator << (ostream& out, const Point& p);
};
ostream & operator << (ostream& out, const Point& p) {
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

class Line {
    Point p1;
    Point p2;
public:
    Line() {
        p1.setX(4);
        p1.setY(6);
        p2.setX(2);
        p2.setY(4);
    }
    Line(int x1, int y1, int x2, int y2) {
        p1.setX(x1);
        p1.setY(y1);
        p2.setX(x2);
        p2.setY(y2);
    }
    Line(const Point &p1, const Point &p2) {
        this->p1 = p1;
        this->p2 = p2;
    }
    float findSlope() {
        return (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
    }
    float findLength() {
        return sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
    }
    Point findMidPoint() {
        Point p;
        p.setX((p1.getX() + p2.getX()) / 2);
        p.setY((p1.getY() + p2.getY()) / 2);
        return p;
    }
};

int main () {
    Point p1(4, 8);
    Point p2(6, 12);

    Line l(p1, p2);

    cout << "Slope: " << l.findSlope() << endl;
    cout << "Length: " << l.findLength() << endl;
    cout << "Midpoint: " << l.findMidPoint() << endl;
    
    return 0;
}