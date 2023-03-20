/*
ABDUL RAFAY
SE=B
ROLL NO = 22i - 8762
*/
#include<iostream>
using namespace std;
//Recursive function
int find_Length(string s, int counter) //counter will start from zero initially
{
	if (s[counter] == '\0')//basse Condition
		return counter;
	else
		return find_Length(s, counter + 1);
}

struct String_Manipulation {
	int Calculate_length (string s)
	{
		int length;
			//call a recursive funcaiton to find string length
			//add your code here
		length = find_Length(s, 0);
			/*
			The function should get a string as input and return the length of the string. 
			The length should be measured with the help of a recursive function. 
			*/
		return length;
	}
	/*bool compareString(string main, string str, int i = 0)
	{
		static int j = 0;
		if (str[j] == main[i])
		{
			if (j == '\0')
			{
				return true;
			}
			j++;
			compareString(main, str,i+1);
		}
		else
		{
			return false;
		}
	}*/
	bool substring(string main, string str)
	{
		bool status = false;
		static int i, j;
		if (main[i] != '\0')
		{
			if (str[j] == main[i])
			{

				if (str[j + 1] == '\0')
				{
					return true;
				}
				
				j++;
				i++;
				substring(main, str);
			}
			else
			{
				j = 0;
			}
			i++;
			if (status == true)
				return true;
			else
				return substring(main, str);
		}
		else
		{
			return false;
		}
	}
	
	int substring_position (string main, string str)
	{
		int index = -1;
		static int i = 0;
		//add your 
		
		/*
			Main = "I am taking OOP course"
			Str = "taking"
			The function will return 5 as substring exist and starts at 5th index of main string. In case the substring does not exist, you will return -1.

		*/
		if (main[i] != '\0')
		{
			if (str[0] == main[i])
			{
				if (substring(main, str) == true)
				{
					return i;
				}
				else
				{
					i++;
					substring_position(main, str);
				}
			}
			else
			{
				i++;
				substring_position(main, str);
			}
		}
		else
		{
			return -1;
		}
		return index;
	}
};



int main()
{
	//add your code
	String_Manipulation obj;
	string Main = "I am taking the OOP Class", Str = "OOP";
	cout << "the length is " << obj.Calculate_length(Main) << endl;
	Main = "I am taking OOP course";
	Str = "takng";
	cout<<obj.substring_position(Main,Str);
} 

