/*------------------------------------------------------------------------------+
|																				|
|	Name :	prodic																|
|	16/03/2018																	|
|	Program delevolped by Gustavo Torres and Filipe Ferreira					|
|	C/C++																		|
|	FEUP,MIEIC,Prog																|
|	MIT LICENSE																	|
|																				|	
+-------------------------------------------------------------------------------+*/


#include <iostream>
#include <iomanip>
#include <string>
#include "Dicionario.h"

using namespace std;

void printTitle(){
	cout << "EXTRACTION OF WORD LIST FROM DICTIONARY\n"
		 << "======================================= " << endl;;
}


int main()
{
	printTitle();
	Dicionario dic;
	string entrada;
	//cout << "Dictionary file ? "; cin >> entrada;
	dic.set_input("29765-8.txt");
	//cout << "Word list file ? "; cin >> entrada;
	//dic.set_output(entrada);
	dic.read();
	//dic.print();
	cout << "Simple : " << dic.get_nSimple() << endl;
	cout << "Unique : " << dic.get_nUnique() << endl;
	system("pause");
	return 0;
}

