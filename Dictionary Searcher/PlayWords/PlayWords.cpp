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

void menu() {
	char ch;
	cout << "Choose an option:\na) Check if the word belongs to the word list.\nb) Guess the word.\nc) Given a set show all posivel combinations.\nd)Given a random set of leters, guess a word.\ne)Read a word with wildcard caracters and return all possivel sets." << endl;
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


int main()
{
	WordData wd;
	string str;
	wd.set_inputFile("penis.txt");
	wd.LoadWords();
	menu();
	//cin >> str;
	//wd.makeupper(str);
	//cout << str;
    return 0;
}

