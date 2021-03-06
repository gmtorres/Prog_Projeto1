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
	//entrada = "ficheiro.txt";
	cout << "Dictionary file ? "; cin >> entrada;
	dic.set_input(entrada);
	//entrada = "a.txt";
	cout << "Word list file ? "; cin >> entrada;
	dic.set_output(entrada);
	cout << "\nExtracting simple words from file " << dic.get_inFile() << ",\nbeginning with letter...\n";
	dic.read();
	cout << "Number of simple = " << dic.get_nSimple() << endl;
	cout << "Sorting words ..." << endl;
	dic.ordenar();
	cout << "Removing duplicate words ..." << endl;
	dic.remove();
	cout << "Number of non-duplicate words = " << dic.get_nUnique() << endl;
	cout << "Saving words into file " << dic.get_outFile() << endl;
	dic.make_out_file();
	cout << "END OF PROCESSING\n";
	//dic.print();
	
	//system("pause");
	return 0;
}

