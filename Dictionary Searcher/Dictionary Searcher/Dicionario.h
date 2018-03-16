#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Dicionario
{
public:
	
	std::string input_file_n,output_file_n;
	std::ifstream in_file;
	std::ofstream out_file;

	Dicionario();  //Incializar o objeto sem parametros
	Dicionario(std::string in_f, std::string out_f); //Inicializar o objeto com os nomes dos ficheiros de entrada e saida
	void set_input(std::string str); // Atribuir um nome ao ficheiro de entrada
	void set_output(std::string str); //Atribuir um nome ao ficheiro de saida
	void ler();
	//~Dicionario();<
};

