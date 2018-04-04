/*------------------------------------------------------------------------------+
|																				|
|	Name :	playwords															|
|	20/03/2018																	|
|	Program developed by Filipe Ferreira and Gustavo Torres  					|
|	C/C++																		|
|	FEUP,MIEIC,Prog																|
|	MIT LICENSE																	|
|										
+-------------------------------------------------------------------------------+*/
#include "WordData.h"    
#include "PWMenu.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <cstring>

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	WordData wd;
	string str;
	do {
		cout << "Words file: "; cin >> str;
		wd.set_inputFile(str);
		cout << "Loading words...";
	} while (!wd.LoadWords());
	cout << endl;
	//system("cls");
	//getch();
	do {
	} while (menu(wd));

	return 0;
}

