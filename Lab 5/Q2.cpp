#include <iostream>

using namespace std;

class Block
{
private:
    int length;
    int width;
    int height;
    string material;
    string color;
public:
    Block()
    {
        length = 0;
        width = 0;
        height = 0;
        material = "card";
        color = " ";
    }

    Block(int length, int width, int height, string color)
    {
        this->length = length;
        this->width = width;
        this->height = height;
        this->color = color;

    }

    Block(int length, int width, int height, string material, string color)
    {
        this->length = length;
        this->width = width;
        this->height = height;
        this->color = color;
        this->material = material;
    }

    int getLength()
    {
        return length;
    }
    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    string getColor()
    {
        return color;
    }
    int getVolume()
    {
        return length * width * height;
    }
    int getSurfaceArea()
    {
        return 2 * ((length * width)+ (length * height) + (width * height));
    }
    void print()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Material: " << material << endl;
        cout << "Color: " << color << endl;
        cout << "Volume: " << getVolume() << endl;
        cout << "Surface Area: " << getSurfaceArea() << endl;
    }

    void update(Block b[], int size, int index, double height)
    {
        if (!(index < size))
        b[index].height = height;
    }
};
int main()
{
    Block block[5];
        int width;
        int length;
        int height;
        string color;
        string material;
    for (int i = 0; i < 5; i++)
    {
        cout<<"Enter the length of the block: ";
        cin >> length;
        cout<<"Enter the width of the block: ";
        cin >> width;
        cout<<"Enter the height of the block: ";
        cin >> height;
        cout<<"Enter the color of the block: ";
        cin >> color;
        cout<<"Enter the material of the block: ";
        cin >> material;

        block[i] = Block(length, width, height, material, color);
    }
    for (int i = 0; i < 5; i++)
    {
        block[i].print();
    }
    // update
    int index;
    double height;
    cout << "Enter the index of the block you want to update: ";
    cin >> index;
    cout << "Enter the new height of the block: ";
    cin >> height;
    block[index].update(block, 5, index, height);

    return 0;
}