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
    char *substring(char* substr, int startIndex){////////////////////DO REcheckkkkkkkkkkkkkkkkkkk
        int pos;
        for(int i = startIndex; i < size; i++){
            if (*(data + i) == *(substr)){
                for(int j = 0; j < stringLength(substr); j++){
                    if(*(data + i + j) == *(substr + j)){
                        pos = i;
                        break;
                    }
                }
            }
        }
        char *temp= new char[stringLength(substr) - pos];
        for(int i = pos; i < stringLength(substr); i++){
            *(temp + i) = *(data + i);
        }
        return temp;
    }

    char *substring(char* substr, int startIndex, int endIndex){////////////////////DO REcheckkkkkkkkkkkkkkkkkkk
        int pos;
        for(int i = startIndex; i < size - endIndex; i++){
            if (*(data + i) == *(substr)){
                for(int j = 0; j < stringLength(substr); j++){
                    if(*(data + i + j) == *(substr + j)){
                        pos = i;
                        break;
                    }
                }
            }
        }
        char *temp = new char[endIndex - pos];
        for(int i = pos; i < endIndex; i++){
            *(temp + i) = *(data + i);
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
