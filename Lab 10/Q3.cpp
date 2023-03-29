#include <iostream>
using namespace std;

class Fruit {
private:
    int n;
public:
    Fruit(int n) {
        this->n = n;
    }
};

class Apples : public Fruit {
public:
    Apples(int n) : Fruit(n) {
        cout<<"Apples "<< n << endl;
    }
};


class Mangos : public Fruit {
public:
    Mangos(int n) : Fruit(n) {
        cout<<"Apples "<< n << endl;
    }
};

int main()
{
    Apples a(10);
    Mangos m(20);
    return 0;
}
