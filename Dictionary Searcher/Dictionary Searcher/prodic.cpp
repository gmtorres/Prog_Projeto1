#include <iostream>
#include <iomanip>
#include <string>
#include "Dicionario.h"

using namespace std;

void printTitle()
{
	cout << "EXTRACTION OF WORD LIST FROM DICTIONARY\n"
		<< "======================================= ";
	Dicionario dic;
	dic.set_input("Exemplo.txt");
	dic.ler();
	//system("pause");
}


int main()
{
	printTitle();
	return 0;
}

