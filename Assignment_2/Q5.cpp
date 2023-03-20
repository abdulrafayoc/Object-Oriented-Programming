#include <iostream>
#include <string>
using namespace std;

class Integer{
private:
    int num;
    string str;
public:
    Integer(){
        num = 0;
    }
    Integer(int n){
        num = n;
    }
    Integer(string str){
        num = stoi(str);
    }
    void set(int n){
        num = n;
    }
    int get()const{
        return num;
    }
    int bitCount(){
        int count = 0;
        int n = num;
        while(n != 0){
            if(n % 2 == 1){
                count++;
            }
            n = n / 2;
        }
        return count;
    }
    int compareTo(Integer n){
        if(num == n.num){
            return 1;
        }
        else{
            return 0;
        }
    }
    double doubleValue(){
        return (double)num;
    }
    float floatValue(){
        return (float)num;
    }
    int plus(const Integer &n){
        return num + n.num;
    }
    int minus(const Integer &n){
        return num - n.num;
    }
    int multiple(const Integer &n){
        return num * n.num;
    }
    int divide(const Integer &n){
        return num / n.num;
    }
    static int numberOfLeadingZeros(int i){
        int count = 0;
        while(i != 0){
            if(i % 2 == 1){
                return count;
            }
            count++;
            i = i / 2;
        }
        return count;
    }
    static int numberOfTrailongZeros(int i){
        int count = 0;
        while(i != 0){
            if(i % 2 == 1){
                return count;
            }
            count++;
            i = i / 2;
        }
        return count;
    }
    static int toBinaryString(int i)
    {
        string bin;
        while(i != 0){
            if(i % 2 == 1){
                bin += "1";
            }
            else{
                bin += "0";
            }
            i = i / 2;
        }
    }
    static string toHexString(int i)
    {
        string hex;
        while(i != 0){
            if(i % 16 == 10){
                hex += "A";
            }
            else if(i % 16 == 11){
                hex += "B";
            }
            else if(i % 16 == 12){
                hex += "C";
            }
            else if(i % 16 == 13){
                hex += "D";
            }
            else if(i % 16 == 14){
                hex += "E";
            }
            else if(i % 16 == 15){
                hex += "F";
            }
            else{
                hex += to_string(i % 16);
            }
            i = i / 16;
        }
        return hex;
    }

};
