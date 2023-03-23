#include <iostream>

using namespace std;

class String {
    char* data;
    int size;
public:
    String() {

    }
    String(int length) {
        size = length;
        data = new char[size];
    }
    String(char* str) {
        size = stringLength(str);
        data = new char[size];
        for (int i = 0; i < size; i++) {
            *(data + i) = *(str + i);
        }
    }
    String(String& str) {
        size = str.size;
        data = new char[size];
        for (int i = 0; i < size; i++) {
            *(data + i) = str.data[i];
        }
    }
    ~String() {
        delete[] data;
    }
    int stringLength(char* str) {
        int i = 0;
        while (*(str + i) != '\0') {
            i++;
        }
        return i;
    }
    int stringLength() {
        int i = 0;
        while (*(data + i) != '\0') {
            i++;
        }
        return i;
    }
    void clear() {
        data = NULL;
        size = NULL;
    }
    bool isEmpty() {
        if (data == NULL) {
            return true;
        }
        else {
            return false;
        }
    }
    int charAt(char c) {
        for (int i = 0; i < size; i++) {
            if (*(data + i) == c) {
                return i;
            }
        }
        return -1;
    }
    char* getData() {
        return data;
    }
    bool isEqual(char* str)
    {
        if (size != stringLength(str)) {
            return false;
        }
        else {
            for (int i = 0; i < size; i++) {
                if (*(data + i) != *(str + i)) {
                    return false;
                }
            }
            return true;
        }
    }
    bool equalsIgnoreCase(char* str) {
        if (size != stringLength(str)) {
            return false;
        }
        else {
            for (int i = 0; i < size; i++) {
                if (*(data + i) != *(str + i) || *(data + i) != char(int(*(str + i)) + 32) || *(data + i) != char(int(*(str + i)) - 32)) {
                    return false;
                }
            }
            return true;
        }
    }
    char* substring(char* substr, int startIndex) {
        int pos = 0;
        for (int i = startIndex; i < size; i++) {
            if (*(data + i) == *(substr)) {
                for (int j = 0; j < stringLength(substr); j++) {
                    if (data[i + j] != substr[j]) {
                        break;
                    }
                    if (j == stringLength(substr) - 1) {
                        char* temp = new char[size - startIndex];
                        for (int n = 0; n < size - startIndex; n++) {
                            *(temp + n) = *(data + n + i);
                        }
                        return temp;
                    }
                }
            }
            return NULL;
        }
    }
    char* substring(char* substr, int startIndex, int endIndex) {
        for (int i = startIndex; i < size; i++) {
            if (*(data + i) == *(substr)) {
                for (int j = 0; j < stringLength(substr); j++) {
                    if (data[i + j] != substr[j]) {
                        break;
                    }
                    if (j == stringLength(substr) - 1) {
                        char* temp = new char[endIndex - startIndex];
                        for (int n = 0; n < endIndex - startIndex; n++) {
                            *(temp + n) = *(data + n + i);
                        }
                        return temp;
                    }
                }
            }
        }
            return NULL;
    }
    void Print() {
        if (stringLength() == 0)
            cout << "String is empty";
        else
        {
            for (int i = 0; i < size; i++) {
                cout << *(data + i);
            }
        }
    }
    };


int main() {
    char* str = new char[7];
    cin >> str;
    String s1(str);
    s1.Print();
    cout << s1.charAt('l') << endl;
    cout << s1.stringLength() << endl;
    cout << "get data : " << s1.getData() << endl;
    cout << "is EMpty : " << s1.isEmpty() << endl;
    cout << "is Equal" << s1.isEqual(str) << endl;
    cout << s1.equalsIgnoreCase(str) << endl;
    char* strr = new char[10];
    cin >> strr;
    cout << s1.substring(strr, 0) << endl;
    cout << s1.substring(strr, 0, 10) << endl;
    cout << s1.equalsIgnoreCase(str) << endl;
    s1.clear();
}