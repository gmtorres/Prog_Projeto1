/*------------------------------------------------------------------------------+
|																				|
|	Name :	playwords															|
|	20/03/2018																	|
|	Program developed by Filipe Ferreira and Gustavo Torres  					|
|	C/C++																		|
|	FEUP,MIEIC,Prog																|
|	MIT LICENSE																	|
|																				|
+-------------------------------------------------------------------------------+*/
#include "WordData.h"
#include <iostream>
#include <ctime>

void menu() {
	char ch;
	cout << "Choose an option:\n"
		<<"a) Check if the word belongs to the word list.\n"
		<<"b) Guess the word.\n"
		<<"c) Given a set show all posivel combinations.\n"
		<< "d)Given a random set of leters, guess a word.\n"
		<< "e)Read a word with wildcard caracters and return all possivel sets." << endl;
	cin >> ch;
	while (cin.fail() && (ch != 'a' || ch != 'b' || ch != 'c' || ch != 'd' || ch != 'e')) {
		cout << "Invalid option" << endl;
		cin.clear();
		cin.ignore(100000000, '\n');
		cin >> ch;
	}
	switch (ch) {
	case 'a':
		break;
	case 'b':
		break;
	case 'c':
		break;
	case 'd':
		break;
	case 'e':
		break;
	}

}

bool isalpha_string(string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if (!isalpha(str.at(i)))
			return false;
	}
	return true;
}

void op_a(WordData &wd) {
	string str;
	cout << "\nIntroduza a palavra: "; cin >> str;
	while (true)
	{
		if (!cin.fail() && cin.peek() == '\n')
			str[0] = str[0];
	}
}





int main()
{	
	srand(NULL);
	WordData wd;
	string str;
	wd.set_inputFile("penis.txt");
	wd.LoadWords();
	//menu();
	cin >> str;
	cout << isalpha_string(str);
    return 0;
}

