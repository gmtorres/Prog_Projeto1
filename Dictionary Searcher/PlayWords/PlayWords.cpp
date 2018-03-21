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



void op_b(WordData &wd) {
	string word_o = wd.randomWord();
	string word_s = word_o;
	wd.scrambleWord(word_s);
	cout << "\n\nGUESS THE WORD : " << word_s << endl;
	string tentativa = "";
	int max_t = 3;
	while (max_t > 0) {
		cin >> tentativa;
		wd.makeupper(tentativa);
		if (tentativa.compare(word_o) == 0) {
			cout << "CORRECT!!" << endl;
			break;
		}
		else {
			max_t--;
			if (max_t == 0) {
				cout << "GAME OVER" << endl;
			}
			else {
				cout << "TRY AGAIN" << endl;
			}
		}
	}

}

void menu(WordData &wd) {
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
	case 'b': op_b(wd);
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
	srand(time(0));
	WordData wd;
	string str;
	wd.set_inputFile("Dic_teste.txt");
	wd.LoadWords();
	menu(wd);
	//cin >> str;
	//wd.makeupper(str);
	//cout << str;
    return 0;
}

