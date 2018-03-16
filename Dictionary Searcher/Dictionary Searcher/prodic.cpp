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
	Dicionario dic;
	string entrada;
	cout << "Dictionary file ? "; cin >> entrada;
	dic.set_input(entrada);
	cout << "Word list file ? "; cin >> entrada;
	dic.set_output(entrada);
	dic.read();
	//system("pause");
}


int main()
{
	printTitle();
	return 0;
}

