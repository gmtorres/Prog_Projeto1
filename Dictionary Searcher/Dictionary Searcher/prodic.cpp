#include <iostream>
#include <iomanip>
#include <string>
#include "Dicionario.h"

using namespace std;

void printTitle()
{
	cout << "EXTRACTION OF WORD LIST FROM DICTIONARY\n"
		<< "======================================= ";
	Dicionario dic("Exemplo");
	dic.imprime_nome();
	//system("pause");
}


int main()
{
	printTitle();
	return 0;
}

