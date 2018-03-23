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
#include <stdio.h>
#include <algorithm>


bool isalpha_string(string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if 	((str[i]< 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z') && !(str[i] == ' ') && !(str[i] == '\n'))
		{
			return false;
		}
	}
	return true;
}

bool alfabetico(string str) {
	for (int i = 0; i < str.length(); i++)
	{
		if (!(isalpha(str[i])))
			return false;
	}
	return true;
}

void rm_spaces(string &s)
{
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (!(s[i] == ' '))
			temp += s[i];
	}
	s = temp;
}


void op_a(WordData &wd) {
	string str;
	cout << "\nIntroduza a palavra: "; cin >> str;
	while (true)
	{
		if (!cin.fail() && cin.peek() == '\n' && alfabetico(str))
			break;
		cin.clear();
		cin.ignore(100000000, '\n');
		cout << "Erro. Introduz uma string unicamente com carateres alfabeticos: "; cin >> str;
	}
	if (wd.check_Word(str))
		cout << str << " is in the word list." << endl;
	else
		cout << str << " is not in the word list." << endl;

}





void op_b(WordData &wd) {
	string word_o;
	if (wd.randomWord(word_o)) {
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
					cout << "GAME OVER\tTHE WORD WAS : " << word_o << endl;
				}
				else {
					cout << "TRY AGAIN" << endl;
				}
			}
		}
	}
}

bool isValid(string str, vector<char> vec) {
	if (str.length() > vec.size())
		return false;
	for (int i = 0; i < str.length(); i++) {
		bool v = false;
		for (int a = 0; a < vec.size(); a++) {
			if (str[i] == vec[a]) {
				vec[a] = '\0';
				v = true;
				break;
			}
		}
		if (!v)
			return false;
	}
	return true;
}

void op_d(WordData &wd) {
	cout << "\n\nNumber of letters?" << endl;
	int n;
	cin >> n;
	if (cin.fail() || n <= 0) {
		cout << "Incorrect input" << endl;
		cin.clear();
		cin.ignore(100000, '\n');
		cin >> n;
	}
	vector<char> vec = wd.give_char(n);
	cout << "Form a word with the given set: ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << "\n";
	string inp = "";
	cin >> inp;
	wd.makeupper(inp);
	while (!isValid(inp, vec)) {
		cout << "Input invalido" << endl;
		cin >> inp;
		wd.makeupper(inp);
	}
	if (wd.check_Word(inp)) {
		cout << "CORRECT" << endl;
	}
	else {
		cout << "INCORRECT" << endl;
	}




}

void op_c(WordData &wd) {
	string str;
	vector<char> chars;
	cin.clear();
	cin.ignore(1);
	cout << "Introduz o conjunto de letras: "; getline(cin, str);  //cin.ignore();
	//cout << str.size();
	while (true)
	{
		if (isalpha_string(str))
			break;
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "Erro. Introduz um conjunto com carateres alfabeticos: "; cin >> str;
	}
	wd.makeupper(str);
	for (int i = 0; i < str.length(); i++)
	{
		if (!(str[i] == ' '))
			chars.push_back(str[i]);
	}
	for (int i = 0; i < wd.words.size(); i++) {
		if (isValid(wd.words[i], chars)) {
			cout << wd.words[i] << endl;;
		}
	}

	/*
	for (int i = 0; i < chars.size(); i++)
	{
		cout << chars[i] << ' ';
	}

	cout << endl;

	wd.rm_duplicates_char_vector(chars);

	for (int i = 0; i < chars.size(); i++)
	{
		cout << chars[i] << ' ';
	}
	*/
}

bool menu(WordData &wd) {
	string ch;
	cout << "Choose an option (CNTR + Z to exit):\n\n"
		<< "a) Check if the word belongs to the word list.\n"
		<< "b) Guess the word.\n"
		<< "c) Given a set show all posivel combinations.\n"
		<< "d) Given a random set of leters, guess a word.\n"
		<< "e) Read a word with wildcard caracters and return all possivel sets.\n\n";
	cin >> ch;
	if (cin.eof())
		return false;
	while (cin.fail() && (ch != "a" || ch != "b" || ch != "c" || ch != "d" || ch != "e")) {
		cout << "Invalid option" << endl;
		cin.clear();
		cin.ignore(100000000, '\n');
		cin >> ch;
	}
	char cha = ch[0];
	switch (cha) {
	case 'a': op_a(wd);
		break;
	case 'b': op_b(wd);
		break;
	case 'c': op_c(wd);
		break;
	case 'd': op_d(wd);
		break;
	case 'e':
		break;
	}
	cout << endl;
	return true;
}

int main()
{
	srand(time(0));
	WordData wd;
	string str;
	wd.set_inputFile("penis.txt");
	wd.LoadWords();
	do {
	} while (menu(wd));

	return 0;
}

