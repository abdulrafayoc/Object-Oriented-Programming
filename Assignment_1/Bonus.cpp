/*
ABDUL RAFAY
SE=B
ROLL NO = 22i - 8762
*/
#include <iostream>

using namespace std;


bool findWord(char guess, string answer)
{
	static int i;
	if (i < answer.length())
	{
		if (guess == answer[i])
		{
			return true;
		}
		i++;
		findWord(guess, answer);
	}
	return false;
}

int hangman(string answer)
{
	char guess;
	bool found = false;
	static int lives = 5;
	static int foundCount;


	if (lives != 0)
	{
		cout << "You have " << lives << " lives left." << endl;
		cout << "Enter a letter: ";
		cin >> guess;
		
		if (foundCount >= answer.length() - 1)
		{
			return lives;
		}
		else if (lives == 0)
		{
			cout << "You have no lives left!" << endl;
			return 0;
		}
		
		found = findWord(guess, answer);
		if (found == true)
		{
			cout << "\033[32mYou found a letter!\033[0m" << endl;
			foundCount++;
			hangman(answer);
		}
		else if (found == false)
		{
			lives--;
			cout << "You did not find a letter!" << endl;
		}
		hangman(answer);
	}
}
int main()
{
	string nobodys[10] = { "fahad", "ghaus" , "sajid" , "ali" , "umer" , "zeeshan" , "usman" , "ahmed" , "bilal" };
	string answer = nobodys[(rand() % 10) + 1];
    int lives;

	lives = hangman("answer");


    if (lives != 0)
        cout << "\033[32mCongrats you found the word!\033[0m" << endl;
    else
        cout << "\033[31mOh no, you failed :( !\033[0m" << endl;

    return 0;
}