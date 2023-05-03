#include <iostream>
#include <fstream>

using namespace std;

void input() {
    ofstream file;
    file.open("info.bin", ios::binary);
    string topic;
    string info;
    cout << "Enter Topic: ";
    cin >> topic;
    cout << "Enter Info: ";
    cin >> info;
    
    file.write((char*)&topic, sizeof(topic));
    file.close();
}

void output() {
    ifstream file;
    file.open("info.bin", ios::binary);
    string topic;
    string info;

    int count = 0;
    while (!file.eof()) {
        file.read((char*)&topic, sizeof(topic));
        count++;
    }
    cout << "Total Lines: " << count << endl;
    file.close();
}


int main() {
    input();
    output();
    return 0;
}