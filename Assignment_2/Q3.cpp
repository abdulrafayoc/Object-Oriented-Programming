#include <iostream>

using namespace std;

class String{
    char *data;
    int size;
public:
    String(){

    }
    String(int length){
        size = length;
        data = new char[size];
    }
    String(char *str){
        size = stringLength(str);
        data = new char[size];
        for(int i = 0; i < size; i++){
            *(data + i) = *(str + i);
        }
    }
    String(String &str){
        size = str.size;
        data = new char[size];
        for(int i = 0; i < size; i++){
            *(data + i) = str.data[i];
        }
    }
    ~String(){
        delete [] data;
    }
    int stringLength(char *str){
        int i = 0;
        while(*(str + i) != '\0'){
            i++;
        }
        return i;
    }
    int stringLength(){
        int i = 0;
        while(*(data + i) != '\0'){
            i++;
        }
        return i;
    }
    void clear(){
        data = NULL;
        size = NULL;
    }
    bool isEmpty(){
        if(data == NULL){
            return true;
        }
        else{
            return false;
        }
    }
    int charAt(char c){
        for(int i = 0; i < size; i++){
            if(*(data + i) == c){
                return i;
            }
        }
        return NULL;
    }
    char* getData(){
        return data;
    }
    bool isEqual(char* str)
    {
        if(size != stringLength(str)){
            return false;
        }
        else{
            for(int i = 0; i < size; i++){
                if(*(data + i) != *(str + i)){
                    return false;
                }
            }
            return true;
        }
    }
    bool equalsIgnoreCase(char* str){
        if(size != stringLength(str)){
            return false;
        }
        else{
            for(int i = 0; i < size; i++){
                if(*(data + i) != *(str + i) || *(data + i) != char(int(*(str + i)) + 32) || *(data + i) != char(int(*(str + i)) - 32)){
                    return false;
                }
            }
            return true;
        }
    }
    char *substring(char* substr, int startIndex){
        int pos;
        for(int i = startIndex; i < size; i++){
            if (*(data + i) == *(substr)){
                for(int j = 0; j < stringLength(substr); j++){
                    if (*(data + i + j) == *(substr + j)) {
                        if (j = stringLength(substr) - 1) {
                            pos = i;
                            break;
                        }
                    }
                }
            }
        }
        char *temp= new char[stringLength(substr) - pos];
        
        for(int i = pos; i < stringLength(substr); i++) {
            *(temp + i - pos) = *(data + i);
        }
        return temp;
    }

    char *substring(char* substr, int startIndex, int endIndex){
        int pos;
        for (int i = startIndex; i < size; i++) {
            if (*(data + i) == *(substr)) {
                for (int j = 0; j < stringLength(substr); j++) {
                    if (*(data + i + j) == *(substr + j)) {
                        if (j = stringLength(substr) - 1) {
                            pos = i;
                            break;
                        }
                    }
                }
            }
        }
        char *temp = new char[endIndex - pos];
        for(int i = pos; i < endIndex; i++){
            *(temp + i - pos) = *(data + i);
        }
        return temp;
    }
    void Print(){
        if (stringLength() == 0)
            cout << "String is empty";
        else
        {
            for(int i = 0; i < size; i++){
                cout << *(data + i);
            }
        }
    }
};


int main() {
    String s1("Hello");
    s1.Print();
    cout << s1.charAt('l') << endl;
    cout << s1.stringLength() << endl;
    cout << "get data : " << s1.getData() << endl;
    cout << "is EMpty : " << s1.isEmpty() << endl;
    cout << "is Equal" << s1.isEqual("Hello") << endl;
    cout << s1.equalsIgnoreCase("HELLO") << endl;
    cout << s1.substring("llo", 2) << endl;
    cout << s1.substring("llo", 2, 4) << endl;
    cout << s1.equalsIgnoreCase("HELLO") << endl;

    s1.clear();
}