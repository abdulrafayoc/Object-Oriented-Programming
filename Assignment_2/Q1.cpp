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

        image = new Pixel**[depth];

        for (int i = 0; i < depth; i++) 
        {
            image[depth] = new Pixel*[row];
            for (int j = 0; j < row;j++) 
            {
                image[depth][row] = new Pixel[col];
            }
        }

        row = 0;
        col = 0;
        depth = 0;
    }
    Image(int d = 1, int c = 1, int r = 1)
    {
        row = r;
        col = c;
        depth = d;
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
    Pixel setPixel(int x, int y, int z, Pixel p)
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
    }
    void clear()
    {
        Pixel black(0, 0, 0);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                    image[i][j][k] = black;
            }
        }
    }
    double getAverageBrightness()
    {
        double avg = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < depth; k++)
                {
                    avg += (image[i][j][k].red + image[i][j][k].green + image[i][j][k].blue) / 3;
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
                if (image[depth][i][j].red + image[depth][i][j].green + image[depth][i][j].blue > max)
                {
                    max = image[depth][i][j].red + image[depth][i][j].green + image[depth][i][j].blue;
                }
            }
        }
        return max;
    }
    int countBrightPixel()
    {
        int count;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                for (int k = 0; k < depth; k++)
                {
                    if (image[i][j][k].red == 255 || image[i][j][k].green == 255 || image[i][j][k].blue == 255)
                    {
                        count++;
                    }
                }
            }
        }
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

}