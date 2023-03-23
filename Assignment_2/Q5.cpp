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
		while (i != 0) {
			if (i % 2 == 1) {
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
    static string toBinaryString(int i)
    {
		int binary = 0;
		int count = 0;
		while (i != 0) {
			if (i % 2 == 1) {
				binary += pow(10, count);
			}
			count++;
			i = i / 2;
		}
		string str = to_string(binary);
		return str;
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
int main() {
    Integer i1(10);
    Integer i2(20);
	cout << i1.plus(i2) << endl;//output 30
	cout << i1.minus(i2) << endl;//output -10
	cout << i1.multiple(i2) << endl;//output 200
	cout << i1.divide(i2) << endl;//output 0
	cout << i1.compareTo(i2) << endl;//output 0
	cout << i1.doubleValue() << endl;//output 10.0
	cout << i1.floatValue() << endl;//output 10.0
	cout << i1.bitCount() << endl;//output 2
	cout << Integer::numberOfLeadingZeros(10) << endl;//output 28
	cout << Integer::numberOfTrailongZeros(10) << endl;//output 1
	cout << Integer::toBinaryString(10) << endl;//output 1010
	cout << Integer::toHexString(10) << endl;//output A
    return 0;
}
