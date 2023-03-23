#include <iostream>

using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int **ptr;
public:
    Matrix (int r, int c)
    {
        rows = r;
        cols = c;
        ptr = new int*[rows];
        for (int i = 0; i < rows; i++)
        {
            ptr[i] = new int[cols];
        }
    }
    Matrix operator= (const Matrix& right)
    {
        if(rows != right.rows || cols != right.cols)
        {
            cout << "Error!! Matrices are not the same size." << endl;
            return;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                ptr[i][j] = right.ptr[i][j];
            }
        }
        return right;
    }
    bool operator== (const Matrix& right)
    {
        if(rows != right.rows || cols != right.cols)
        {
            cout << "Error!! Matrices are not the same size." << endl;
            return;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (ptr[i][j] != right.ptr[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
    Matrix operator+ (const Matrix& right)
    {
        if (rows != right.rows || cols != right.cols)
        {
            cout << "Error!! Matrices are not the same size." << endl;
            return;
        }
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.ptr[i][j] = ptr[i][j] + right.ptr[i][j];
            }
        }
        return temp;
    }
    Matrix operator- (const Matrix& right)
    {
        if (rows != right.rows || cols != right.cols)
        {
            cout << "Error!! Matrices are not the same size." << endl;
            return;
        }
        Matrix temp(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.ptr[i][j] = ptr[i][j] - right.ptr[i][j];
            }
        }
        return temp;
    }
    Matrix operator* (const Matrix& right)
    {
        if (cols != right.rows)
        {
            cout << "Error!! Matrices are not the same size." << endl;
            return;
        }
        Matrix temp(rows, right.cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < right.cols; j++)
            {
                temp.ptr[i][j] = 0;
                for (int k = 0; k < cols; k++)
                {
                    temp.ptr[i][j] += ptr[i][k] * right.ptr[k][j];
                }
            }
        }
        return temp;
    }
    

};