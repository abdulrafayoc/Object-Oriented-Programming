#include <iostream>
#include <fstream>

using namespace std;

class PhoneDirectory {
private:
    string fullName;
    string number;
    string email;
public:
    PhoneDirectory() {
        fullName = "";
        number = "";
        email = "";
    }
    PhoneDirectory(string fullName, string number, string email) {
        this->fullName = fullName;
        this->number = number;
        this->email = email;
    }
    // Setters
    void setFullName(string fullName) {
        this->fullName = fullName;
    }
    void setNumber(string number) {
        this->number = number;
    }
    void setEmail(string email) {
        this->email = email;
    }
    // Getters
    string getFullName() {
        return fullName;
    }
    string getNumber() {
        return number;
    }
    string getEmail() {
        return email;
    }
    // Methods
    void display() {
        cout << "Full Name: " << fullName << endl;
        cout << "Number: " << number << endl;
        cout << "Email: " << email << endl;
    }
};

int main() {
    int i = 0;

    ofstream file;
    file.open("phonedir.bin", ios::binary);
    PhoneDirectory p[3];
    string fullName, number, email;
    for (i = 0; i < 3; i++) {
        cout << "Enter Dtails of Person " << i + 1 << endl;
        cout << "Enter Full Name: ";
        cin >> fullName;
        cout << "Enter Number: ";
        cin >> number;
        cout << "Enter Email: ";
        cin >> email;

        p[i].setFullName(fullName);
        p[i].setNumber(number);
        p[i].setEmail(email);

        file.write((char*)&p[i], sizeof(p));
    }

    cout << "Records Saved Successfully!" << endl;

    ifstream file2;

    /*Then write class functions searchByName: which should read the file and must
return the Phone number of searched person and searchByemail: which should read the file
and must return the Phone number of person holding the searched email address. Also write a
class function printDirectory which must read the complete directory and print all the records
of the directory.*/
    file2.open("phonedir.bin", ios::binary);
    string searchName, searchEmail;
    cout << "Enter Name to Search: ";
    cin >> searchName;

    for (i = 0; i < 3; i++) {
        file2.read((char*)&p[i], sizeof(p));
        
        if (p[i].getEmail() == searchEmail) {
            cout << "Number: " << p[i].getNumber() << endl;
        }
        else if (i == 2) {
            cout << "No Record Found!" << endl;
        }
    }


    cout << "Enter Email to Search: ";
    cin >> searchEmail;
    for (i = 0; i < 3; i++) {
        file2.read((char*)&p[i], sizeof(p));
        
        if (p[i].getEmail() == searchEmail) {
            cout << "Number: " << p[i].getNumber() << endl;
        }
        else if (i == 2) {
            cout << "No Record Found!" << endl;
        }
    }

    return 0;
}
