#include <iostream>

using namespace std;

class Container
{
private:
    int *values;
    int capacity;
    int counter;
public:
    Container(int c)
    {
        capacity = c;
        values = new int[capacity];
        counter = 0;
    }

    bool isFull()
    {
        if (counter == capacity)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void insert(int val)
    {
        if (isFull())
        {
            cout << "The container is full" << endl;
        }
        else
        {
            values[counter] = val;
            counter++;
        }
    }

    bool search( int val)
    {
        for (int i = 0; i < counter; i++)
        {
            if (values[i] == val)
            {
                return true;
            }
        }
        return false;
    }

    void remove(int val)
    {
        if (search(val))
        {
            for (int i = 0; i < counter; i++)
            {
                if (values[i] == val)
                {
                    for (int j = 0; j < counter - i; j++)
                    {
                        values[i + j] = values[i + j + 1];
                    }
                    values[counter] = 0;
                    counter--;
                }
            }
        }
        else
        {
            cout << "\033[31mInvallid\033[0m" << endl;
        }
    }

    void print()
    {
        for (int i = 0; i < counter; i++)
        {
            cout << values[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    
}