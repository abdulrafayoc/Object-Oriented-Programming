#include <iostream>
#include <fstream>

using namespace std;

class Student {
public:
    int regNo;
    string fullName;
    string program;
    string contact;
};

int main() {
    int i = 0;

    ofstream file;
    file.open("Record.bin", ios::binary);
    Student s[3];
    for (i = 0; i < 3; i++) {
        cout << "Enter Dtails of Student " << i + 1 << endl;
        cout << "Enter Reg No: ";
        cin >> s[i].regNo;
        cout << "Enter Full Name: ";
        cin >> s[i].fullName;
        cout << "Enter Program: ";
        cin >> s[i].program;
        cout << "Enter Contact: ";
        cin >> s[i].contact;

        file.write((char*)&s[i] , sizeof(s));
        file.close();
    }

    cout << "Records Saved Successfully!" << endl;

    ifstream file2;

    file2.open("Record.bin", ios::binary);

    for (i = 0; i < 3; i++) {
        file2.read((char*)&s[i], sizeof(s));
        cout << "Reg No: " << s[i].regNo << endl;
        cout << "Full Name: " << s[i].fullName << endl;
        cout << "Program: " << s[i].program << endl;
        cout << "Contact: " << s[i].contact << endl;
    }

    file2.close();

    return 0;
}