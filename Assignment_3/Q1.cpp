#include <iostream>

using namespace std;

class Block
{
private:
    string form;
    string color;
public:
    Block() {
        form = "";
        color = "";
    }
    Block(string shape, string color) {
        this->form = shape;
        this->color = color;
    }
    string getShape() {
        return form;
    }
    string getColor() {
        return color;
    }
    ostream & display (ostream& out) const{
        if (color == "")
            out << "(" << form << ")";
        else
            out << "(" << form << "," << color << ")";
        return out;
    }
    ostream & operator << (ostream& out) const {
        return display(out);
    }
};

class Build {
    Block ***Tower;
    int i;//layers
    int j;//depth
    int k;//width
public:
    Build() {
        
    }
    Build(Block b) {
        i = 1;
        j = 1;
        k = 1;
        Tower = new Block**[i];
        Tower[0] = new Block*[j];
        Tower[0][0] = new Block[k];
        Tower[0][0][0] = b;
    }
    ostream& display(ostream& out) const {
        for (int a = 0; a < this->i; a++) {
            for (int b = 0; b < this->j; b++) {
                for (int c = 0; c < this->k; c++) {
                    out << Tower[a][b][c];
                }
                out << endl;
            }
            out << endl;
        }
        return out;
    }
    ostream& operator << (ostream& out) const {
        return display(out);
    }
    Build operator ^ (Build right) {   
        int a = this->i + right.i;
        int b = this->j;
        int c = this->k;
        Block ***temp = new Block**[a];
        for (int i = 0; i < a; i++) {
            temp[i] = new Block*[b];
            for (int j = 0; j < b; j++) {
                temp[i][j] = new Block[c];
                for (int k = 0; k < c; k++) {
                    if (i < this->i) {
                        temp[i][j][k] = this->Tower[i][j][k];
                    }
                    else {
                        temp[i][j][k] = right.Tower[i - this->i][j][k];
                    }
                }
            }
        }
    return ***temp;
    }
    void operator ^= (Build right) {
        int a = this->i + right.i;
        int b = this->j;
        int c = this->k;
        Block ***temp = new Block**[a];
        for (int i = 0; i < a; i++) {
            temp[i] = new Block*[b];
            for (int j = 0; j < b; j++) {
                temp[i][j] = new Block[c];
                for (int k = 0; k < c; k++) {
                    if (i < this->i) {
                        temp[i][j][k] = this->Tower[i][j][k];
                    }
                    else {
                        temp[i][j][k] = right.Tower[i - this->i][j][k];
                    }
                }
            }
        }
        for (int i = 0; i < this->i; i++) {
            for (int j = 0; j < this->j; j++) {
                delete[] Tower[i][j];
            }
            delete[] Tower[i];
        }
        delete[] Tower;
        Tower = temp;
        this->i = a;
        this->j = b;
        this->k = c;
    }
    Build operator - (Build right) {
        if (this->i > right.i) {
            return *this;
        }
        int a = this->i;
        int b = this->j + right.j;
        int c = this->k;
        Block ***temp = new Block**[a];
        for (int i = 0; i < a; i++) {
            temp[i] = new Block*[b];
            for (int j = 0; j < b; j++) {
                temp[i][j] = new Block[c];
                for (int k = 0; k < c; k++) {
                    if (j < this->j) {
                        temp[i][j][k] = this->Tower[i][j][k];
                    }
                    else {
                        temp[i][j][k] = right.Tower[i][j - this->j][k];
                    }
                }
            }
        }
        return ***temp;
    }
    void operator -= (Build right) {
        if (this->i > right.i) {
            return;
        }
        int a = this->i;
        int b = this->j + right.j;
        int c = this->k;
        Block ***temp = new Block**[a];
        for (int i = 0; i < a; i++) {
            temp[i] = new Block*[b];
            for (int j = 0; j < b; j++) {
                temp[i][j] = new Block[c];
                for (int k = 0; k < c; k++) {
                    if (j < this->j) {
                        temp[i][j][k] = this->Tower[i][j][k];
                    }
                    else {
                        temp[i][j][k] = right.Tower[i][j - this->j][k];
                    }
                }
            }
        }
        for (int i = 0; i < this->i; i++) {
            for (int j = 0; j < this->j; j++) {
                delete[] Tower[i][j];
            }
            delete[] Tower[i];
        }
        delete[] Tower;
        Tower = temp;
        this->i = a;
        this->j = b;
        this->k = c;
    }
    Build operator + (Build right) {
        if (this->i > right.i) {
            return *this;
        }
        if (this->j > right.j) {
            return *this;
        }
        int a = this->i;
        int b = this->j;
        int c = this->k + right.k;
        Block ***temp = new Block**[a];
        for (int i = 0; i < a; i++) {
            temp[i] = new Block*[b];
            for (int j = 0; j < b; j++) {
                temp[i][j] = new Block[c];
                for (int k = 0; k < c; k++) {
                    if (k < this->k) {
                        temp[i][j][k] = this->Tower[i][j][k];
                    }
                    else {
                        temp[i][j][k] = right.Tower[i][j][k - this->k];
                    }
                }
            }
        }
        return ***temp;
    }
    void operator += (Build right) {
        if (this->i > right.i) {
            return;
        }
        if (this->j > right.j) {
            return;
        }
        int a = this->i;
        int b = this->j;
        int c = this->k + right.k;
        Block ***temp = new Block**[a];
        for (int i = 0; i < a; i++) {
            temp[i] = new Block*[b];
            for (int j = 0; j < b; j++) {
                temp[i][j] = new Block[c];
                for (int k = 0; k < c; k++) {
                    if (k < this->k) {
                        temp[i][j][k] = this->Tower[i][j][k];
                    }
                    else {
                        temp[i][j][k] = right.Tower[i][j][k - this->k];
                    }
                }
            }
        }
        for (int i = 0; i < this->i; i++) {
            for (int j = 0; j < this->j; j++) {
                delete[] Tower[i][j];
            }
            delete[] Tower[i];
        }
        delete[] Tower;
        Tower = temp;
        this->i = a;
        this->j = b;
        this->k = c;
    }
    Build operator *(unsigned int n) {
        //+ operator repeated n-1 times
        Build temp = *this;
        for (int i = 0; i < n - 1; i++) {
            temp += *this;
        }
        return temp;
    }
    Build operator / (unsigned int n) {
        //^ operator repeated n-1 times
        Build temp = *this;
        for (int i = 0; i < n - 1; i++) {
            temp ^= *this;
        }
    }
    Build operator % (unsigned int n) {
        //- operator repeated n-1 times
        Build temp = *this;
        for (int i = 0; i < n - 1; i++) {
            temp -= *this;
        }
    }
};

int main() {
    Block b1("simple","red");
    Block b2("simple","red");
    Block b3("simple","red");
    Block b4("simple","red");

    Build B(b1);
    B += b2;
    B += b3;
    B += b4;
    cout << b1 << endl;
    cout << B << endl;


    return 0;
}

