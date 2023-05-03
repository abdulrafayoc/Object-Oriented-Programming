#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;



int count_char(ifstream& file, char ch) {
    int count = 0;
    while (!file.eof()) {
        char file_char;
        file.read((char*)&file_char, sizeof(file_char));
        if (file_char == ch) {
            count++;
        }
    }
    return count;
}

double calculate_entropy(string fileName) {
    ifstream file;
    file.open(fileName, ios::binary);
    int count = count_char(file, 'a');
    int i = count_char(file, 'b');
    int j = count_char(file, 'c');
    int k = count_char(file, 'd');
    int l = count_char(file, 'e');
    int m = count_char(file, 'f');
    int n = count_char(file, 'g');
    double entropy = -((count / 7) * log2(count / 7) + (i / 7) * log2(i / 7) + (j / 7) * log2(j / 7) + (k / 7) * log2(k / 7) + (l / 7) * log2(l / 7) + (m / 7) * log2(m / 7) + (n / 7) * log2(n / 7));
    return entropy;
}

int main() {
    cout << calculate_entropy("info.bin") << endl;
    return 0;
}