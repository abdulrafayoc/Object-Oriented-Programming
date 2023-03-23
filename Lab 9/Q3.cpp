#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **Ptr;
public:
    Matrix (int r, int c){
        rows = r;
        cols = c;
        Ptr = new int*[rows];
        for (int i = 0; i < rows; i++) {
            Ptr[i] = new int[cols];
        }
    }
    void Input(){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> Ptr[i][j];
            }
        }
    }
    bool operator < (const Matrix& right){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (Ptr[i][j] < right.Ptr[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    void operator += (const Matrix& right) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Ptr[i][j] += right.Ptr[i][j];
            }
        }
    }
    void operator -= (const Matrix& right) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Ptr[i][j] -= right.Ptr[i][j];
            }
        }
    }
    void operator *= (const Matrix& right) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Ptr[i][j] *= right.Ptr[i][j];
            }
        }
    }
    Matrix operator++ () {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                Ptr[i][j]++;
            }
        }
        return *this;
    }

};