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

}


int main()
{
	WordData wd;
	string str;
	wd.set_inputFile("penis.txt");
	wd.LoadWords();
	cin >> str;
	wd.makeupper(str);
	cout << str;
    return 0;
}

