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

int main()
{
	WordData wd;
	wd.set_inputFile("penis.txt");
	wd.LoadWords();
	
    return 0;
}

