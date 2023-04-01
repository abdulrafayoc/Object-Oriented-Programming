#include <iostream>

using namespace std;

class Block
{
private:
    string shape;
    string color;
public:
    Block(string shape, string color)
    {
        this->shape = shape;
        this->color = color;
    }
    string getShape()
    {
        return shape;
    }
    string getColor()
    {
        return color;
    }
};
