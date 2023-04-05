#include <iostream>

using namespace std;

class Block
{
protected:
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
    friend ostream & operator << (ostream& out, const Block& b);
};
ostream & operator << (ostream& out,Block &B) {
        // return display(out);
        if (B.getColor() == "")
            out << "(" << B.getShape() << ")";
        else
            out << "(" << B.getShape() << "," << B.getColor() << ")";
        return out;
    }

class Build {
    int i;//layers
    int j;//depth
    int k;//width
public:
    Block ***Tower;
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
        return temp;
    }
    Build operator % (unsigned int n) {
        //- operator repeated n-1 times
        Build temp = *this;
        for (int i = 0; i < n - 1; i++) {
            temp -= *this;
        }
        return temp;
    }
    ostream& display(ostream& out,Build& B) {
        for (int a = B.i - 1; a >= 0; a--) {
            cout << "Layer " << a << ":" << endl;
            for (int b = B.j - 1; b >= 0; b--) {
                for (int c = B.k - 1; c >= 0; c--) {
                    out << B.Tower[a][b][c];
                }
                out << endl;
            }
            out << endl;
        }
        return out;
    }
     
    friend ostream& operator << (ostream& out,Build &b) ;
};
     ostream& operator << (ostream& out,Build &b)  {
        return b.display(out,b);
    }

int main() {
    Block b("","");
    Block b1("Simple", "White");
    Block b2("Simple", "Red");
    Block b3("ObliquedL", "Red");
    Block b4("ObliquedR", "Red");
    Build B1(b1);
    Build B2(b2);
    Build B3(b3);
    Build B4(b4);
} 