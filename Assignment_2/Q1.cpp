#include <iostream>

using namespace std;

struct Pixel
{
    int red;
    int green;
    int blue;

    Pixel() 
    {
        red = 0;
        green = 0;
        blue = 0;
    }

    Pixel(int r, int g, int b)
    {
        red = r;
        green = g;
        blue = b;
    }
};

class Image
{
private:
    int row;
    int col;
    int depth;
    Pixel ***image;//<<<---------------
public:
    Image()
    {
        depth = 0;
        row = 0;
        col = 0;
    }
    Image(int d = 1, int r = 1, int c = 1)
    {
        depth = d;
        row = r;
        col = c;
        image = new Pixel * *[depth];

        for (int i = 0; i < depth; i++)
        {
            image[i] = new Pixel * [row];
            for (int j = 0; j < row; j++)
            {
                image[i][j] = new Pixel[col];
            }
        }
    }
    Image(const Image &img)
    {
        row = img.row;
        col = img.col;
        depth = img.depth;
    }
    ~Image()
    {
        row = 0;
        col = 0;
        depth = 0;
		delete[] image;
    }
    //Getters and Setters
    void setRow(int r)
    {
        row = r;
    }
    void setCol(int c)
    {
        col = c;
    }
    void setDepth(int d)
    {
        depth = d;
    }
    int getRow()
    {
        return row;
    }
    int getCol()
    {
        return col;
    }
    int getDepth()
    {
        return depth;
    }
    
    Pixel getPixel(int x, int y, int z)
    {
        return image[x][y][z];
    }
    void setPixel(int x, int y, int z, Pixel p)
    {
        image[x][y][z] = p;
    }
    void fill(Pixel P)
    {
        for (int i = 0; i < depth; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    image[i][j][k] = P;
                }
            }
        }
        return;
    }
    void clear()
    {
        Pixel black(0, 0, 0);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < depth; k++)
                {
                    image[i][j][k] = black;
                }
            }
        }
        return;
    }
    double getAverageBrightness()
    {
        double avg = 0.000;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < depth; k++)
                {
                    avg += ((double)image[i][j][k].red + (double)image[i][j][k].green + (double)image[i][j][k].blue) / 3;
                }
            }
        }
        return (avg / (row * col * depth));
    }

    int getMaximumBrightness(int depth)
    {
        int max = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (image[depth][i][j].red > max) {
                    max = image[depth][i][j].red;
                }
                if (image[depth][i][j].green > max) {
                    max = image[depth][i][j].green;
                }
                if (image[depth][i][j].blue > max) {
                    max = image[depth][i][j].blue;
                }
            }
        }
        return max/3;
    }
    int countBrightPixel()
    {
        int count = 0;
        for (int i = 0; i < depth; i++)
        {
            for (int j = 0; j < row; j++)
            {
                for (int k = 0; k < col; k++)
                {
                    if (image[i][j][k].red == 255 || image[i][j][k].green == 255 || image[i][j][k].blue == 255)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    void transposePixel(int depth)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                Pixel temp;
                image[depth][i][j] = image[depth][j][i];
            }
        }
    }
};

int main()
{
    Image img(3, 3, 3);
    Pixel p(255, 255, 255);
    img.fill(p);
    cout << img.getAverageBrightness() << endl;
    cout << img.getMaximumBrightness(0) << endl;
    cout << img.countBrightPixel() << endl;
    img.transposePixel(0);
    img.clear();
    return 0;
}